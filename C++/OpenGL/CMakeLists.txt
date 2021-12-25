# Define minimum required version for CMake
cmake_minimum_required(VERSION 3.22)

# Details of the project
project(OpenGL VERSION 0.1
        DESCRIPTION "OpenGL with WebAssembly implementation"
        LANGUAGES C CXX)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# The compiled source code resides here
add_subdirectory(src)
