cmake_minimum_required(VERSION 3.15)

# set the project name and version
project(DSA-cpp VERSION 1.0)

##### specify the C/C++ standard
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_DIR "${CMAKE_SOURCE_DIR}/cmake")
# Dependencies: Solving external package dependencies
set(EXTERNAL_DIR ${CMAKE_SOURCE_DIR}/externals)

# Boost library Flag
set(BOOST OFF)

# Unit Test Flag
set(TEST ON)


if (MAKE_BUILD_TYPE STREQUAL "Debug")
# Add the following line to enable exception handling
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fexceptions")
endif ()

include(${CMAKE_DIR}/includes.cmake)