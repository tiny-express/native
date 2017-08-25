#!/bin/bash

if [[ "$TRAVIS_OS_NAME" == "linux" ]];
then
    lcov --directory . --capture --output-file coverage.info
    lcov --remove coverage.info '/usr/*' --output-file coverage.info
    lcov --list coverage.info
    bash <(curl -s https://codecov.io/bash) || echo "Codecov did not collect coverage reports"
fi