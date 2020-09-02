cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(DSA, VERSION 1.0)

# Dependencies: Solving external package dependencies
set(EXTERNAL_DIR ${CMAKE_CURRENT_SOURCE_DIR}/externals)
include(${EXTERNAL_DIR}/gtest.cmake)

include_directories(${CMAKE_SOURCE_DIR}/src)

add_subdirectory(src)
add_subdirectory(test)