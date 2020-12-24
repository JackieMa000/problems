add_executable(binary_tree_test
        bst_test.cpp
        bt_test.cpp)

target_link_libraries(binary_tree_test
        arrays
        trees
        test_main)