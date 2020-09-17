#ifndef LIB_LISTS_ARRAYS_ARRAY_TEST_H
#define LIB_LISTS_ARRAYS_ARRAY_TEST_H

#include <dsa/lib/lists/list_test_fx.hpp>

namespace dsa::lib::lists::arrays {

class ArrayTest : public ListTest {
};

class ToSinglyLinkedListTest : public ArrayTest {
 protected:
    static void run(int *ary, unsigned int length) {
        nodes::ListNode *actual = createSinglyLinkedList(ary, length);
        EXPECT_ARRAY_EQ_LINKEDLIST(ary, length, actual);
        destroyLinkedList(actual);
    }
};

class ToBinaryTreeTest : public ArrayTest {
 protected:
    static nodes::BinaryTreeNode *getTreeFromArray(int *ary, unsigned int length) {
        Array array(ary, length);
        return array.toBinaryTree();
    }
};

}  // namespace dsa::lib::lists::arrays

#endif