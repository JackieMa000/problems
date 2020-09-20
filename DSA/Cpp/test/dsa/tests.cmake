######### Utils Test ##############
add_test(NAME Utils_test COMMAND utils_test)

######### Arrays Test #############
add_test(NAME ArrayTest COMMAND array_test)

###### LinkedList Test ####
add_test(NAME LinkedListTest COMMAND linkedlist_test)
add_test(NAME SinglyLinkedlistTest COMMAND singlyLinkedlist_test)
add_test(NAME DoublyLinkedlistTest COMMAND doublyLinkedlist_test)

######## Tree Test ####
add_test(NAME BinaryTreeTest COMMAND binary_tree_test)