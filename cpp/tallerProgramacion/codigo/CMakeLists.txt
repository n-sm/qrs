cmake_minimum_required(VERSION 2.8)
project(taller)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -ggdb3 -Wall")

include_directories(src)

add_subdirectory(test)
add_subdirectory(src)