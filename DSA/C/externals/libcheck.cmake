# The way that CLion manages multiple configurations, it causes a copy of
# the CMakeCache.txt to be copied across due to it not expecting there to
# be a project within a project.  This causes the hard-coded paths in the
# cache to be copied and builds to fail.  To mitigate this, we simply
# remove the cache if it exists before we configure the new project.  It
# is safe to do so because it will be re-generated.  Since this is only
# executed at the configure step, it should not cause additional builds or
# downloads.
file(REMOVE "${CMAKE_BINARY_DIR}/libcheck-download/CMakeCache.txt")

# Download and unpack libcheck at configure time
# the add_subdirectory() command requires this CMakeLists.txt
# the actual value of CMAKE_BINARY_DIR will be replaced with the current value when the file is copied.
configure_file(${EXTERNAL_DIR}/libcheck.cmake.in ${CMAKE_BINARY_DIR}/libcheck-download/CMakeLists.txt)

# invoke CMake to setup and execute a sub-build of the CMakeLists.txt file we just copied
# this is what the two execute_process() commands are doing. These are simply forcing CMake to immediately fully process
# the CMakeLists.txt file we copied rather than waiting until build time
# cMake configure the project
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/libcheck-download)
if (result)
    message(FATAL_ERROR "CMake step for libcheck failed: ${result}")
endif ()

# cMake build the project
execute_process(COMMAND ${CMAKE_COMMAND} --build .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/libcheck-download)
if (result)
    message(FATAL_ERROR "Build step for libcheck failed: ${result}")
endif ()

# Add libcheck directly to our build.
add_subdirectory(${CMAKE_BINARY_DIR}/libcheck-src
        ${CMAKE_BINARY_DIR}/libcheck-build
        EXCLUDE_FROM_ALL)

# CMake also manages the git clone and checkout steps for us and ensures it does not repeat those steps unless
# it is required, such as if you change the URL of the git repository, change the git tag or delete the build
# output directory. In short, CMake is doing all the work for you, as it should!