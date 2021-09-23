add_executable(algorithms_test

        algo_min_test.cpp algo_max_test.cpp algo_minmax_test.cpp
        maxSizeElement_test.cpp minSizeElement_test.cpp

        strip_test.cpp copy_test.cpp fill_test.cpp swap_test.cpp
        replace_test.cpp remove_test.cpp find_test.cpp count_test.cpp
        reverse_test.cpp distance_test.cpp
        for_each_test.cpp all_of_test.cpp any_of_test.cpp none_of_test.cpp
        equal_test.cpp
        )
target_link_libraries(algorithms_test
        test_main)
target_precompile_headers(algorithms_test PRIVATE pch.h)
