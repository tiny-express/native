#
# Copyright (c) 2016 Food Tiny Project. All rights reserved.
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
    enable_language(ASM)
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

if (COMPILER_SUPPORTS_CXX11)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")
elseif (COMPILER_SUPPORTS_CXX0X)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++0x")
else ()
    message(STATUS "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
endif ()

add_definitions(-D_GNU_SOURCE)

# CMake Modules
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/mk" ${CMAKE_MODULE_PATH})

# Detect platform and include path for OpenSSL
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")

#if (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
#    set(OPENSSL_ROOT_DIR "/usr/local/opt/openssl")
#elseif (${CMAKE_SYSTEM_NAME} MATCHES "Linux")
#    set(OPENSSL_ROOT_DIR "/usr/include/openssl")
#else ()
#    set(OPENSSL_ROOT_DIR "C:/Program Files (x86)/GnuWin32/include")
#endif ()

# Set root directory for OpenSSL
#set(OPENSSL_ROOT_DIR "${OPENSSL_ROOT_DIR}")

# Detect installed components
#find_package(ZLIB REQUIRED)
#find_package(OpenSSL REQUIRED)
#find_package(Threads REQUIRED)

#if (OPENSSL_FOUND)
#    include_directories("${OPENSSL_INCLUDE_DIR}")
#endif ()

# Dynamic linked library for OSX
set(DYLD_LIBRARY_PATH ${DYLD_LIBRARY_PATH})

# Only header files
file(GLOB_RECURSE HEADERS
        ./*.h
        library.hpp)

# Include all C/C++ and Unix Assembly files
file(GLOB_RECURSE SOURCES_C
        common/*
       #crypto/*
        datetime/*
        math/*
       #network/*
        server/*
       #storage/*
        string/*
        system/*
       #thread/*
        type/*
       #vendor/*
       #validator/*
        )

# Include all C unit test cases
file(GLOB_RECURSE TESTS_C
        common/*_test.c
       #crypto/*_test.c
        datetime/*_test.c
        math/*_test.c
       #network/*_test.c
        server/*_ .test.c
       #storage/*_test.c
        string/*_test.c
        system/*_test.c
       #thread/*_test.c
        type/*_test.c
       #vendor/*_test.c
       #validator/*_test.c
        )

# Remove all test files within c files
foreach (test_c_file ${TESTS_C})
    list(REMOVE_ITEM SOURCES_C ${test_c_file})
endforeach ()

# Only C++ unit test files
file(GLOB_RECURSE SOURCES_CPP
        java/**/*.cpp
        )

# Only C++ unit test files
file(GLOB_RECURSE TESTS_CPP
        java/**/*Test.cpp
        )

# Remove all test files within cpp files
foreach (test_cpp_file ${TESTS_CPP})
    list(REMOVE_ITEM SOURCES_CPP ${test_cpp_file})
endforeach ()

# Create test binary for testing
add_executable(${PROJECT_NAME}_test_c ${TESTS_C} ${SOURCES_C}  misc/unit-test.c)
add_executable(${PROJECT_NAME}_test ${TESTS_C} ${SOURCES_C} ${TESTS_CPP} ${SOURCES_CPP} misc/unit-test.c)

# Create native library for static linking
add_library(${PROJECT_NAME}_static ${SOURCES_C} ${SOURCES_CPP})
add_library(${PROJECT_NAME} SHARED ${SOURCES_C} ${SOURCES_CPP})

# Add make test
add_custom_target(
        unit-test
        COMMAND ./${PROJECT_NAME}_test
)

# Run mock server
add_custom_target(
        server
        COMMAND python ./misc/server.py
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
        COMMAND valgrind --track-origins=yes --error-exitcode=2  --leak-check=full ./native_test_c
)

# Check memory leak
add_custom_target(
        leak-c-debug
        COMMAND valgrind --gen-suppressions=yes --track-origins=yes --error-exitcode=2 --show-leak-kinds=all --leak-check=full ./native_test_c
)

# Add make installation - install to Unix system
install(TARGETS ${PROJECT_NAME}_static DESTINATION lib)
install(TARGETS ${PROJECT_NAME} DESTINATION lib)
install(FILES ${HEADERS} DESTINATION include/native)
install(DIRECTORY java DESTINATION include/native)
install(FILES ${HEADERS} DESTINATION include/native)

# Add uninstall
add_custom_target(
        uninstall
        COMMAND rm -rf /usr/local/include/native
        COMMAND rm -rf /usr/local/lib/libnative*
)

# Link library for OSX and other platform
# Darwin platform no need to link realtime library (-lrt)
if (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    target_link_libraries(${PROJECT_NAME} ${CMAKE_THREAD_LIBS_INIT} ${ZLIB_LIBRARIES} ${OPENSSL_LIBRARIES} -lcrypto -lm)
    target_link_libraries(${PROJECT_NAME}_static ${CMAKE_THREAD_LIBS_INIT} ${ZLIB_LIBRARIES} ${OPENSSL_LIBRARIES} -lcrypto -lm)
    target_link_libraries(${PROJECT_NAME}_test ${CMAKE_THREAD_LIBS_INIT} ${ZLIB_LIBRARIES} ${OPENSSL_LIBRARIES} -lcrypto -lm)
    target_link_libraries(${PROJECT_NAME}_test_c ${CMAKE_THREAD_LIBS_INIT} ${ZLIB_LIBRARIES} ${OPENSSL_LIBRARIES} -lcrypto -lm)
elseif (${CMAKE_SYSTEM_NAME} MATCHES "Unix")
    target_link_libraries(${PROJECT_NAME} ${CMAKE_THREAD_LIBS_INIT} ${ZLIB_LIBRARIES} ${OPENSSL_LIBRARIES} -lcrypto -lm -lrt)
    target_link_libraries(${PROJECT_NAME}_static ${CMAKE_THREAD_LIBS_INIT} ${ZLIB_LIBRARIES} ${OPENSSL_LIBRARIES} -lcrypto -lm -lrt)
    target_link_libraries(${PROJECT_NAME}_test ${CMAKE_THREAD_LIBS_INIT} ${ZLIB_LIBRARIES} ${OPENSSL_LIBRARIES} -lcrypto -lm -lrt)
    target_link_libraries(${PROJECT_NAME}_test_c ${CMAKE_THREAD_LIBS_INIT} ${ZLIB_LIBRARIES} ${OPENSSL_LIBRARIES} -lcrypto -lm -lrt)
else()
    target_link_libraries(${PROJECT_NAME} ${CMAKE_THREAD_LIBS_INIT} -lm)
    target_link_libraries(${PROJECT_NAME}_static ${CMAKE_THREAD_LIBS_INIT}-lm)
    target_link_libraries(${PROJECT_NAME}_test ${CMAKE_THREAD_LIBS_INIT} -lm)
    target_link_libraries(${PROJECT_NAME}_test_c ${CMAKE_THREAD_LIBS_INIT} -lm)
endif()