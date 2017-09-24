FROM alpine:latest

RUN apk add --update make cmake g++
ADD . native
RUN cd native && cmake . -DCMAKE_BUILD_TYPE=release && make -j4 && make install
RUN export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/usr/local/lib
RUN rm -rf native
WORKDIR /