#include "nodes.h"
#include "lib/trees.h"

lib::BinaryTree::BinaryTree(nodes::BinaryTreeNode *root) { this->root = root; }
lib::BinaryTree::~BinaryTree() { destroy(root); };
void lib::BinaryTree::destroy(nodes::BinaryTreeNode *root)
{
    if (!root)
        return;
    if (root->left)
        destroy(root->left);
    if (root->right)
        destroy(root->right);
    delete root;
};

nodes::BinaryTreeNode *lib::BinaryTree::lowestCommonAncestor(nodes::BinaryTreeNode *p, nodes::BinaryTreeNode *q) {
    return lowestCommonAncestorDfs(this->root, p, q);
}
nodes::BinaryTreeNode *lib::BinaryTree::lowestCommonAncestorDfs(nodes::BinaryTreeNode *root, 
nodes::BinaryTreeNode *p, nodes::BinaryTreeNode *q) {
    if (!root || p == root || q == root) return root;

    nodes::BinaryTreeNode *left = lowestCommonAncestorDfs(root->left, p, q);
    nodes::BinaryTreeNode *right = lowestCommonAncestorDfs(root->right, p, q);

    return (left && right) ? root : !left ? right : left;
}

lib::BinarySearchTree::BinarySearchTree(nodes::BinaryTreeNode *root) : BinaryTree(root) {}

std::vector<int> lib::BinarySearchTree::preorder()
{
    std::vector<int> lst;
    return preorderDfs(this->root, lst);
}
std::vector<int> lib::BinarySearchTree::preorderDfs(nodes::BinaryTreeNode *root, std::vector<int> lst)
{
    if (root)
    {
        lst.push_back(root->val);
        preorderDfs(root->left, lst);
        preorderDfs(root->right, lst);
    }
    return lst;
}

std::vector<int> *lib::BinarySearchTree::inorder()
{
    std::vector<int> *lst;
    lst = new std::vector<int>();
    return inorderDfs(this->root, lst);
}
std::vector<int> *lib::BinarySearchTree::inorderDfs(nodes::BinaryTreeNode *root, std::vector<int> *lst)
{
    if (root)
    {
        inorderDfs(root->left, lst);
        lst->push_back(root->val);
        inorderDfs(root->right, lst);
    }
    return lst;
}

std::vector<int> &lib::BinarySearchTree::postorder()
{
    std::vector<int> lst;
    return postorderDfs(this->root, lst);
}
std::vector<int> &lib::BinarySearchTree::postorderDfs(nodes::BinaryTreeNode *root, std::vector<int> &lst)
{
    if (root)
    {
        postorderDfs(root->left, lst);
        postorderDfs(root->right, lst);
        lst.push_back(root->val);
    }
    return lst;
}

bool lib::BinarySearchTree::isValid()
{
    return isValidBST(this->root, nullptr, nullptr);
}
/*
 LowerBound and UpperBound.
BST Rule:
 left(all nodes) < root < right(all nodes)
 Biggest on the left < root < smallest on the right
*/
bool lib::BinarySearchTree::isValidBST(nodes::BinaryTreeNode *root, nodes::BinaryTreeNode *minNode,
                                       nodes::BinaryTreeNode *maxNode)
{
    if (!root)
        return true;

    //Biggest on the left, Upper Bound
    if (maxNode && root->val >= maxNode->val)
        return false;

    // Smallest on the right, Lower Bound
    if (minNode && root->val <= minNode->val)
        return false;

    return isValidBST(root->left, minNode, root) && isValidBST(root->right, root, maxNode);
}