#
# Copyright 2017 Food Tiny Project. All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are met:
#
# Redistributions of source code must retain the above copyright
# notice, this list of conditions and the following disclaimer.
# Redistributions in binary form must reproduce the above
# copyright notice, this list of conditions and the following disclaimer
# in the documentation and/or other materials provided with the
# distribution.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
# "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
# LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
# A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
# OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
# SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
# LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
# DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
# THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
# (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
# OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#

cmake_minimum_required(VERSION 2.8.8)
project(native CXX)

# GNU filesystem layout conventions
include(GNUInstallDirs)

# Force GCC for Linux
if (${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    set(CMAKE_CXX_COMPILER "g++")
endif()

# Enable runtime search path support for dynamic libraries on OSX
if (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    set(CMAKE_MACOSX_RPATH 1)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -w ")
endif ()

# Force Linux and Darwin use GCC
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

# Check C++ compiler version
include(CheckCXXCompilerFlag)

check_cxx_compiler_flag("-std=gnu++11" COMPILER_SUPPORTS_CXX11)
check_cxx_compiler_flag("-std=gnu++0x" COMPILER_SUPPORTS_CXX0X)

# Set GCC ignore warning multi-characters constants
set(GCC_COVERAGE_COMPILE_FLAGS "-Wno-multichar -Woverflow")
add_definitions(${GCC_COVERAGE_COMPILE_FLAGS})

# Check CXX version
if (COMPILER_SUPPORTS_CXX11)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11 -Wfatal-errors")
elseif (COMPILER_SUPPORTS_CXX0X)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++0x -Wfatal-errors")
else ()
    message(STATUS "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
endif ()
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wfatal-errors")

# GNU Source compatible
add_definitions(-D_GNU_SOURCE)

if (${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    # CMake Modules
    set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/misc" ${CMAKE_MODULE_PATH})
    set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -g -O0 -fprofile-arcs -ftest-coverage")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g -O0 -fprofile-arcs -ftest-coverage")

    # Enable coverage by cmake modules
    if (CMAKE_COMPILER_IS_GNUCXX AND CMAKE_BUILD_TYPE EQUAL "DEBUG")
        include(CodeCoverage)
        setup_target_for_coverage(${PROJECT_NAME}_coverage tests coverage)
    endif ()
endif ()

# Detect platform and include path for OpenSSL
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")

# Dynamic linked library for OSX
set(DYLD_LIBRARY_PATH ${DYLD_LIBRARY_PATH})

# Release mode
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3 -march=native")

# Only C++ unit test files
file(GLOB_RECURSE SOURCES_CPP
        kernel/**/*.cpp
        java/Java.cpp
        java/**/*.cpp
        java/**/**/*.cpp
        javax/**/*.cpp
        )

# Only C++ unit test files
file(GLOB_RECURSE TESTS_CPP
        kernel/**/*Test.cpp
        java/**/*Test.cpp
        java/**/**/*Test.cpp
        javax/**/*Test.cpp
        )

# Only C++ unit benchmark files
file(GLOB_RECURSE BENCHMARK_CPP
        kernel/**/*Benchmark.cpp
        java/**/*Benchmark.cpp
        java/**/**/*Benchmark.cpp
        javax/**/*Benchmark.cpp
        )

# Remove all test files within cpp files
foreach (test_cpp_file ${TESTS_CPP})
    list(REMOVE_ITEM SOURCES_CPP ${test_cpp_file})
endforeach ()

# Remove all benchmark files within cpp files
foreach (benchmark_cpp_file ${BENCHMARK_CPP})
    list(REMOVE_ITEM SOURCES_CPP ${benchmark_cpp_file})
endforeach ()

# Create test binary for testing
add_executable(${PROJECT_NAME}_test ${TESTS_CPP} ${SOURCES_CPP} misc/UnitTest.cpp)

# Create benchmark binary
add_executable(${PROJECT_NAME}_benchmark ${BENCHMARK_CPP} ${SOURCES_CPP} benchmark/benchmark.cpp)

# Link google benchmark library
target_link_libraries(${PROJECT_NAME}_benchmark libbenchmark.a)

# Create native library for static linking
add_library(${PROJECT_NAME} SHARED ${SOURCES_CPP})
add_library(${PROJECT_NAME}_static STATIC ${SOURCES_CPP})

# Add make test
add_custom_target(
        unit-test
        COMMAND ./${PROJECT_NAME}_test
)

# Check memory leak
add_custom_target(
        leak
        COMMAND make native_test
        COMMAND valgrind --track-origins=yes --error-exitcode=2 --leak-check=full ./native_test
)

# Enable testing
include(CTest)
enable_testing()

# Add make installation - install to Unix system
set(CMAKE_SKIP_INSTALL_ALL_DEPENDENCY true)
install(TARGETS ${PROJECT_NAME} DESTINATION lib OPTIONAL)
install(TARGETS ${PROJECT_NAME}_static DESTINATION lib OPTIONAL)
install(FILES library.hpp DESTINATION include/native)
install(DIRECTORY java DESTINATION include/native FILES_MATCHING PATTERN "*.hpp")
install(DIRECTORY javax DESTINATION include/native FILES_MATCHING PATTERN "*.hpp")
install(DIRECTORY kernel DESTINATION include/native FILES_MATCHING PATTERN "*.hpp")

# Add uninstall
add_custom_target(
        uninstall
        COMMAND rm -rf /usr/local/include/native
        COMMAND rm -rf /usr/local/lib/libnative*
)

# Link library for OSX and other platform
# Darwin platform no need to link realtime library (-lrt)
if (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    target_link_libraries(${PROJECT_NAME} ${CMAKE_THREAD_LIBS_INIT} -lm)
    target_link_libraries(${PROJECT_NAME}_test ${CMAKE_THREAD_LIBS_INIT} -lm)
elseif (${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    target_link_libraries(${PROJECT_NAME} ${CMAKE_THREAD_LIBS_INIT} -lm -lrt)
    target_link_libraries(${PROJECT_NAME}_test ${CMAKE_THREAD_LIBS_INIT} -lm -lrt)
else ()
    target_link_libraries(${PROJECT_NAME} ${CMAKE_THREAD_LIBS_INIT} -lm)
    target_link_libraries(${PROJECT_NAME}_test ${CMAKE_THREAD_LIBS_INIT} -lm)
endif ()
