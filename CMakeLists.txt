cmake_minimum_required(VERSION 2.8)
project(native ASM C)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -w")

find_library(ZLIB REQUIRED)
find_package(Threads REQUIRED)

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
    main.c
)

add_executable(${PROJECT_NAME} ${SOURCES})
if (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    target_link_libraries(${PROJECT_NAME} ${CMAKE_THREAD_LIBS_INIT} -lz)
else()
    target_link_libraries(${PROJECT_NAME} ${CMAKE_THREAD_LIBS_INIT} -lrt -lz)
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
    main.c
)

foreach(test ${TESTS})
    list(REMOVE_ITEM SOURCES ${test})
endforeach()

add_library(builtin STATIC ${SOURCES})

target_compile_definitions(builtin PRIVATE CASSANDRA)
if (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    target_link_libraries(builtin ${CMAKE_THREAD_LIBS_INIT} -lz)
else()
    target_link_libraries(builtin ${CMAKE_THREAD_LIBS_INIT} -lrt -lz)
endif()