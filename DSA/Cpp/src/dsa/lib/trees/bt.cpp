#include "bt.h"

namespace dsa::lib::trees {

BinaryTree::BinaryTree(nodes::BinaryTreeNode* root)
{
    this->root = root;
}
BinaryTree::~BinaryTree()
{
    destroy(root);
};
void
BinaryTree::destroy(nodes::BinaryTreeNode* root)
{
    if (!root)
        return;
    if (root->left)
        destroy(root->left);
    if (root->right)
        destroy(root->right);
    delete root;
};

nodes::BinaryTreeNode*
BinaryTree::lowestCommonAncestor(nodes::BinaryTreeNode* p, nodes::BinaryTreeNode* q)
{
    return lowestCommonAncestorDfs(this->root, p, q);
}
nodes::BinaryTreeNode*
BinaryTree::lowestCommonAncestorDfs(nodes::BinaryTreeNode* root, nodes::BinaryTreeNode* p, nodes::BinaryTreeNode* q)
{
    if (!root || p == root || q == root)
        return root;

    nodes::BinaryTreeNode* left = lowestCommonAncestorDfs(root->left, p, q);
    nodes::BinaryTreeNode* right = lowestCommonAncestorDfs(root->right, p, q);

    return (left && right) ? root : !left ? right : left;
}

}  // namespace dsa::lib::trees