# Define minimum required version for CMake
cmake_minimum_required(VERSION 3.22)

# Details of the project
project(WebGL VERSION 1.0
        DESCRIPTION "WebAssembly GLES 2 implementation"
        LANGUAGES C CXX)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Define linker flags for Emscripten
add_link_options(-s MAX_WEBGL_VERSION=2)

# The compiled source code resides here
add_subdirectory(src)
