# Define minimum required version for CMake
cmake_minimum_required(VERSION 3.22)

# Details of the project
project(OpenGL VERSION 1.0
        DESCRIPTION "WebAssembly GLES 2 implementation"
        LANGUAGES C CXX)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Define linker flags for Emscripten
#add_link_options(-s FULL_ES3=1 -s USE_GLFW=3)
#add_link_options(-s MAX_WEBGL_VERSION=2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -std=c++20")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -s FULL_ES3=1 -s USE_WEBGL2=1 -s USE_GLFW=3 -s WASM=1 -s ALLOW_MEMORY_GROWTH=1")

# Define executable suffix
set(CMAKE_EXECUTABLE_SUFFIX ".html")

# The compiled source code resides here
add_subdirectory(src)
