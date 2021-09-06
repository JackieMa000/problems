#include <dsa/lib/arrays/array.h>
#include <dsa/lib/lists/linkedlists/ls.h>
#include <dsa/lib/trees/bt.h>
#include "array_test.h"

namespace dsa::lib::arrays {
namespace {

class ToSinglyLinkedListTest : public ArrayTest {
 protected:
    static void run(int *ary, length_t length) {
        auto head = arrayToSinglyLinkedlist(ary, length);
        EXPECT_ARRAY_EQ_LINKEDLIST(ary, length, head);
        lists::linkedlists::LinkedList::destroy(head);
    }

    static void expectNull(int *ary, length_t length) {
        auto head = arrayToSinglyLinkedlist(ary, length);
        EXPECT_EQ(nullptr, head);
    }
};
TEST_F(ToSinglyLinkedListTest, emptyArray) {
    int ary[] = {};
    expectNull(ary, arylen(ary));
}
TEST_F(ToSinglyLinkedListTest, firstElement0) {
    int ary[] = {0};
    expectNull(ary, arylen(ary));
}
TEST_F(ToSinglyLinkedListTest, firstElement0_1) {
    int ary[] = {0, 1};
    expectNull(ary, arylen(ary));
}
TEST_F(ToSinglyLinkedListTest, case1) {
    int ary[] = {1};
    run(ary, arylen(ary));
}
TEST_F(ToSinglyLinkedListTest, case2) {
    int ary[] = {1, 2, 3};
    run(ary, arylen(ary));
}

class ToCyclicSinglyLinkedListTest : public ArrayTest {
 protected:
    static void run(int *ary, length_t length, int pos, int expected, int idx) {
        ListNode *actual = toCyclicSingyLinkedList(ary, length, pos);
        EXPECT_EQ(expected, getLinkedListNodeByIndex(actual, idx)->val);
        lists::linkedlists::LinkedList::destroyCycle(actual, length);
    }
    static ListNode *toCyclicSingyLinkedList(int *ary, length_t length, int pos) {
        Array array(ary, length);
        return array.toCyclicSinglyLinkedList(pos);
    }
    static void runPosMinus(int *ary, length_t length, int pos) {
        ListNode *actual = toCyclicSingyLinkedList(ary, length, pos);
        EXPECT_ARRAY_EQ_LINKEDLIST(ary, length, actual);
        lists::linkedlists::LinkedList::destroyCycle(actual, length);
    }
};
TEST_F(ToCyclicSinglyLinkedListTest, posMinus) {
    int ary[] = {1, 2, 3};
    runPosMinus(ary, arylen(ary), -1);
}
TEST_F(ToCyclicSinglyLinkedListTest, posMinus1) {
    int ary[] = {1, 2, 3};
    runPosMinus(ary, arylen(ary), -2);
}
TEST_F(ToCyclicSinglyLinkedListTest, case1) {
    int ary[] = {1, 2, 3};
    run(ary, arylen(ary), 0, 1, 3);
}
TEST_F(ToCyclicSinglyLinkedListTest, case2) {
    int ary[] = {1, 2, 3};
    run(ary, arylen(ary), 1, 2, 3);
}
TEST_F(ToCyclicSinglyLinkedListTest, case3) {
    int ary[] = {1, 2, 3};
    run(ary, arylen(ary), 2, 3, 2);
}

class ToBinaryTreeTest : public ArrayTest {
 protected:
    static void run(int *ary, length_t length) {
        BinaryTreeNode *root = arrayToBinaryTree(ary, length);
        EXPECT_EQ_TREE(ary, ary + length, root);
        trees::BinaryTree::destroy(root);
    }
    static void expectNull(int *ary, length_t length) {
        EXPECT_EQ(nullptr, arrayToBinaryTree(ary, length));
    }
};
TEST_F(ToBinaryTreeTest, emptyArray) {
    int ary[] = {};
    expectNull(ary, arylen(ary));
}
TEST_F(ToBinaryTreeTest, firstElement0) {
    int ary[] = {0};
    expectNull(ary, arylen(ary));
}
TEST_F(ToBinaryTreeTest, firstElement0_1) {
    int ary[] = {0, 1};
    expectNull(ary, arylen(ary));
}
TEST_F(ToBinaryTreeTest, case1) {
    int ary[] = {1, 2, 3};
    run(ary, arylen(ary));
}
TEST_F(ToBinaryTreeTest, case2) {
    int ary[] = {3, 1, 5, 0, 2};
    run(ary, arylen(ary));
}
TEST_F(ToBinaryTreeTest, case3) {
    int ary[] = {5, 1, 4, 0, 6, 3, 6};
    run(ary, arylen(ary));
}
TEST_F(ToBinaryTreeTest, case4) {
    int ary[] = {1, 0};
    run(ary, arylen(ary));
}

}  // namespace
}  // namespace dsa::lib::arrays