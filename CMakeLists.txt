cmake_minimum_required(VERSION 3.10)
project(Arrays-Lists)

add_library(DataStructures_lib INTERFACE)
target_include_directories(DataStructures_lib INTERFACE include/)

add_executable(efficiency_tests src/main.cpp)
target_link_libraries(efficiency_tests DataStructures_lib)