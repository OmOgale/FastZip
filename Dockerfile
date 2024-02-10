FROM arm64v8/alpine

RUN apk update && \
    apk add --no-cache build-base clang cmake python3 bash

RUN mkdir -p /usr/local/src/zippy
COPY . /usr/local/src/zippy

WORKDIR /usr/local/src/zippy

RUN chmod +x run.sh && ./run.sh
