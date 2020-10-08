#include <dsa/lib/trees/bt.h>
#include "binary_tree_test.h"

namespace dsa::lib::trees {
namespace {

class ToArrayTest : public BinaryTreeTest {
 protected:
    [[nodiscard]] inline static std::tuple<length_t, int *> toArray(BinaryTreeNode *root) {
        BinaryTree bt(root);
        return bt.toArray();
    }

    inline static void run(int ary[], length_t length) {
        BinaryTreeNode *root = arrayToTree(ary, length);
        auto[actLen, actAry] = toArray(root);
        EXPECT_ARRAY_EQ(ary, length, actAry, actLen);
        BinaryTree::destroy(root);
        delete[] actAry;
    }
};

class DepthTest : public BinaryTreeTest {
 protected:
    static depth_t getTreeDepth(BinaryTreeNode *root) {
        BinaryTree bt(root);
        return bt.depth();
    }

    static void run(int *ary, length_t length, depth_t expected) {
        BinaryTreeNode *root = arrayToTree(ary, length);
        auto actual = getTreeDepth(root);
        EXPECT_EQ(expected, actual);
        BinaryTree::destroy(root);
    }
};

class GetArraySizeForBinaryTreeTest : public BinaryTreeTest {
 protected:
    static void run(int *ary, length_t length, length_t expected) {
        BinaryTreeNode *root = arrayToTree(ary, length);
        auto actual = BinaryTree::getArraySizeForBinaryTree(root);
        EXPECT_EQ(expected, actual);
        BinaryTree::destroy(root);
    }
};

TEST_F(ToArrayTest, case1) {
    int ary[] = {1, 2, 3};
    run(ary, aryLength(ary));
}
TEST_F(ToArrayTest, case2) {
    int ary[] = {3, 1, 5, 0, 2};
    run(ary, aryLength(ary));
}
TEST_F(ToArrayTest, case3) {
    int ary[] = {5, 1, 4, 0, 6, 3, 6};
    run(ary, aryLength(ary));
}

TEST_F(DepthTest, case1) {
    int ary[] = {1};
    run(ary, aryLength(ary), 1);
}
TEST_F(DepthTest, case2) {
    int ary[] = {1, 2, 3};
    run(ary, aryLength(ary), 2);
}
TEST_F(DepthTest, case3) {
    int ary[] = {5, 1, 4, 0, 0, 3, 6};
    run(ary, aryLength(ary), 3);
}

TEST_F(GetArraySizeForBinaryTreeTest, case1) {
    int ary[] = {1};
    run(ary, aryLength(ary), 1);
}
TEST_F(GetArraySizeForBinaryTreeTest, case2) {
    int ary[] = {1, 2};
    run(ary, aryLength(ary), 3);
}
TEST_F(GetArraySizeForBinaryTreeTest, case3) {
    int ary[] = {1, 2, 3};
    run(ary, aryLength(ary), 3);
}
TEST_F(GetArraySizeForBinaryTreeTest, case4) {
    int ary[] = {3, 1, 5, 0, 2};
    run(ary, aryLength(ary), 7);
}

}
}