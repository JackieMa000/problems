add_executable(math.ds_test
        paren_test.cpp
        anagram_test.cpp
        palindrome_test.cpp)
target_link_libraries(math.ds_test
        math.ds
        test_main)