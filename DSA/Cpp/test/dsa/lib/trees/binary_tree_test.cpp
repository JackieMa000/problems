#include <dsa/lib/trees/bt.h>
#include "binary_tree_test.h"

namespace dsa::lib::trees {
namespace {

class ToArrayTest : public BinaryTreeTest {
 protected:
    inline static BinaryTreeNode *generateTreeFromArray(int *ary, length_t length) {
        arrays::Array array(ary, length);
        return array.toBinaryTree();
    }
    inline static std::tuple<length_t, int *> toArray(BinaryTreeNode *root) {
        BinaryTree bt(root);
        return bt.toArray();
    }
    inline static void run(int ary[], length_t length) {
        BinaryTreeNode *root = generateTreeFromArray(ary, length);
        auto[actLen, actAry] = toArray(root);
        EXPECT_ARRAY_EQ(ary, length, actAry, actLen);

        BinaryTree::destroy(root);
        delete[] actAry;
    }
};

//FixMe: Memory Leak
class DepthTest : public BinaryTreeTest {
 protected:
    static depth_t getTreeDepth(BinaryTreeNode *root) {
        BinaryTree bt(root);
        return bt.depth();
    }

    static BinaryTreeNode *generateTreeFromArray(int *ary, length_t length) {
        arrays::Array array(ary, length);
        return array.toBinaryTree();
    }
};

//FixMe: Memory Leak
class GetArraySizeForBinaryTree : public BinaryTreeTest {
 protected:
    static length_t act(int *ary, length_t length) {
        arrays::Array array(ary, length);
        return BinaryTree::getArraySizeForBinaryTree(array.toBinaryTree());
    }
};

TEST_F(ToArrayTest, case1) {
    int ary[] = {1, 2, 3};
    run(ary, sizeof(ary) / sizeof(ary[0]));
}
TEST_F(ToArrayTest, case2) {
    int ary[] = {3, 1, 5, 0, 2};
    run(ary, sizeof(ary) / sizeof(ary[0]));
}
TEST_F(ToArrayTest, case3) {
    int ary[] = {5, 1, 4, 0, 6, 3, 6};
    run(ary, sizeof(ary) / sizeof(ary[0]));
}

TEST_F(DepthTest, case1) {
    int ary[] = {1};
    auto actual = getTreeDepth(generateTreeFromArray(ary, sizeof(ary) / sizeof(ary[0])));
    EXPECT_EQ(1, actual);
}
TEST_F(DepthTest, case2) {
    int ary[] = {1, 2, 3};
    auto actual = getTreeDepth(generateTreeFromArray(ary, sizeof(ary) / sizeof(ary[0])));
    EXPECT_EQ(2, actual);
}
TEST_F(DepthTest, case3) {
    int ary[] = {5, 1, 4, 0, 0, 3, 6};
    auto actual = getTreeDepth(generateTreeFromArray(ary, sizeof(ary) / sizeof(ary[0])));
    EXPECT_EQ(3, actual);
}

TEST_F(GetArraySizeForBinaryTree, case1) {
    int ary[] = {1};
    auto actual = act(ary, sizeof(ary) / sizeof(ary[0]));
    EXPECT_EQ(1, actual);
}
TEST_F(GetArraySizeForBinaryTree, case2) {
    int ary[] = {1, 2};
    auto actual = act(ary, sizeof(ary) / sizeof(ary[0]));
    EXPECT_EQ(3, actual);
}
TEST_F(GetArraySizeForBinaryTree, case3) {
    int ary[] = {1, 2, 3};
    auto actual = act(ary, sizeof(ary) / sizeof(ary[0]));
    EXPECT_EQ(3, actual);
}
TEST_F(GetArraySizeForBinaryTree, case4) {
    int ary[] = {3, 1, 5, 0, 2};
    auto actual = act(ary, sizeof(ary) / sizeof(ary[0]));
    EXPECT_EQ(7, actual);
}

}
}