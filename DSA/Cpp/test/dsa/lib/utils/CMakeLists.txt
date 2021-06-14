add_executable(utils_test

        algo_min_test.cpp
        algo_max_test.cpp
        algo_minmax_test.cpp

        algorithm_test.cpp
        algo_test_1.cpp
        algo_test_2.cpp

        nums_test.cpp)
target_link_libraries(utils_test
        test_main)
target_precompile_headers(utils_test PRIVATE pch.h)
