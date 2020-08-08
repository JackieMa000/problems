#include "nodes.h"
#include "lib/trees.h"

lib::BinaryTree::BinaryTree(nodes::BinaryTreeNode *root) { this->root = root; }

void lib::BinaryTree::destroy(const nodes::BinaryTreeNode *root)
{
    if (!root)
        return;
    if (root->left)
        destroy(root->left);
    if (root->right)
        destroy(root->right);
    delete root;
};

lib::BinaryTree::~BinaryTree() { destroy(root); };