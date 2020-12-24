cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(DSA, VERSION 1.0)

##### specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_CXX_STANDARD_REQUIRED True)

# add_library(dsa_compiler_flags INTERFACE)
# target_compile_features(dsa_compiler_flags INTERFACE cxx_std_11)

# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

# add_definitions(-std=c++17)

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