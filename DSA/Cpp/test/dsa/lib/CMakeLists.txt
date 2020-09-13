add_executable(utils_test utils_test.cpp)
target_link_libraries(utils_test test_main)
target_link_libraries(utils_test utils)

add_subdirectory(lists)
