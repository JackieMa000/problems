#include "array_test_fx.hpp"

namespace dsa::lib::lists::arrays {
namespace {

TEST_F(ToSinglyLinkedListTest, case1) {
    int ary[] = {1};
    run(ary, sizeof(ary));
}

TEST_F(ToSinglyLinkedListTest, case2) {
    int ary[] = {1, 2, 3};
    run(ary, sizeof(ary));
}

TEST_F(ToBinaryTreeTest, case1) {
    int ary[] = {1, 2, 3};
    unsigned long size = sizeof(ary);
    EXPECT_ARRAY_EQ_TREE(ary, size / 4, getTreeFromArray(ary, size));
}

TEST_F(ToBinaryTreeTest, case2) {
    int ary[] = {3, 1, 5, 0, 2};
    unsigned long size = sizeof(ary);
    EXPECT_ARRAY_EQ_TREE(ary, size / 4, getTreeFromArray(ary, size));
}

TEST_F(ToBinaryTreeTest, case3) {
    int ary[] = {5, 1, 4, 0, 6, 3, 6};
    unsigned long size = sizeof(ary);
    EXPECT_ARRAY_EQ_TREE(ary, size / 4, getTreeFromArray(ary, size));
}

}  // namespace
}  // namespace dsa::lib::lists::arrays