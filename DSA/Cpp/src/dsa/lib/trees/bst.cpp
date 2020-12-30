#include "bst.h"
#include "bt.h"

namespace dsa::lib::trees {

BinarySearchTree::BinarySearchTree(BinaryTreeNode *root) : BinaryTree(root) {}

bool BinarySearchTree::isValid() {
    return isValidBST(this->root, nullptr, nullptr);
}

/**
 *LowerBound and UpperBound.
 * Rule:
 * left(all nodes) < root < right(all nodes)
 * Biggest on the left(upperBound) < root < smallest on the right(lowerBound)
 */
bool BinarySearchTree::isValidBST(BinaryTreeNode *root, BinaryTreeNode *minNode, BinaryTreeNode *maxNode) {
    if (!root) return true;

    // Left subTree, Upper Bound
    if (maxNode && root->val >= maxNode->val) return false;

    // Right subTree, Lower Bound
    if (minNode && root->val <= minNode->val) return false;

    return isValidBST(root->left, minNode, root) && isValidBST(root->right, root, maxNode);
}

/**
 * BST LCA Rule:
 * lca(root, p, q): find lca of p and q in the tree.
 * 1. if p < root < q or q < root < p -> root
 * 2. if p < root and q < root -> lca is on the left
 * 3. if root < p and root < q -> lca is on the right
 */
BinaryTreeNode *BinarySearchTree::lowestCommonAncestor(BinaryTreeNode *p, BinaryTreeNode *q) {
    return lowestCommonAncestorBfs(this->root, p, q);
}

BinaryTreeNode *BinarySearchTree::lowestCommonAncestorDfs(BinaryTreeNode *root, BinaryTreeNode *p, BinaryTreeNode *q) {
    return (root->val > p->val && root->val > q->val) ? lowestCommonAncestorDfs(root->left, p, q) :
           (root->val < p->val && root->val < q->val) ? lowestCommonAncestorDfs(root->right, p, q) : root;
}

BinaryTreeNode *BinarySearchTree::lowestCommonAncestorBfs(BinaryTreeNode *root, BinaryTreeNode *p, BinaryTreeNode *q) {
    while (root) {
        if (root->val > p->val && root->val > q->val) {
            root = root->left;
        } else if (root->val < p->val && root->val < q->val) {
            root = root->right;
        } else {
            break;
        }
    }
    return root;
}

}  // namespace dsa::lib::trees