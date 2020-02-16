cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

PROJECT(linear_algebra CXX)

add_definitions(-std=c++11)

set(CXX_FLAGS "-Wall" "-pedantic")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")



add_library(matrix  src/matrix.h)
set_target_properties(matrix PROPERTIES LINKER_LANGUAGE CXX)

add_executable (example src/example.cpp)
target_link_libraries (example matrix)
