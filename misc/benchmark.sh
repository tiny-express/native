#!/bin/bash
cd /tmp
git clone https://github.com/google/benchmark.git
cd benchmark
cmake -DCMAKE_BUILD_TYPE=Release -DBENCHMARK_ENABLE_LTO=true
sudo make install