# Define minimum required version for CMake
cmake_minimum_required(VERSION 3.22)

# Details of the project
project(OpenGL VERSION 1.0
        DESCRIPTION "OpenGL implementation on WebAssembly"
        LANGUAGES C CXX)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Specify data type for output
set(CMAKE_EXECUTABLE_SUFFIX ".html")

add_compile_options(-Wall -Wextra)
add_link_options(-s USE_GLFW=3)

# Add source executable and link to libraries
add_executable(OpenGL src/main.cpp)
