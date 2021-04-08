add_executable(sort_test
        bubble_sort_test.cpp selection_sort_test.cpp insertion_sort_test.cpp
        merge_sort_test.cpp quick_sort_test.cpp
        bucket_sort_test.cpp counting_sort_test.cpp)
target_link_libraries(sort_test test_main)