FROM alpine:latest
MAINTAINER Loi Nguyen<loint@foodtiny.com>

ENV NATIVE 1.0.2

WORKDIR /tmp
RUN apk add --update curl make cmake g++
RUN curl -o native.tar.gz -L https://github.com/foodtiny/native/archive/v$NATIVE.tar.gz
RUN tar -xvf native.tar.gz && rm -rf native.tar.gz && mv native-$NATIVE native
RUN cd native && cmake . && make install
RUN export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/usr/local/lib
RUN apk del curl
WORKDIR /
RUN rm -rf /tmp