#ifndef LIB_LISTS_ARRAYS_ARRAY_TEST_H
#define LIB_LISTS_ARRAYS_ARRAY_TEST_H

#include <dsa/lib/lists/list_test_fx.hpp>

namespace dsa::lib::lists::arrays {

class ArrayTest : public ListTest {
};

class ToSinglyLinkedListTest : public ArrayTest {
 protected:
    static void run(int *ary, unsigned long size) {
        nodes::ListNode *actual = createSinglyLinkedList(ary, size);
        EXPECT_ARRAY_EQ_LINKEDLIST(ary, size / 4, actual);
        destroyLinkedList(actual);
    }
};

class ToBinaryTreeTest : public ArrayTest {
 protected:
    static nodes::BinaryTreeNode *getTreeFromArray(int *ary, unsigned long size) {
        Array array(ary, size);
        return array.toBinaryTree();
    }
};

}  // namespace dsa::lib::lists::arrays

#endif