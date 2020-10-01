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

TEST_F(ToSinglyLinkedListTest, case1) {
    int ary[] = {1};
    run(ary, sizeof(ary) / sizeof(ary[0]));
}

TEST_F(ToSinglyLinkedListTest, case2) {
    int ary[] = {1, 2, 3};
    run(ary, sizeof(ary) / sizeof(ary[0]));
}

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

TEST_F(RStripTest, empty_array) {
    int ary[] = {}, expected[] = {};
    length_t actLen = arrays::rStrip(ary, sizeof(ary) / sizeof(ary[0]));
    EXPECT_ARRAY_EQ(expected, sizeof(expected) / sizeof(expected[0]), ary, actLen);
}
TEST_F(RStripTest, length1_element0) {
    int ary[] = {0}, expected[] = {};
    length_t actLen = arrays::rStrip(ary, sizeof(ary) / sizeof(ary[0]));
    EXPECT_ARRAY_EQ(expected, sizeof(expected) / sizeof(expected[0]), ary, actLen);
}
TEST_F(RStripTest, last_element_not0) {
    int ary[] = {1, 2}, expected[] = {1, 2};
    length_t actLen = arrays::rStrip(ary, sizeof(ary) / sizeof(ary[0]));
    EXPECT_ARRAY_EQ(expected, sizeof(expected) / sizeof(expected[0]), ary, actLen);
}
TEST_F(RStripTest, last_element0_case1) {
    int ary[] = {1, 2, 0}, expected[] = {1, 2};
    length_t actLen = arrays::rStrip(ary, sizeof(ary) / sizeof(ary[0]));
    EXPECT_ARRAY_EQ(expected, sizeof(expected) / sizeof(expected[0]), ary, actLen);
}
TEST_F(RStripTest, last_element0_case2) {
    int ary[] = {1, 0, 2, 0, 0}, expected[] = {1, 0, 2};
    length_t actLen = arrays::rStrip(ary, sizeof(ary) / sizeof(ary[0]));
    EXPECT_ARRAY_EQ(expected, sizeof(expected) / sizeof(expected[0]), ary, actLen);
}

}  // namespace
}  // namespace dsa::lib::arrays