cmake_minimum_required(VERSION 3.17)

# set the project name and version
project(DSA, VERSION 1.0)

##### specify the C++ standard
set(CMAKE_CXX_STANDARD 17)

# Turn on sanitizer for debugging
#include(sanitizer.cmake)

# Enable cMake's CTest
include(CTest)

# Dependencies: Solving external package dependencies
set(EXTERNAL_DIR ${CMAKE_SOURCE_DIR}/externals)
include(${EXTERNAL_DIR}/gtest.cmake)

include_directories(${CMAKE_SOURCE_DIR}/src)
include_directories(${CMAKE_SOURCE_DIR}/test)

add_subdirectory(src)
add_subdirectory(test)
#add_subdirectory(experiment)