# Enable cMake's CTest
include(CTest)

add_subdirectory(lib)
add_subdirectory(testing)

# Add cTest
include(tests.cmake)