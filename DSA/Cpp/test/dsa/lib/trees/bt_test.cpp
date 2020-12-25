#include <dsa/lib/trees/bt.h>
#include "bt_test.h"

namespace dsa::lib::trees {
namespace {

class ToArrayTest : public BinaryTreeTest {
 protected:
    [[nodiscard]] inline static arrayStruct toArray(BinaryTreeNode *root) {
        BinaryTree bt(root);
        return bt.toArray();
    }
    inline static void run(int ary[], length_t length) {
        BinaryTreeNode *root = arrayToBinaryTree(ary, length);
        auto actual = toArray(root);
        EXPECT_ARRAY_EQ(ary, length, actual.ary, actual.length);
        BinaryTree::destroy(root);
        delete[] actual.ary;
    }
};
TEST_F(ToArrayTest, nullTree) {
    auto actual = toArray(nullptr);
    EXPECT_EQ(0, actual.length);
    EXPECT_EQ(nullptr, actual.ary);
}
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

class DepthTest : public BinaryTreeTest {
 protected:
    static depth_t getTreeDepth(BinaryTreeNode *root) {
        BinaryTree bt(root);
        return bt.depth();
    }
    static void run(int *ary, length_t length, depth_t expected) {
        BinaryTreeNode *root = arrayToBinaryTree(ary, length);
        auto actual = getTreeDepth(root);
        EXPECT_EQ(expected, actual);
        BinaryTree::destroy(root);
    }
};
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

class GetArraySizeForBinaryTreeTest : public BinaryTreeTest {
 protected:
    static void run(int *ary, length_t length, length_t expected) {
        BinaryTreeNode *root = arrayToBinaryTree(ary, length);
        auto actual = BinaryTree::getArraySizeForBinaryTree(root);
        EXPECT_EQ(expected, actual);
        BinaryTree::destroy(root);
    }
};
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

class GetNodeByIndexTest : public BinaryTreeTest {
 protected:
    static BinaryTreeNode *getNodeByIndex(BinaryTreeNode *root, pos_t i) {
        BinaryTree bt(root);
        return bt.getNodeByIndex(i);
    }
};
TEST_F(GetNodeByIndexTest, case1) {
    BinaryTreeNode *actual = getNodeByIndex(nullptr, 0);
    EXPECT_EQ(nullptr, actual);
}
TEST_F(GetNodeByIndexTest, case2) {
    BinaryTreeNode *actual = getNodeByIndex(nullptr, 1);
    EXPECT_EQ(nullptr, actual);
}
TEST_F(GetNodeByIndexTest, case3) {
    int ary[] = {1};
    BinaryTreeNode *root = arrayToBinaryTree(ary, aryLength(ary));
    BinaryTreeNode *actual = getNodeByIndex(root, 1);

    EXPECT_EQ(nullptr, actual);
    BinaryTree::destroy(root);
}
TEST_F(GetNodeByIndexTest, case4) {
    int ary[] = {1, 0, 3};
    BinaryTreeNode *root = arrayToBinaryTree(ary, aryLength(ary));
    BinaryTreeNode *actual = getNodeByIndex(root, 1);

    EXPECT_EQ(nullptr, actual);
    BinaryTree::destroy(root);
}
TEST_F(GetNodeByIndexTest, case5) {
    int ary[] = {1};
    BinaryTreeNode *root = arrayToBinaryTree(ary, aryLength(ary));
    BinaryTreeNode *actual = getNodeByIndex(root, 0);

    EXPECT_EQ(1, actual->val);
    BinaryTree::destroy(root);
}
TEST_F(GetNodeByIndexTest, case6) {
    int ary[] = {1, 2, 3};
    BinaryTreeNode *root = arrayToBinaryTree(ary, aryLength(ary));
    BinaryTreeNode *actual = getNodeByIndex(root, 2);

    EXPECT_EQ(3, actual->val);
    BinaryTree::destroy(root);
}
TEST_F(GetNodeByIndexTest, case7) {
    int ary[] = {3, 1, 5, 0, 2};
    BinaryTreeNode *root = arrayToBinaryTree(ary, aryLength(ary));
    BinaryTreeNode *actual = getNodeByIndex(root, 4);

    EXPECT_EQ(2, actual->val);
    BinaryTree::destroy(root);
}

class GetNodeByValueTest : public BinaryTreeTest {
 protected:
    static BinaryTreeNode *getNodeByValue(BinaryTreeNode *root, int val) {
        BinaryTree bt(root);
        return bt.getNodeByValue(val);
    }
};
TEST_F(GetNodeByValueTest, emptyTree) {
    BinaryTreeNode *actual = getNodeByValue(nullptr, 1);
    EXPECT_EQ(nullptr, actual);
}
TEST_F(GetNodeByValueTest, valueNotExist) {
    int ary[] = {1};
    BinaryTreeNode *root = arrayToBinaryTree(ary, aryLength(ary));
    BinaryTreeNode *actual = getNodeByValue(root, 2);
    EXPECT_EQ(nullptr, actual);
    BinaryTree::destroy(root);
}
TEST_F(GetNodeByValueTest, case1) {
    int ary[] = {1};
    BinaryTreeNode *root = arrayToBinaryTree(ary, aryLength(ary));
    BinaryTreeNode *actual = getNodeByValue(root, 1);
    EXPECT_EQ(1, actual->val);
    BinaryTree::destroy(root);
}
TEST_F(GetNodeByValueTest, case2) {
    int ary[] = {1, 2, 3};
    BinaryTreeNode *root = arrayToBinaryTree(ary, aryLength(ary));
    BinaryTreeNode *actual = getNodeByValue(root, 3);
    EXPECT_EQ(3, actual->val);
    BinaryTree::destroy(root);
}
TEST_F(GetNodeByValueTest, case3) {
    int ary[] = {1, 2, 3};
    BinaryTreeNode *root = arrayToBinaryTree(ary, aryLength(ary));
    BinaryTreeNode *actual = getNodeByValue(root, 2);
    EXPECT_EQ(2, actual->val);
    BinaryTree::destroy(root);
}
TEST_F(GetNodeByValueTest, case4) {
    int ary[] = {3, 1, 5, 0, 2};
    BinaryTreeNode *root = arrayToBinaryTree(ary, aryLength(ary));
    BinaryTreeNode *actual = getNodeByValue(root, 2);
    EXPECT_EQ(2, actual->val);
    BinaryTree::destroy(root);
}

//class LowestCommonAncestorTest : public LibTest {
class LowestCommonAncestorTest : public BinaryTreeTest {
 protected:
    static BinaryTreeNode *lca(BinaryTreeNode *root, BinaryTreeNode *p, BinaryTreeNode *q) {
        BinaryTree bt(root);
        return bt.lowestCommonAncestor(p, q);
    }
};
//TEST_F(LowestCommonAncestorTest, case1) {
////    Act;
//    int ary[] = {3, 5, 1, 6, 2, 0, 8, 0, 0, 7, 4};
//    length_t length = aryLength(ary);
//    BinaryTreeNode *root = arrayToBinaryTree(ary, length);
//    BinaryTreeNode *p = getTreeNodeByValue(5);
//    BinaryTreeNode *q = getTreeNodeByValue(1);
//
////    Arrange;
//    BinaryTreeNode *actual = lca(root, p, q);
////    Assert;
//
//}

}
}