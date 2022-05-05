#!/bin/bash 
###rm "./build/hello"
cmake -S . -B build
cmake --build build
./build/hello
