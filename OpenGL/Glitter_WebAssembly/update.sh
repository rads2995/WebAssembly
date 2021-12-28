#!/bin/bash

cd /home/omega/Projects/WebAssembly/OpenGL/build/src
cp *.js *.wasm *.html /home/omega/Projects/rads2995.github.io/
cd /home/omega/Projects/rads2995.github.io
mv OpenGL.html index.html
git add .
git commit -m "Update from C++ Webassembly"
git push
