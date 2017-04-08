CMAKE_MINIMUM_REQUIRED(VERSION 3.2)
PROJECT(native)

SET(CMAKE_C_COMPILER gcc)
SET(CMAKE_C_FLAGS "${CMAKE_CXX_FLAGS} -w")

set(ZLIB_PUBLIC_HDRS
        ${CMAKE_CURRENT_BINARY_DIR}/zconf.h
        zlib.h
)

FIND_PACKAGE(Threads REQUIRED)

FILE(GLOB_RECURSE SOURCES
    context/*.c
    compress/*.c
    crypto/*.c
    datetime/*.c
    general/*.c
    network/*.c
    server/*.c
    storage/*.c
    string/*.c
    system/*.c
    thread/*.c
    type/*.c
    main.c
)

ADD_EXECUTABLE(${PROJECT_NAME} ${SOURCES})
if (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${CMAKE_THREAD_LIBS_INIT} -lz)
else()
    TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${CMAKE_THREAD_LIBS_INIT} -lrt -lz)
endif()

FILE(GLOB_RECURSE TESTS
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

ADD_LIBRARY(builtin STATIC ${SOURCES})

TARGET_COMPILE_DEFINITIONS(builtin PRIVATE CASSANDRA)
if (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    TARGET_LINK_LIBRARIES(builtin ${CMAKE_THREAD_LIBS_INIT})
else()
    TARGET_LINK_LIBRARIES(builtin ${CMAKE_THREAD_LIBS_INIT} -lrt)
endif()