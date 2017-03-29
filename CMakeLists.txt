cmake_minimum_required(VERSION 3.6)
project(native)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    src/context/context.c
    src/context/context_test.c
    src/context/http_request.c
    src/context/http_response.c
    src/datetime/datetime.c
    src/datetime/datetime_test.c
    src/general/append.c
    src/general/append_test.c
    src/general/join.c
    src/general/join_test.c
    src/general/len.c
    src/general/len_test.c
    src/general/seg.c
    src/general/seg_test.c
    src/network/address.c
    src/network/address_test.c
    src/server/mongoose.c
    src/storage/cassandra.c
    src/storage/logger.c
    src/storage/logger.h
    src/storage/logger_test.c
    src/string/convert.c
    src/string/convert_test.c
    src/string/process.c
    src/string/process_test.c
    src/system/device.c
    src/system/device_test.c
    src/thread/thpool.c
    src/thread/thpool.h
    src/thread/thread.c
    src/thread/thread.h
    src/thread/thread_test.c
    src/type/json/helper.c
    src/type/json/helper_test.c
    src/type/json/json.c
    src/type/json/json_test.c
    src/type/default.c
    src/type/default.h
    src/type/json.h
    src/builtin.h
    src/component.h
    src/context.h
    src/datetime.h
    src/general.h
    src/mongoose.h
    src/network.h
    src/server.h
    src/storage.h
    src/string.h
    src/system.h
    src/type.h
    src/unistd.h
    src/unit_test.h)

add_executable(native ${SOURCE_FILES})