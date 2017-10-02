#!/bin/bash

cd ../benchmark
git clone https://github.com/google/benchmark
cd benchmark
cmake -DCMAKE_BUILD_TYPE=Release
make benchmark