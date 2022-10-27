#!/bin/sh

set -xe

clang++ -Wall -pedantic -std=c++17 -O0 -o test *.cpp
