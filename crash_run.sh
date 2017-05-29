#!/bin/bash
echo "Crash run ..."
for i in {1..50}
do
    echo "run: $i"
    make native_test && ./native_test
done
echo "Done !"