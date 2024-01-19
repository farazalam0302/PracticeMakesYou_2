#!/bin/bash

includePath='/mnt/c/Users/faraz/boost_1_72_0'
libraryPath='/mnt/c/Users/faraz/boost_1_72_0/stage/lib'
(g++ -std=c++17 -g -I$includePath -L$libraryPath $1 -o a.out && clear) && echo "Successful compilation" && ./a.out
