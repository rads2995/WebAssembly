# Add local library for source code header files
#add_library(library example.cpp)
#target_include_directories(library PUBLIC ../include)

# Add external Glad library
add_library(glad ../lib/src/glad.c)
target_include_directories(glad PUBLIC ../lib/include/glad/)

# Add source executable
add_executable(${PROJECT_NAME} main.cpp)

# Link local and external libraries to executable
target_link_libraries(${PROJECT_NAME} PRIVATE glad)
