#include <dsa/lib/lib_test.h>
#include "solution.hpp"
#include <dsa/lib/trees/bt.h>

class SolutionTest : public ::testing::Test {
 protected:
    typedef ::dsa::nodes::BinaryTreeNode BinaryTreeNode;
    typedef ::dsa::lib::trees::BinaryTree BinaryTree;

    typedef dsa::lib::LibTest TestFixture;

    static bool isValidBST(BinaryTreeNode *root) {
        Solution3 bst;
        return bst.isValidBST(root);
    }
};
TEST_F(SolutionTest, emptyTreeIsBST) {
    int ary[] = {};
    BinaryTreeNode *root = TestFixture::arrayToBinaryTree(ary, aryLength(ary));
    bool actual = isValidBST(root);
    EXPECT_TRUE(actual);
    BinaryTree::destroy(root);
}
TEST_F(SolutionTest, oneNodeIsBST) {
    int ary[] = {1};
    BinaryTreeNode *root = TestFixture::arrayToBinaryTree(ary, aryLength(ary));
    bool actual = isValidBST(root);
    EXPECT_TRUE(actual);
    BinaryTree::destroy(root);
}
TEST_F(SolutionTest, notBST1) {
    int ary[] = {1, 1};
    BinaryTreeNode *root = TestFixture::arrayToBinaryTree(ary, aryLength(ary));
    bool actual = isValidBST(root);
    EXPECT_FALSE(actual);
    BinaryTree::destroy(root);
}
TEST_F(SolutionTest, notBST2) {
    int ary[] = {2, 4, 5};
    BinaryTreeNode *root = TestFixture::arrayToBinaryTree(ary, aryLength(ary));
    bool actual = isValidBST(root);
    EXPECT_FALSE(actual);
    BinaryTree::destroy(root);
}
TEST_F(SolutionTest, notBST3) {
    int ary[] = {5, 1, 4, 0, 6, 3, 6};
    BinaryTreeNode *root = TestFixture::arrayToBinaryTree(ary, aryLength(ary));
    bool actual = isValidBST(root);
    EXPECT_FALSE(actual);
    BinaryTree::destroy(root);
}
TEST_F(SolutionTest, isBST1) {
    int ary[] = {5, 1, 8, 0, 2, 6, 9};
    BinaryTreeNode *root = TestFixture::arrayToBinaryTree(ary, aryLength(ary));
    bool actual = isValidBST(root);
    EXPECT_TRUE(actual);
    BinaryTree::destroy(root);
}
TEST_F(SolutionTest, isBST2) {
    int ary[] = {5, 1, 6, -3, 2, 0, 7};
    BinaryTreeNode *root = TestFixture::arrayToBinaryTree(ary, aryLength(ary));
    bool actual = isValidBST(root);
    EXPECT_TRUE(actual);
    BinaryTree::destroy(root);
}
TEST_F(SolutionTest, isBST3) {
    int ary[] = {3, 1, 5, 0, 2};
    BinaryTreeNode *root = TestFixture::arrayToBinaryTree(ary, aryLength(ary));
    bool actual = isValidBST(root);
    EXPECT_TRUE(actual);
    BinaryTree::destroy(root);
}
TEST_F(SolutionTest, isBST4) {
    int ary[] = {5, 3, 9, 1, 4, 8, 15};
    BinaryTreeNode *root = TestFixture::arrayToBinaryTree(ary, aryLength(ary));
    bool actual = isValidBST(root);
    EXPECT_TRUE(actual);
    BinaryTree::destroy(root);
}
