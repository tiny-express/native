#!/bin/bash

SOURCE_PATH=$1
if [ -z "$1" ]
  then SOURCE_PATH=java
fi
python cpplint.py --extensions=hpp,cpp $(find $SOURCE_PATH -name "*.hpp" -or -name "*.cpp")
