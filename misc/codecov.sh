if [[ "$TRAVIS_OS_NAME" == "linux" ]];
    cd ${TRAVIS_BUILD_DIR}
    lcov --directory . --capture --output-file coverage.info
    lcov --remove coverage.info '/usr/*' --output-file coverage.info
    lcov --list coverage.info
    bash <(curl -s https://codecov.io/bash) || echo "Codecov did not collect coverage reports"
fi