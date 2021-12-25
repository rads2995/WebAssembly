# Add local library for source code header files
#add_library(library example.cpp)
#target_include_directories(library PUBLIC ../include)

# Add source executable and link all libraries
add_executable(${PROJECT_NAME} main.cpp)
#target_link_libraries(${PROJECT_NAME} PRIVATE)
