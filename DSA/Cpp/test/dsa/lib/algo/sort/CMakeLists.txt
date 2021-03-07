add_executable(sort_test
        bubble_sort_test.cpp selection_sort_test.cpp insertion_sort_test.cpp
        merge_sort_test.cpp quick_sort_test.cpp
        bucket_sort_test.cpp)
target_link_libraries(sort_test test_main)

#cmake_minimum_required(VERSION 3.17)
#set(CMAKE_CXX_STANDARD 17)
add_executable(cppmain cppmain.cpp)
