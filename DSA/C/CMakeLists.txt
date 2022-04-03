cmake_minimum_required(VERSION 3.19)

project(DSA-c VERSION 1.0)

set(CMAKE_C_STANDARD 11)

set(CMAKE_DIR "${CMAKE_SOURCE_DIR}/cmake")
# Dependencies: Solving external package dependencies
set(EXTERNAL_DIR ${CMAKE_SOURCE_DIR}/externals)

# Unit Test Flag
set(TEST ON)

include(${CMAKE_DIR}/includes.cmake)