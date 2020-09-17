#include "array_test_fx.hpp"

namespace dsa::lib::lists::arrays {
namespace {

TEST_F(ToSinglyLinkedListTest, case1) {
    int ary[] = {1};
    run(ary, sizeof(ary) / 4);
}

TEST_F(ToSinglyLinkedListTest, case2) {
    int ary[] = {1, 2, 3};
    run(ary, sizeof(ary) / 4);
}

TEST_F(ToBinaryTreeTest, case1) {
    int ary[] = {1, 2, 3};
    unsigned int len = sizeof(ary) / 4;
    EXPECT_ARRAY_EQ_TREE(ary, len, getTreeFromArray(ary, len));
}

TEST_F(ToBinaryTreeTest, case2) {
    int ary[] = {3, 1, 5, 0, 2};
    unsigned int len = sizeof(ary) / 4;
    EXPECT_ARRAY_EQ_TREE(ary, len, getTreeFromArray(ary, len));
}

TEST_F(ToBinaryTreeTest, case3) {
    int ary[] = {5, 1, 4, 0, 6, 3, 6};
    unsigned int len = sizeof(ary) / 4;
    EXPECT_ARRAY_EQ_TREE(ary, len, getTreeFromArray(ary, len));
}

}  // namespace
}  // namespace dsa::lib::lists::arrays