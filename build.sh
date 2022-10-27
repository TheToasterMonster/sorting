#!/bin/sh

set -xe

clang++ -Wall -pedantic -std=c++17 -O2 -o test *.cpp
