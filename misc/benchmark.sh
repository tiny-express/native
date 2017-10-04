#!/bin/bash
cd benchmark/benchmark
cmake -DCMAKE_BUILD_TYPE=Release
make benchmark
