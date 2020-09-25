add_executable(utils_test utils_test.cpp)
target_link_libraries(utils_test
        utils
        test_main)

add_subdirectory(lists)
add_subdirectory(trees)
add_subdirectory(arrays)
