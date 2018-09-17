FROM alpine:3.8
RUN apk add --no-cache gcc g++ musl musl-dev make cmake
RUN gcc -v
ADD . native
RUN cd native && cmake . -DCMAKE_BUILD_TYPE=Release && make native_static -j8 && make native -j8 && make install
RUN export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/usr/local/lib
RUN rm -rf native
WORKDIR /
