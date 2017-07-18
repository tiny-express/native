# Install script for directory: /home/nakhoadl/workspace/foodtiny/native

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/home/nakhoadl/workspace/foodtiny/native/libnative_static.a")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/home/nakhoadl/workspace/foodtiny/native/CMakeFiles/CMakeRelink.dir/libnative.so")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/native" TYPE FILE FILES
    "/home/nakhoadl/workspace/foodtiny/native/./java/util/Deque/Deque.h"
    "/home/nakhoadl/workspace/foodtiny/native/./vendor.h"
    "/home/nakhoadl/workspace/foodtiny/native/./kernel/test.h"
    "/home/nakhoadl/workspace/foodtiny/native/./kernel/platform.h"
    "/home/nakhoadl/workspace/foodtiny/native/./kernel/json.h"
    "/home/nakhoadl/workspace/foodtiny/native/./kernel/math.h"
    "/home/nakhoadl/workspace/foodtiny/native/./kernel/type.h"
    "/home/nakhoadl/workspace/foodtiny/native/./kernel/builtin.h"
    "/home/nakhoadl/workspace/foodtiny/native/./kernel/network.h"
    "/home/nakhoadl/workspace/foodtiny/native/./kernel/datetime.h"
    "/home/nakhoadl/workspace/foodtiny/native/./kernel/common.h"
    "/home/nakhoadl/workspace/foodtiny/native/./kernel/string.h"
    "/home/nakhoadl/workspace/foodtiny/native/library.hpp"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/native" TYPE DIRECTORY FILES "/home/nakhoadl/workspace/foodtiny/native/java")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/native" TYPE FILE FILES
    "/home/nakhoadl/workspace/foodtiny/native/./java/util/Deque/Deque.h"
    "/home/nakhoadl/workspace/foodtiny/native/./vendor.h"
    "/home/nakhoadl/workspace/foodtiny/native/./kernel/test.h"
    "/home/nakhoadl/workspace/foodtiny/native/./kernel/platform.h"
    "/home/nakhoadl/workspace/foodtiny/native/./kernel/json.h"
    "/home/nakhoadl/workspace/foodtiny/native/./kernel/math.h"
    "/home/nakhoadl/workspace/foodtiny/native/./kernel/type.h"
    "/home/nakhoadl/workspace/foodtiny/native/./kernel/builtin.h"
    "/home/nakhoadl/workspace/foodtiny/native/./kernel/network.h"
    "/home/nakhoadl/workspace/foodtiny/native/./kernel/datetime.h"
    "/home/nakhoadl/workspace/foodtiny/native/./kernel/common.h"
    "/home/nakhoadl/workspace/foodtiny/native/./kernel/string.h"
    "/home/nakhoadl/workspace/foodtiny/native/library.hpp"
    )
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/home/nakhoadl/workspace/foodtiny/native/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
