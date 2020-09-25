#ifndef LIB_LISTS_ARRAYS_ARRAY_TEST_H
#define LIB_LISTS_ARRAYS_ARRAY_TEST_H

#include <dsa/lib/trees/bt.h>
#include <dsa/lib/arrays/array.h>
#include <dsa/lib/lists/linkedlists/ls.h>
#include <dsa/testing/testing.h>

namespace dsa::lib::arrays {

class ArrayTest : public testing::DSATest {};

class ToSinglyLinkedListTest : public ArrayTest {
 protected:
    static void run(int *ary, length_t length) {
        Array array(ary, length);
        auto head = array.toSinglyLinkedList();
        EXPECT_ARRAY_EQ_LINKEDLIST(ary, length, head);
        lists::linkedlists::LinkedList::destroy(head);
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

class RStripTest : public ArrayTest {};

}  // namespace dsa::lib::arrays

#endif