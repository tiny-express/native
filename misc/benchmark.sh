#!/bin/bash
cd /tmp
git clone https://github.com/google/benchmark.git
cd benchmark
cmake -DBENCHMARK_ENABLE_TESTING=OFF -DCMAKE_BUILD_TYPE=Release .
make benchmark && sudo make install
