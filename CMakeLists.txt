cmake_minimum_required(VERSION 2.8)
project(native)

enable_language(C)

if (${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    enable_language(ASM)
endif()

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -w")

# GCC flags for Darwin - Unix
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")
if (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    set(OPENSSL_ROOT_DIR "/usr/local/opt/openssl")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -w -undefined dynamic_lookup")
elseif(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    set(OPENSSL_ROOT_DIR "/usr/include/openssl")
else()
    set(OPENSSL_ROOT_DIR "C:/Program Files (x86)/GnuWin32/include")
endif()

# Discover dependencies
# 1. OpenSSL
# 3. LibUV for Darwin
set(OPENSSL_ROOT_DIR "${OPENSSL_ROOT_DIR}")
find_package(ZLIB REQUIRED)
find_package(OpenSSL REQUIRED)
find_package(Threads REQUIRED)

if (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    find_package(LibUV)
endif()

if (OPENSSL_FOUND)
    include_directories("${OPENSSL_INCLUDE_DIR}")
endif()

set(DYLD_LIBRARY_PATH ${DYLD_LIBRARY_PATH})

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
    system/*
    thread/*
    type/*
    vendor/*
    main.c
)

add_executable(${PROJECT_NAME} ${SOURCES})
if (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    target_link_libraries(${PROJECT_NAME} ${CMAKE_THREAD_LIBS_INIT} -lz -lssl -lcrypto)
else()
    target_link_libraries(${PROJECT_NAME} ${CMAKE_THREAD_LIBS_INIT} -lrt -lz -lssl -lcrypto)
endif()

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
    system/*_test.c
    thread/*_test.c
    type/*_test.c
    vendor/*_test.c
    main.c
)

foreach(test ${TESTS})
    list(REMOVE_ITEM SOURCES ${test})
endforeach()

add_library(builtin STATIC ${SOURCES})

target_compile_definitions(builtin PRIVATE CASSANDRA)
if (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    target_link_libraries(builtin ${CMAKE_THREAD_LIBS_INIT} -lz -lssl -lcrypto -lcassandra)
else()
    target_link_libraries(builtin ${CMAKE_THREAD_LIBS_INIT} -lrt -lz -lssl -lcrypto -lcassandra)
endif()