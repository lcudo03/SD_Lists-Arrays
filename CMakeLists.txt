cmake_minimum_required(VERSION 3.10)
SET(CMAKE_CXX_FLAGS "-O0")
SET(CMAKE_C_FLAGS "-O0")

project(Arrays-Lists)

add_library(DataStructures_lib INTERFACE)
target_include_directories(DataStructures_lib INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include/)

add_executable(efficiency_tests ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)
target_link_libraries(efficiency_tests DataStructures_lib)