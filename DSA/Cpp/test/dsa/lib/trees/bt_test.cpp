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

class LowestCommonAncestorTestBT : public BinaryTreeTest {
 protected:
    static BinaryTreeNode *lca(BinaryTreeNode *root, BinaryTreeNode *p, BinaryTreeNode *q) {
        BinaryTree bt(root);
        return bt.lowestCommonAncestor(p, q);
    }
};
TEST_F(LowestCommonAncestorTestBT, case1) {
    int ary[] = {3, 5, 1, 6, 2, 0, 8, 0, 0, 7, 4};
    BinaryTreeNode *root = arrayToBinaryTree(ary, aryLength(ary));
    BinaryTreeNode *p = getTreeNodeByValue(root, 5);
    BinaryTreeNode *q = getTreeNodeByValue(root, 1);

    BinaryTreeNode *actual = lca(root, p, q);

    EXPECT_EQ(3, actual->val);
    BinaryTree::destroy(root);
}
TEST_F(LowestCommonAncestorTestBT, case2) {
    int ary[] = {3, 5, 1, 6, 2, 0, 8, 0, 0, 7, 4};
    BinaryTreeNode *root = arrayToBinaryTree(ary, aryLength(ary));
    BinaryTreeNode *p = getTreeNodeByValue(root, 5);
    BinaryTreeNode *q = getTreeNodeByValue(root, 4);

    BinaryTreeNode *actual = lca(root, p, q);

    EXPECT_EQ(5, actual->val);
    BinaryTree::destroy(root);
}
TEST_F(LowestCommonAncestorTestBT, case3) {
    int ary[] = {1, 2};
    BinaryTreeNode *root = arrayToBinaryTree(ary, aryLength(ary));
    BinaryTreeNode *p = getTreeNodeByValue(root, 1);
    BinaryTreeNode *q = getTreeNodeByValue(root, 2);

    BinaryTreeNode *actual = lca(root, p, q);

    EXPECT_EQ(1, actual->val);
    BinaryTree::destroy(root);
}

class PreOrderTest : public BinaryTreeTest {
 protected:
    static std::vector<int> preorder(BinaryTreeNode *root) {
        BinaryTree bt(root);
        return bt.preorderTraversal();
    }
};
TEST_F(PreOrderTest, emptyTree) {
    std::vector<int> expected = {};
    std::vector<int> actual = preorder(nullptr);
    EXPECT_EQ(expected, actual);
}
TEST_F(PreOrderTest, oneNodeTree) {
    int ary[] = {1};
    BinaryTreeNode *root = arrayToBinaryTree(ary, aryLength(ary));
    std::vector<int> expected = {1};
    std::vector<int> actual = preorder(root);
    EXPECT_EQ(expected, actual);
    BinaryTree::destroy(root);
}
TEST_F(PreOrderTest, case1) {
    int ary[] = {1, 0, 2};
    BinaryTreeNode *root = arrayToBinaryTree(ary, aryLength(ary));
    std::vector<int> expected = {1, 2};
    std::vector<int> actual = preorder(root);
    EXPECT_EQ(expected, actual);
    BinaryTree::destroy(root);
}
TEST_F(PreOrderTest, case2) {
    int ary[] = {1, 2};
    BinaryTreeNode *root = arrayToBinaryTree(ary, aryLength(ary));
    std::vector<int> expected = {1, 2};
    std::vector<int> actual = preorder(root);
    EXPECT_EQ(expected, actual);
    BinaryTree::destroy(root);
}
TEST_F(PreOrderTest, case3) {
    int ary[] = {1, 0, 2, 0, 0, 3};
    BinaryTreeNode *root = arrayToBinaryTree(ary, aryLength(ary));
    std::vector<int> expected = {1, 2, 3};
    std::vector<int> actual = preorder(root);
    EXPECT_EQ(expected, actual);
    BinaryTree::destroy(root);
}

class InOrderTest : public BinaryTreeTest {
 protected:
    static std::vector<int> inorder(BinaryTreeNode *root) {
        BinaryTree bt(root);
        return bt.inorderTraversal();
    }
};
TEST_F(InOrderTest, emptyTree) {
    std::vector<int> expected = {};
    std::vector<int> actual = inorder(nullptr);
    EXPECT_EQ(expected, actual);
}
TEST_F(InOrderTest, oneNodeTree) {
    int ary[] = {1};
    BinaryTreeNode *root = arrayToBinaryTree(ary, aryLength(ary));
    std::vector<int> expected = {1};
    std::vector<int> actual = inorder(root);
    EXPECT_EQ(expected, actual);
    BinaryTree::destroy(root);
}
TEST_F(InOrderTest, case1) {
    int ary[] = {1, 0, 2};
    BinaryTreeNode *root = arrayToBinaryTree(ary, aryLength(ary));
    std::vector<int> expected = {1, 2};
    std::vector<int> actual = inorder(root);
    EXPECT_EQ(expected, actual);
    BinaryTree::destroy(root);
}
TEST_F(InOrderTest, case2) {
    int ary[] = {1, 2};
    BinaryTreeNode *root = arrayToBinaryTree(ary, aryLength(ary));
    std::vector<int> expected = {2, 1};
    std::vector<int> actual = inorder(root);
    EXPECT_EQ(expected, actual);
    BinaryTree::destroy(root);
}
TEST_F(InOrderTest, case3) {
    int ary[] = {1, 0, 2, 0, 0, 3};
    BinaryTreeNode *root = arrayToBinaryTree(ary, aryLength(ary));
    std::vector<int> expected = {1, 3, 2};
    std::vector<int> actual = inorder(root);
    EXPECT_EQ(expected, actual);
    BinaryTree::destroy(root);
}

class PostOrderTest : public BinaryTreeTest {
 protected:
    static std::vector<int> postorder(BinaryTreeNode *root) {
        BinaryTree bt(root);
        return bt.postorderTraversal();
    }
};
TEST_F(PostOrderTest, emptyTree) {
    std::vector<int> expected = {};
    std::vector<int> actual = postorder(nullptr);
    EXPECT_EQ(expected, actual);
}
TEST_F(PostOrderTest, oneNodeTree) {
    int ary[] = {1};
    BinaryTreeNode *root = arrayToBinaryTree(ary, aryLength(ary));
    std::vector<int> expected = {1};
    std::vector<int> actual = postorder(root);
    EXPECT_EQ(expected, actual);
    BinaryTree::destroy(root);
}
TEST_F(PostOrderTest, case1) {
    int ary[] = {1, 0, 2};
    BinaryTreeNode *root = arrayToBinaryTree(ary, aryLength(ary));
    std::vector<int> expected = {2, 1};
    std::vector<int> actual = postorder(root);
    EXPECT_EQ(expected, actual);
    BinaryTree::destroy(root);
}
TEST_F(PostOrderTest, case2) {
    int ary[] = {1, 2};
    BinaryTreeNode *root = arrayToBinaryTree(ary, aryLength(ary));
    std::vector<int> expected = {2, 1};
    std::vector<int> actual = postorder(root);
    EXPECT_EQ(expected, actual);
    BinaryTree::destroy(root);
}
TEST_F(PostOrderTest, case3) {
    int ary[] = {1, 0, 2, 0, 0, 3};
    BinaryTreeNode *root = arrayToBinaryTree(ary, aryLength(ary));
    std::vector<int> expected = {3, 2, 1};
    std::vector<int> actual = postorder(root);
    EXPECT_EQ(expected, actual);
    BinaryTree::destroy(root);
}

class LevelOrderTest : public BinaryTreeTest {
 protected:
    static std::vector<std::vector<int>> levelOrder(BinaryTreeNode *root) {
        BinaryTree bt(root);
        return bt.levelOrder();
    }
};
TEST_F(LevelOrderTest, emptyTree) {
    std::vector<std::vector<int>> expected;
    std::vector<std::vector<int>> actual = levelOrder(nullptr);
    EXPECT_EQ(expected, actual);
}
TEST_F(LevelOrderTest, case1) {
    int ary[] = {3, 9, 20, 0, 0, 15, 7};
    BinaryTreeNode *root = arrayToBinaryTree(ary, aryLength(ary));
    std::vector<std::vector<int>> expected = {{3}, {9, 20}, {15, 7}};
    std::vector<std::vector<int>> actual = levelOrder(root);
    EXPECT_EQ(expected, actual);
    BinaryTree::destroy(root);
}

}
}