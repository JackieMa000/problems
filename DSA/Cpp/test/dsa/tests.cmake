######### Utils Test ##############
add_test(NAME UtilsTest COMMAND utils_test)

######### Arrays Test #############
add_test(NAME ArrayTest COMMAND array_test)

###### LinkedList Test ####
add_test(NAME LinkedListTest COMMAND linkedlist_test)
add_test(NAME SinglyLinkedlistTest COMMAND singlyLinkedlist_test)
add_test(NAME DoublyLinkedlistTest COMMAND doublyLinkedlist_test)

######## Tree Test ####
add_test(NAME BinaryTreeTest COMMAND binary_tree_test)

######## Math Test #####
add_test(NAME Math.DSTest COMMAND math.ds_test)
add_test(NAME Math.NumsTest COMMAND math.nums_test)

######### Container Test #####
add_test(NAME QueueTest COMMAND queue_test)

######## Algo Test #####
add_test(NAME SortTest COMMAND sort_test)

######## Testing Test #####
add_test(NAME TestingTest COMMAND testing_test)
