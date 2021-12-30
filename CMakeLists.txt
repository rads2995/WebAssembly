# Define minimum required version for CMake
cmake_minimum_required(VERSION 3.22)

# Details of the project
project(WebAssembly LANGUAGES C CXX)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Specify compiler flags
add_compile_options(-Wall -s USE_SDL=2 -s USE_SDL_IMAGE=2)

# Specify linker flags  
add_link_options(-s SDL2_IMAGE_FORMATS='["bmp"]')

# Add source executable and link to libraries
add_executable(Run src/main.cpp)
