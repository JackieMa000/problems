# Enable cTest
include(CTest)

# Install libcheck
include(${EXTERNAL_DIR}/libcheck.cmake)

# Disable it by default, but enable it if you want to check libcheck source code
#add_subdirectory(${EXTERNAL_DIR}/libcheck-src)

include_directories(${CMAKE_SOURCE_DIR}/test)
add_subdirectory(${CMAKE_SOURCE_DIR}/test)
