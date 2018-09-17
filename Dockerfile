FROM gcc:6
RUN apt-get update && apt-get install -y --no-install-recommends cmake
RUN cmake --version
ADD . native
RUN cd native && cmake . -DCMAKE_BUILD_TYPE=Release && make native_static -j8 && make native -j8 && make install
RUN export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/usr/local/lib
RUN rm -rf native
WORKDIR /
