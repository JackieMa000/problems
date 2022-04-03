# Turn on sanitizer for debugging
if (CMAKE_BUILD_TYPE STREQUAL "Debug")
#    include(${CMAKE_DIR}/sanitizer.cmake)
endif ()

# utility macros, functions
include(${CMAKE_DIR}/utils.cmake)

# Compile source
include(${CMAKE_DIR}/src.cmake)

if (${BOOST})
    include(${EXTERNAL_DIR}/boost.cmake)
endif ()

if (${TEST})
    include(${CMAKE_DIR}/test.cmake)
endif ()
