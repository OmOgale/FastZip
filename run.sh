#!/bin/bash

cd ./build
cmake ..
make 
cd ..
mv build/Zippy .

