add_library(testing testing.cpp)
target_link_libraries(testing PUBLIC gtest)
pch_for_debug(testing PUBLIC pch.h)

add_library(test_main test_main.cpp)
target_link_libraries(test_main PUBLIC testing)
pch_for_debug(test_main PUBLIC pch.h)

add_executable(testing_test testing_test.cpp)
target_link_libraries(testing_test test_main)