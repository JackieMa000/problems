add_executable(linkedlist_test
ls_test.cpp)

add_executable(singlyLinkedlist_test
sls_test.cpp)

add_executable(doublyLinkedlist_test
dls_test.cpp)

target_link_libraries(linkedlist_test
nodes
linkedlists
arrays
test_main)

target_link_libraries(singlyLinkedlist_test
nodes
linkedlists
arrays
test_main)

target_link_libraries(doublyLinkedlist_test
nodes
linkedlists
arrays
test_main)