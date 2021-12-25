#!/bin/bash
mkdir -p build
emcmake cmake -S . -B build
cd build
emmake make
