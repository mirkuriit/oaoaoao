cmake_minimum_required(VERSION 3.10)

project(meow)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(${CMAKE_SOURCE_DIR}/doctest)

#add_subdirectory(first_class)
add_subdirectory(rational_proj)
#dd_subdirectory(test_prj)