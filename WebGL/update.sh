#!/bin/bash

cd /home/omega/Projects/WebAssembly/OpenGL/build/src
cp *.js *.wasm /home/omega/Projects/rads2995.github.io/
cd /home/omega/Projects/rads2995.github.io
git add .
git commit -m "Update from C++ Webassembly"
git push
