cmake_minimum_required(VERSION 3.15)

# set the project name and version
project(DSA-cpp, VERSION 1.0)

##### specify the C/C++ standard
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_DIR "${CMAKE_SOURCE_DIR}/cmake")
# Dependencies: Solving external package dependencies
set(EXTERNAL_DIR ${CMAKE_SOURCE_DIR}/externals)

# Turn on sanitizer for debugging
if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    include(${CMAKE_DIR}/sanitizer.cmake)
endif ()

# Boost library Flag
set(BOOST OFF)
if (${BOOST})
    include(${CMAKE_DIR}/boost.cmake)
endif ()

# utility macros, functions
include(${CMAKE_DIR}/utils.cmake)

# Compile source
include(${CMAKE_DIR}/src.cmake)

# Test Flag
set(TEST ON)
if (${TEST})
    include(${CMAKE_DIR}/test.cmake)
endif ()