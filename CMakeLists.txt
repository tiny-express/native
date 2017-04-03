CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
PROJECT(native)

SET(CMAKE_C_COMPILER gcc)
SET(CMAKE_C_FLAGS  "${CMAKE_CXX_FLAGS} -w")

FIND_PACKAGE(Threads REQUIRED)

SET(SOURCE_FILES
    context/context.c
    context/context_test.c
    context/http_request.c
    context/http_response.c
    datetime/datetime.c
    datetime/datetime_test.c
    general/append.c
    general/append_test.c
    general/join.c
    general/join_test.c
    general/len.c
    general/len_test.c
    general/seg.c
    general/seg_test.c
    network/address.c
    network/address_test.c
    server/mongoose.c
    storage/cassandra.c
    storage/logger.c
    storage/logger.h
    storage/logger_test.c
    string/convert.c
    string/convert_test.c
    string/process.c
    string/process_test.c
    system/device.c
    system/device_test.c
    thread/thpool.c
    thread/thpool.h
    thread/thread.h
    thread/thread_test.c
    type/json/json.c
    type/json/json_test.c
    type/default.c
    type/default.h
    type/json.h
    builtin.h
    component.h
    context.h
    datetime.h
    general.h
    main.c
    mongoose.h
    network.h
    server.h
    storage.h
    string.h
    system.h
    type.h
    unistd.h
    unit_test.h)

ADD_EXECUTABLE(${PROJECT_NAME} ${SOURCE_FILES})
TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${CMAKE_THREAD_LIBS_INIT} -lrt)