#!/bin/bash

rm -rf CMakeCache.txt
if [[ "$TRAVIS_BRANCH" == "development" ]];
then
    docker login -u $UP -p $DOWN
    docker build -t foodtiny/native:development -f DockerfileDevelopment .
    docker push foodtiny/native:development
fi
