add_executable(linkedlist_test
        ls_test.cpp ls_test1.cpp)

target_link_libraries(linkedlist_test
        linkedlists
        arrays
        test_main)

add_executable(singlyLinkedlist_test
        sls_test.cpp)

target_link_libraries(singlyLinkedlist_test
        linkedlists
        arrays
        test_main)

add_executable(doublyLinkedlist_test
        dls_test.cpp)

target_link_libraries(doublyLinkedlist_test
        linkedlists
        arrays
        test_main)