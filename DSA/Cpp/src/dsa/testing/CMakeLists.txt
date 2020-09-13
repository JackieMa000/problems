add_library(testing testing.cpp)
target_link_libraries(testing gtest)

add_library(test_main test_main.cpp)
target_link_libraries(test_main testing)