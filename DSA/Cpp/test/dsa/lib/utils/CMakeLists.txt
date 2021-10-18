add_executable(utils_test

        nums_test.cpp
        funcs_test.cpp
        )
target_link_libraries(utils_test
        test_main)
pch_for_debug(utils_test PRIVATE pch.h)

add_subdirectory(algorithms)