#ifndef LIB_TREES_BST_H
#define LIB_TREES_BST_H

#include "bt.h"

namespace dsa::lib::trees {

class BinarySearchTree : public BinaryTree {
 public:
    explicit BinarySearchTree(BinaryTreeNode *root);

    std::vector<int> preorder();
    std::vector<int> *inorder();
    std::vector<int> &postorder();

//    LeetCode98
    bool isValid();

//    LeetCode235
    BinaryTreeNode *lowestCommonAncestor(BinaryTreeNode *p, BinaryTreeNode *q) override;

 private:
    static std::vector<int> preorderDfs(BinaryTreeNode *root, std::vector<int> lst);
    static std::vector<int> *inorderDfs(BinaryTreeNode *root, std::vector<int> *lst);
    static std::vector<int> &postorderDfs(BinaryTreeNode *root, std::vector<int> &lst);
    static bool isValidBST(BinaryTreeNode *root, BinaryTreeNode *minNode, BinaryTreeNode *maxNode);
    static BinaryTreeNode *lowestCommonAncestorDfs(BinaryTreeNode *root, BinaryTreeNode *p, BinaryTreeNode *q);
    static BinaryTreeNode *lowestCommonAncestorBfs(BinaryTreeNode *root, BinaryTreeNode *p, BinaryTreeNode *q);

};

}  // namespace dsa::lib::trees

#endif