#ifndef LIB_LISTS_ARRAYS_ARRAY_TEST_H
#define LIB_LISTS_ARRAYS_ARRAY_TEST_H

#include <dsa/lib/lists/list_test.h>
#include <dsa/lib/trees/bt.h>

namespace dsa::lib::lists::arrays {

class ArrayTest : public ListTest {};

class ToSinglyLinkedListTest : public ArrayTest {
 protected:
    static void run(int *ary, length_t length) {
        Array array(ary, length);
        auto head = array.toSinglyLinkedList();
        EXPECT_ARRAY_EQ_LINKEDLIST(ary, length, head);
        linkedlists::LinkedList::destroy(head);
    }
};

class ToBinaryTreeTest : public ArrayTest {
 protected:
    static void run(int *ary, length_t length) {
        Array array(ary, length);
        auto root = array.toBinaryTree();
        EXPECT_ARRAY_EQ_TREE(ary, length, root);
        trees::BinaryTree::destroy(root);
    }
};

}  // namespace dsa::lib::lists::arrays

#endif