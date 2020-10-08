#include <dsa/lib/arrays/array.h>
#include <dsa/lib/lists/linkedlists/ls.h>
#include <dsa/lib/trees/bt.h>
#include "array_test.h"

namespace dsa::lib::arrays {
namespace {

class ToSinglyLinkedListTest : public ArrayTest {
 protected:
    static void run(int *ary, length_t length) {
        Array array(ary, length);
        auto head = array.toSinglyLinkedList();
        EXPECT_ARRAY_EQ_LINKEDLIST(ary, length, head);
        lists::linkedlists::LinkedList::destroy(head);
    }
};
TEST_F(ToSinglyLinkedListTest, case1) {
    int ary[] = {1};
    run(ary, sizeof(ary) / sizeof(ary[0]));
}
TEST_F(ToSinglyLinkedListTest, case2) {
    int ary[] = {1, 2, 3};
    run(ary, sizeof(ary) / sizeof(ary[0]));
}

class ToBinaryTreeTest : public ArrayTest {
 protected:
    static void run(int *ary, length_t length) {
        Array array(ary, length);
        auto root = array.toBinaryTree();
        EXPECT_ARRAY_EQ_TREE(ary, length, root);
        trees::BinaryTree::destroy(root);
    }
};
TEST_F(ToBinaryTreeTest, case1) {
    int ary[] = {1, 2, 3};
    run(ary, sizeof(ary) / sizeof(ary[0]));
}

TEST_F(ToBinaryTreeTest, case2) {
    int ary[] = {3, 1, 5, 0, 2};
    run(ary, sizeof(ary) / sizeof(ary[0]));
}
TEST_F(ToBinaryTreeTest, case3) {
    int ary[] = {5, 1, 4, 0, 6, 3, 6};
    run(ary, sizeof(ary) / sizeof(ary[0]));
}
TEST_F(ToBinaryTreeTest, case4) {
    int ary[] = {1, 0};
    run(ary, sizeof(ary) / sizeof(ary[0]));
}
TEST_F(ToBinaryTreeTest, nullNode) {
    int ary[] = {0};
    Array array(ary, sizeof(ary) / sizeof(ary[0]));
    EXPECT_EQ(nullptr, array.toBinaryTree());
}

}  // namespace
}  // namespace dsa::lib::arrays