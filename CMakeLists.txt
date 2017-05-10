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

cmake_minimum_required(VERSION 2.8)
project(native)

# Native is written in pure C
enable_language(C)

# Only enable GNU Assembly for Linux amd64
# Please careful when you would like to optimize any function in ASM
# ASM implementation must be GNU Assembly for Linux 64bit
# C implementation must be implemented first for __APPLE__
# Keep human readable for __APPLE__ - no need to optimize for testing
if (${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    enable_language(ASM)
endif()

set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/mk" ${CMAKE_MODULE_PATH})
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -w")

# Detect platform and include path for OpenSSL
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")
if (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    set(OPENSSL_ROOT_DIR "/usr/local/opt/openssl")
elseif(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    set(OPENSSL_ROOT_DIR "/usr/include/openssl")
else()
    set(OPENSSL_ROOT_DIR "C:/Program Files (x86)/GnuWin32/include")
endif()
set(OPENSSL_ROOT_DIR "${OPENSSL_ROOT_DIR}")

# Detect installed components
find_package(ZLIB REQUIRED)
find_package(OpenSSL REQUIRED)
find_package(Threads REQUIRED)

if (OPENSSL_FOUND)
    include_directories("${OPENSSL_INCLUDE_DIR}")
endif()

# Dynamic linked library for OSX
set(DYLD_LIBRARY_PATH ${DYLD_LIBRARY_PATH})

# Include all C and Unix Assembly files
file(GLOB_RECURSE SOURCES
    context/*
    compress/*
    crypto/*
    datetime/*
    general/*
    network/*
    server/*
    storage/*
    string/*
    thread/*
    type/*
    vendor/*
    validator/*
)

file(GLOB_RECURSE HEADERS
    ./*.h
)

# Include all unit test cases
file(GLOB_RECURSE TESTS
    context/*_test.c
    compress/*_test.c
    crypto/*_test.c
    datetime/*_test.c
    general/*_test.c
    network/*_test.c
    server/*_test.c
    storage/*_test.c
    string/*_test.c
    thread/*_test.c
    type/*_test.c
    vendor/*_test.c
    validator/*_test.c
)

# Remove all test files within c files
foreach(test ${TESTS})
    list(REMOVE_ITEM SOURCES ${test})
endforeach()

# Create test binary for testing
add_executable(${PROJECT_NAME}_test ${TESTS} ${SOURCES} main.c)

# Enable native library build with Cassandra Driver
# Create native library for static linking
add_library(${PROJECT_NAME}_static ${SOURCES})
add_library(${PROJECT_NAME} SHARED ${SOURCES})

# Add make test
enable_testing()
add_test(${PROJECT_NAME}_test ./${PROJECT_NAME}_test)

# Add make install - installation to unix system
install (TARGETS ${PROJECT_NAME}_static DESTINATION bin)
install (TARGETS ${PROJECT_NAME} DESTINATION bin)
install (FILES ${HEADERS} DESTINATION include/native)

# Link library for OSX and other platform
# Darwin platform no need to link realtime library (-lrt)
if (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    target_link_libraries(${PROJECT_NAME}      ${CMAKE_THREAD_LIBS_INIT} ${ZLIB_LIBRARIES} ${OPENSSL_LIBRARIES} -lcrypto)
    target_link_libraries(${PROJECT_NAME}_test ${CMAKE_THREAD_LIBS_INIT} ${ZLIB_LIBRARIES} ${OPENSSL_LIBRARIES} -lcrypto)
else()
    target_link_libraries(${PROJECT_NAME}      ${CMAKE_THREAD_LIBS_INIT} ${ZLIB_LIBRARIES} ${OPENSSL_LIBRARIES} -lcrypto -lrt)
    target_link_libraries(${PROJECT_NAME}_test ${CMAKE_THREAD_LIBS_INIT} ${ZLIB_LIBRARIES} ${OPENSSL_LIBRARIES} -lcrypto -lrt)
endif()
