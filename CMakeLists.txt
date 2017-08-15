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
project(native C CXX)

# Only enable GNU Assembly for Linux amd64
# Please careful when you would like to optimize any function in ASM
# ASM implementation must be GNU Assembly for Linux amd x64
# C implementation must be implemented first for __APPLE__
# Keep human readable for __APPLE__ - no need to optimize for testing
if (${CMAKE_SYSTEM_NAME} MATCHES "Linux")
#    enable_language(ASM)
endif ()

# Enable runtime search path support for dynamic libraries on OSX
if (APPLE)
    set(CMAKE_MACOSX_RPATH 1)
endif ()

# GNU filesystem layout conventions
include(GNUInstallDirs)

# Force Linux and Darwin use GCC
set(CMAKE_C_COMPILER "gcc")
set(CMAKE_CXX_COMPILER "g++")

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

# Include all C/C++ and Unix Assembly files
file(GLOB_RECURSE SOURCES_C
        kernel/common/*
        kernel/datetime/*
        kernel/math/*
        kernel/string/*
        )

# Include all C unit test cases
file(GLOB_RECURSE TESTS_C
        kernel/common/*_test.c
        kernel/datetime/*_test.c
        kernel/math/*_test.c
        kernel/string/*_test.c
        )

# Remove all test files within c files
foreach (test_c_file ${TESTS_C})
    list(REMOVE_ITEM SOURCES_C ${test_c_file})
endforeach ()

# Only C++ unit test files
file(GLOB_RECURSE SOURCES_CPP
        javax/**/*.cpp
        java/**/*.cpp
        )

# Only C++ unit test files
file(GLOB_RECURSE TESTS_CPP
        javax/**/*Test.cpp
        java/**/*Test.cpp
        )

# Remove all test files within cpp files
foreach (test_cpp_file ${TESTS_CPP})
    list(REMOVE_ITEM SOURCES_CPP ${test_cpp_file})
endforeach ()

# Create test binary for testing
add_executable(${PROJECT_NAME}_test_c ${TESTS_C} ${SOURCES_C} misc/unit-test.c)
add_executable(${PROJECT_NAME}_test ${TESTS_C} ${SOURCES_C} ${TESTS_CPP} ${SOURCES_CPP} misc/unit-test.c)

# Create native library for static linking
add_library(${PROJECT_NAME} SHARED ${SOURCES_C} ${SOURCES_CPP})

# Add make test
add_custom_target(
        unit-test
        COMMAND ./${PROJECT_NAME}_test
)

# Check memory leak
add_custom_target(
        leak
        COMMAND valgrind --track-origins=yes --error-exitcode=2 --leak-check=full ./native_test
)

# Check memory leak
add_custom_target(
        leak-debug
        COMMAND valgrind --gen-suppressions=yes --track-origins=yes --error-exitcode=2 --show-leak-kinds=all --leak-check=full ./native_test
)

# Check memory leak
add_custom_target(
        leak-c
        COMMAND valgrind --track-origins=yes --error-exitcode=2 --leak-check=full ./native_test_c
)

# Check memory leak
add_custom_target(
        leak-c-debug
        COMMAND valgrind --gen-suppressions=yes --track-origins=yes --error-exitcode=2 --show-leak-kinds=all --leak-check=full ./native_test_c
)

# Enable testing
include(CTest)
enable_testing()

# Add make installation - install to Unix system
install(TARGETS ${PROJECT_NAME} DESTINATION lib)
install(FILES library.hpp DESTINATION include/native)
install(DIRECTORY java DESTINATION include/native FILES_MATCHING PATTERN "*.hpp")
install(DIRECTORY javax DESTINATION include/native FILES_MATCHING PATTERN "*.hpp")
install(DIRECTORY kernel DESTINATION include/native FILES_MATCHING PATTERN "*.h")

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
    target_link_libraries(${PROJECT_NAME}_test_c ${CMAKE_THREAD_LIBS_INIT} -lm)
elseif (${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    target_link_libraries(${PROJECT_NAME} ${CMAKE_THREAD_LIBS_INIT} -lm -lrt)
    target_link_libraries(${PROJECT_NAME}_test ${CMAKE_THREAD_LIBS_INIT} -lm -lrt)
    target_link_libraries(${PROJECT_NAME}_test_c ${CMAKE_THREAD_LIBS_INIT} -lm -lrt)
else ()
    target_link_libraries(${PROJECT_NAME} ${CMAKE_THREAD_LIBS_INIT} -lm)
    target_link_libraries(${PROJECT_NAME}_test ${CMAKE_THREAD_LIBS_INIT} -lm)
    target_link_libraries(${PROJECT_NAME}_test_c ${CMAKE_THREAD_LIBS_INIT} -lm)
endif ()

