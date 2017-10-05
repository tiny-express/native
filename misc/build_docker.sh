#!/bin/bash

if [ "$TRAVIS_PULL_REQUEST" = false ] && [ "$TRAVIS_OS_NAME" == "linux" ];
then
    rm -rf CMakeCache.txt
    if [[ "$TRAVIS_BRANCH" == "development" ]];
    then
        docker login -u $UP -p $DOWN
        docker build -t foodtiny/native:development .
        docker push foodtiny/native:development
    fi

    if [[ "$TRAVIS_BRANCH" == "master" ]];
    then
        docker login -u $UP -p $DOWN
        docker build -t foodtiny/native:latest .
        docker push foodtiny/native:latest
    fi
fi