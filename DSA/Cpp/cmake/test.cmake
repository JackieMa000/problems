# Enable cTest
include(CTest)

# Install Google Test
include(${EXTERNAL_DIR}/gtest.cmake)

include_directories(${CMAKE_SOURCE_DIR}/test)
add_subdirectory(test)
