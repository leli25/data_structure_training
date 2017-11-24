cmake_minimum_required( VERSION 2.8 )
project(binarySearch)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
include_directories("./include")

aux_source_directory(. SRC_DIR)
add_executable(binarySearchTree ${SRC_DIR})