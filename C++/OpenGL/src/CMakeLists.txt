# Add library for source code header files
#add_library(library example.cpp)
#target_include_directories(library PUBLIC ../include)

# Add external glfw3 library
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
add_library(glfw glfw3.cpp)
target_include_directories(glfw PUBLIC ../lib/GLFW)

# Add external Glad library
add_library(glad ../lib/glad/src/glad.c)
target_include_directories(glad PUBLIC ../lib/glad/include)

# Add source executable and link to libraries
add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE library glfw glad)
add_link_options(lGL)
