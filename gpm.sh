#!/bin/bash

g++ -pthread  $1 -std=c++17 -g -o a.out && ./a.out
