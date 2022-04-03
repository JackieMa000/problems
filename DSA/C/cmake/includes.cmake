# Turn on sanitizer for debugging
if (CMAKE_BUILD_TYPE STREQUAL "Debug")
#    include(${CMAKE_DIR}/sanitizer.cmake)
endif ()

# Compile source
include(${CMAKE_DIR}/src.cmake)

if (${TEST})
    include(${CMAKE_DIR}/test.cmake)
endif ()
