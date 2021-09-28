add_executable(utils_test

        nums_test.cpp
        funcs_test.cpp
        )
target_link_libraries(utils_test
        test_main)
target_precompile_headers(utils_test PRIVATE pch.h)

add_subdirectory(algorithms)