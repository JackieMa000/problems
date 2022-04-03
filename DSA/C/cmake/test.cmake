# Enable cTest
include(CTest)

# Install libcheck
# include(${EXTERNAL_DIR}/libcheck.cmake)
# For the convenience of checking libcheck source code
add_subdirectory(${EXTERNAL_DIR}/libcheck-src)

include_directories(${CMAKE_SOURCE_DIR}/test)
add_subdirectory(${CMAKE_SOURCE_DIR}/test)
