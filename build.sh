#!/bin/sh

set -xe

clang++ -Wall -pedantic -std=c++17 -o test *.cpp
