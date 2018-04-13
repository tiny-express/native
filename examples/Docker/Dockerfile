FROM foodtiny/native:latest
MAINTAINER Loi Nguyen <loint@foodtiny.com>

ADD HelloWorld.cpp .
RUN g++ -c -o main.o HelloWorld.cpp
RUN g++ -o main main.o -lnative

ENTRYPOINT ./main