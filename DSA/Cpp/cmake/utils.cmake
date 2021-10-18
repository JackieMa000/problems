# precompile headers for target
macro(pch_for_debug target scope pch)
    if ((CMAKE_BUILD_TYPE STREQUAL "Debug") AND (${CMAKE_VERSION} GREATER_EQUAL "3.15.0"))
        target_precompile_headers(${target} ${scope} ${pch})
    endif ()
endmacro()
