CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
PROJECT(native)

SET(CMAKE_C_COMPILER gcc)
SET(CMAKE_C_FLAGS "${CMAKE_CXX_FLAGS} -w")

FIND_PACKAGE(Threads REQUIRED)

FILE(GLOB_RECURSE SOURCES
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

ADD_EXECUTABLE(${PROJECT_NAME} ${SOURCES})
if (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${CMAKE_THREAD_LIBS_INIT})
else()
    TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${CMAKE_THREAD_LIBS_INIT} -lrt)
endif()
