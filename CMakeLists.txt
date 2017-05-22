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
project(native C CXX)

# Only enable GNU Assembly for Linux amd64
# Please careful when you would like to optimize any function in ASM
# ASM implementation must be GNU Assembly for Linux 64bit
# C implementation must be implemented first for __APPLE__
# Keep human readable for __APPLE__ - no need to optimize for testing
if (${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    enable_language(ASM)
endif()

# Check compiler version
include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)
if(COMPILER_SUPPORTS_CXX11)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
elseif(COMPILER_SUPPORTS_CXX0X)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
else()
    message(STATUS "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
endif()

set(CMAKE_C_COMPILER ${CC})
set(CMAKE_CXX_COMPILER ${CXX})
set(CMAKE_C_FLAGS  "${CMAKE_C_FLAGS} -w")
set(CMAKE_CXX_FLAGS         "-w")
set(CMAKE_CXX_FLAGS_DEBUG   "-O0 -g3")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/mk" ${CMAKE_MODULE_PATH})

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
    common/*
    context/*
    compress/*
    crypto/*
    datetime/*
    java/*
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
        library.hpp
)

# Include all unit test cases
file(GLOB_RECURSE TESTS
    common/*_test.c
    context/*_test.c
    compress/*_test.c
    crypto/*_test.c
    datetime/*_test.c
    java/**/*Test.cpp
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
install (TARGETS ${PROJECT_NAME}_static DESTINATION lib)
install (TARGETS ${PROJECT_NAME} DESTINATION lib)
install (FILES ${HEADERS} DESTINATION include/native)
install (DIRECTORY java DESTINATION include/native)
install (FILES ${HEADERS} DESTINATION include/native)

# Link library for OSX and other platform
# Darwin platform no need to link realtime library (-lrt)
if (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    target_link_libraries(${PROJECT_NAME}           ${CMAKE_THREAD_LIBS_INIT} ${ZLIB_LIBRARIES} ${OPENSSL_LIBRARIES} -lcrypto)
    target_link_libraries(${PROJECT_NAME}_static    ${CMAKE_THREAD_LIBS_INIT} ${ZLIB_LIBRARIES} ${OPENSSL_LIBRARIES} -lcrypto)
    target_link_libraries(${PROJECT_NAME}_test      ${CMAKE_THREAD_LIBS_INIT} ${ZLIB_LIBRARIES} ${OPENSSL_LIBRARIES} -lcrypto)
else()
    target_link_libraries(${PROJECT_NAME}           ${CMAKE_THREAD_LIBS_INIT} ${ZLIB_LIBRARIES} ${OPENSSL_LIBRARIES} -lcrypto -lrt)
    target_link_libraries(${PROJECT_NAME}_static    ${CMAKE_THREAD_LIBS_INIT} ${ZLIB_LIBRARIES} ${OPENSSL_LIBRARIES} -lcrypto -lrt)
    target_link_libraries(${PROJECT_NAME}_test      ${CMAKE_THREAD_LIBS_INIT} ${ZLIB_LIBRARIES} ${OPENSSL_LIBRARIES} -lcrypto -lrt)
endif()
