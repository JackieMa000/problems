#include "bst.h"

namespace dsa::lib::trees {

BinarySearchTree::BinarySearchTree(BinaryTreeNode *root) : BinaryTree(root) {}

std::vector<int> BinarySearchTree::preorder() {
    std::vector<int> lst;
    return preorderDfs(this->root, lst);
}
std::vector<int> BinarySearchTree::preorderDfs(BinaryTreeNode *root, std::vector<int> lst) {
    if (root) {
        lst.push_back(root->val);
        preorderDfs(root->left, lst);
        preorderDfs(root->right, lst);
    }
    return lst;
}

std::vector<int> *BinarySearchTree::inorder() {
    std::vector<int> *lst;
    lst = new std::vector<int>();
    return inorderDfs(this->root, lst);
}
std::vector<int> *BinarySearchTree::inorderDfs(BinaryTreeNode *root, std::vector<int> *lst) {
    if (root) {
        inorderDfs(root->left, lst);
        lst->push_back(root->val);
        inorderDfs(root->right, lst);
    }
    return lst;
}

std::vector<int> &BinarySearchTree::postorder() {
    std::vector<int> lst;
    return postorderDfs(this->root, lst);
}
std::vector<int> &BinarySearchTree::postorderDfs(BinaryTreeNode *root, std::vector<int> &lst) {
    if (root) {
        postorderDfs(root->left, lst);
        postorderDfs(root->right, lst);
        lst.push_back(root->val);
    }
    return lst;
}

bool BinarySearchTree::isValid() {
    return isValidBST(this->root, nullptr, nullptr);
}
/**
 *LowerBound and UpperBound.
 * BST Rule:
 * left(all nodes) < root < right(all nodes)
 * Biggest on the left < root < smallest on the right
 */
bool BinarySearchTree::isValidBST(BinaryTreeNode *root,
                                  BinaryTreeNode *minNode,
                                  BinaryTreeNode *maxNode) {
    if (!root) return true;

    // Biggest on the left, Upper Bound
    if (maxNode && root->val >= maxNode->val) return false;

    // Smallest on the right, Lower Bound
    if (minNode && root->val <= minNode->val) return false;

    return isValidBST(root->left, minNode, root) && isValidBST(root->right, root, maxNode);
}

/**
 * BST LCA Rule:
 * 1. if p < root < q or q < root < p -> root
 * 2. if p < root and q < root -> goes to left subtree
 * 3. if root < p and root < q -> goes to right subtree
 */
BinaryTreeNode *BinarySearchTree::lowestCommonAncestor(BinaryTreeNode *p, BinaryTreeNode *q) {
    return lowestCommonAncestorDfs(this->root, p, q);
}

BinaryTreeNode *BinarySearchTree::lowestCommonAncestorDfs(BinaryTreeNode *root,
                                                          BinaryTreeNode *p,
                                                          BinaryTreeNode *q) {
    return (p->val < root->val && q->val < root->val) ? lowestCommonAncestorDfs(root->left, p, q) :
           (root->val < p->val && root->val < q->val) ? lowestCommonAncestorDfs(root->right, p, q) : root;
}

BinaryTreeNode *BinarySearchTree::lowestCommonAncestorBfs(BinaryTreeNode *root,
                                                          BinaryTreeNode *p,
                                                          BinaryTreeNode *q) {
    while (root) {
        if (p->val < root->val && q->val < root->val) root = root->left;
        else if (root->val < p->val && root->val < q->val) root = root->right;
        else return root;
    }
    return root;
}

}  // namespace dsa::lib::trees