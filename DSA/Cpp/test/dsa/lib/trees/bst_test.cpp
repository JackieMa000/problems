#include <dsa/lib/trees/bst.h>
#include "bst_test.h"

namespace dsa::lib::trees {
namespace {

class IsValidTest : public BinarySearchTreeTest {
 protected:
    static bool isValidBST(BinaryTreeNode *root) {
        BinarySearchTree bst(root);
        return bst.isValid();
    }
};
TEST_F(IsValidTest, emptyTreeIsBST) {
    int ary[] = {};
    BinaryTreeNode *root = arrayToBinaryTree(ary, aryLength(ary));
    bool actual = isValidBST(root);
    EXPECT_TRUE(actual);
    BinaryTree::destroy(root);
}
TEST_F(IsValidTest, oneNodeIsBST) {
    int ary[] = {1};
    BinaryTreeNode *root = arrayToBinaryTree(ary, aryLength(ary));
    bool actual = isValidBST(root);
    EXPECT_TRUE(actual);
    BinaryTree::destroy(root);
}
TEST_F(IsValidTest, notBST1) {
    int ary[] = {1, 1};
    BinaryTreeNode *root = arrayToBinaryTree(ary, aryLength(ary));
    bool actual = isValidBST(root);
    EXPECT_FALSE(actual);
    BinaryTree::destroy(root);
}
TEST_F(IsValidTest, notBST2) {
    int ary[] = {2, 4, 5};
    BinaryTreeNode *root = arrayToBinaryTree(ary, aryLength(ary));
    bool actual = isValidBST(root);
    EXPECT_FALSE(actual);
    BinaryTree::destroy(root);
}
TEST_F(IsValidTest, notBST3) {
    int ary[] = {5, 1, 4, 0, 6, 3, 6};
    BinaryTreeNode *root = arrayToBinaryTree(ary, aryLength(ary));
    bool actual = isValidBST(root);
    EXPECT_FALSE(actual);
    BinaryTree::destroy(root);
}
TEST_F(IsValidTest, isBST1) {
    int ary[] = {5, 1, 8, 0, 2, 6, 9};
    BinaryTreeNode *root = arrayToBinaryTree(ary, aryLength(ary));
    bool actual = isValidBST(root);
    EXPECT_TRUE(actual);
    BinaryTree::destroy(root);
}
TEST_F(IsValidTest, isBST2) {
    int ary[] = {5, 1, 6, -3, 2, 0, 7};
    BinaryTreeNode *root = arrayToBinaryTree(ary, aryLength(ary));
    bool actual = isValidBST(root);
    EXPECT_TRUE(actual);
    BinaryTree::destroy(root);
}
TEST_F(IsValidTest, isBST3) {
    int ary[] = {3, 1, 5, 0, 2};
    BinaryTreeNode *root = arrayToBinaryTree(ary, aryLength(ary));
    bool actual = isValidBST(root);
    EXPECT_TRUE(actual);
    BinaryTree::destroy(root);
}

class LowestCommonAncestorTestBST : public BinarySearchTreeTest {
 protected:
    static BinaryTreeNode *lca(BinaryTreeNode *root, BinaryTreeNode *p, BinaryTreeNode *q) {
        BinarySearchTree bst(root);
        return bst.lowestCommonAncestor(p, q);
    }
};
TEST_F(LowestCommonAncestorTestBST, case1) {
    int ary[] = {6, 2, 8, 1, 4, 7, 9, 0, 0, 3, 5};
    BinaryTreeNode *root = arrayToBinaryTree(ary, aryLength(ary));
    BinaryTreeNode *p = getTreeNodeByValue(root, 2);
    BinaryTreeNode *q = getTreeNodeByValue(root, 8);

    BinaryTreeNode *actual = lca(root, p, q);

    EXPECT_EQ(6, actual->val);
    BinaryTree::destroy(root);
}
TEST_F(LowestCommonAncestorTestBST, case2) {
    int ary[] = {6, 2, 8, 1, 4, 7, 9, 0, 0, 3, 5};
    BinaryTreeNode *root = arrayToBinaryTree(ary, aryLength(ary));
    BinaryTreeNode *p = getTreeNodeByValue(root, 2);
    BinaryTreeNode *q = getTreeNodeByValue(root, 4);

    BinaryTreeNode *actual = lca(root, p, q);

    EXPECT_EQ(2, actual->val);
    BinaryTree::destroy(root);
}
TEST_F(LowestCommonAncestorTestBST, case3) {
    int ary[] = {1, 2};
    BinaryTreeNode *root = arrayToBinaryTree(ary, aryLength(ary));
    BinaryTreeNode *p = getTreeNodeByValue(root, 1);
    BinaryTreeNode *q = getTreeNodeByValue(root, 2);

    BinaryTreeNode *actual = lca(root, p, q);

    EXPECT_EQ(1, actual->val);
    BinaryTree::destroy(root);
}

class PreOrderTestBST : public BinarySearchTreeTest {
 protected:
    static std::vector<int> preorder(BinaryTreeNode *root) {
        BinarySearchTree bst(root);
        return bst.preorderTraversal();
    }
};
TEST_F(PreOrderTestBST, case1) {
    int ary[] = {2, 1};
    BinaryTreeNode *root = arrayToBinaryTree(ary, aryLength(ary));
    std::vector<int> expected = {2, 1};
    std::vector<int> actual = preorder(root);
    EXPECT_EQ(expected, actual);
    BinaryTree::destroy(root);
}
TEST_F(PreOrderTestBST, case2) {
    int ary[] = {2, 1, 3};
    BinaryTreeNode *root = arrayToBinaryTree(ary, aryLength(ary));
    std::vector<int> expected = {2, 1, 3};
    std::vector<int> actual = preorder(root);
    EXPECT_EQ(expected, actual);
    BinaryTree::destroy(root);
}
TEST_F(PreOrderTestBST, case3) {
    int ary[] = {3, 1, 5, 0, 2};
    BinaryTreeNode *root = arrayToBinaryTree(ary, aryLength(ary));
    std::vector<int> expected = {3, 1, 2, 5};
    std::vector<int> actual = preorder(root);
    EXPECT_EQ(expected, actual);
    BinaryTree::destroy(root);
}

class InOrderTestBST : public BinarySearchTreeTest {
 protected:
    static std::vector<int> inorder(BinaryTreeNode *root) {
        BinarySearchTree bst(root);
        return bst.inorderTraversal();
    }
};
TEST_F(InOrderTestBST, case1) {
    int ary[] = {2, 1};
    BinaryTreeNode *root = arrayToBinaryTree(ary, aryLength(ary));
    std::vector<int> expected = {1, 2};
    std::vector<int> actual = inorder(root);
    EXPECT_EQ(expected, actual);
    BinaryTree::destroy(root);
}
TEST_F(InOrderTestBST, case2) {
    int ary[] = {2, 1, 3};
    BinaryTreeNode *root = arrayToBinaryTree(ary, aryLength(ary));
    std::vector<int> expected = {1, 2, 3};
    std::vector<int> actual = inorder(root);
    EXPECT_EQ(expected, actual);
    BinaryTree::destroy(root);
}
TEST_F(InOrderTestBST, case3) {
    int ary[] = {3, 1, 5, 0, 2};
    BinaryTreeNode *root = arrayToBinaryTree(ary, aryLength(ary));
    std::vector<int> expected = {1, 2, 3, 5};
    std::vector<int> actual = inorder(root);
    EXPECT_EQ(expected, actual);
    BinaryTree::destroy(root);
}

class PostOrderTestBST : public BinarySearchTreeTest {
 protected:
    static std::vector<int> postorder(BinaryTreeNode *root) {
        BinarySearchTree bst(root);
        return bst.postorderTraversal();
    }
};
TEST_F(PostOrderTestBST, case1) {
    int ary[] = {2, 1};
    BinaryTreeNode *root = arrayToBinaryTree(ary, aryLength(ary));
    std::vector<int> expected = {1, 2};
    std::vector<int> actual = postorder(root);
    EXPECT_EQ(expected, actual);
    BinaryTree::destroy(root);
}
TEST_F(PostOrderTestBST, case2) {
    int ary[] = {2, 1, 3};
    BinaryTreeNode *root = arrayToBinaryTree(ary, aryLength(ary));
    std::vector<int> expected = {1, 3, 2};
    std::vector<int> actual = postorder(root);
    EXPECT_EQ(expected, actual);
    BinaryTree::destroy(root);
}
TEST_F(PostOrderTestBST, case3) {
    int ary[] = {3, 1, 5, 0, 2};
    BinaryTreeNode *root = arrayToBinaryTree(ary, aryLength(ary));
    std::vector<int> expected = {2, 1, 5, 3};
    std::vector<int> actual = postorder(root);
    EXPECT_EQ(expected, actual);
    BinaryTree::destroy(root);
}

}
}
