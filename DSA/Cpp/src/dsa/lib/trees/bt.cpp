#include <dsa/lib/utils.h>
#include <algorithm>
#include <cmath>
#include "bt.h"

namespace dsa::lib::trees {

BinaryTree::BinaryTree(nodes::BinaryTreeNode *root) : root(root) {}
void BinaryTree::destroy(nodes::BinaryTreeNode *root) {
    if (!root) return;
    if (root->left) destroy(root->left);
    if (root->right) destroy(root->right);
    delete root;
}

nodes::BinaryTreeNode *BinaryTree::lowestCommonAncestor(nodes::BinaryTreeNode *p, nodes::BinaryTreeNode *q) {
    return lowestCommonAncestorDfs(this->root, p, q);
}
nodes::BinaryTreeNode *BinaryTree::lowestCommonAncestorDfs(nodes::BinaryTreeNode *root,
                                                           nodes::BinaryTreeNode *p,
                                                           nodes::BinaryTreeNode *q) {
    if (!root || p == root || q == root) return root;
    nodes::BinaryTreeNode *left = lowestCommonAncestorDfs(root->left, p, q);
    nodes::BinaryTreeNode *right = lowestCommonAncestorDfs(root->right, p, q);

    return (left && right) ? root : !left ? right : left;
}

std::tuple<unsigned int, int *> BinaryTree::toArray() {
//    ToDo
//    return std::tuple<unsigned int, int *>();

    unsigned int arySize = getArraySizeForBinaryTree(this->root);
    int ary[arySize];
    generateArrayFromTree(this->root, 0, ary, arySize);
    return utils::arrayRstrip(ary, 0);
}
unsigned int BinaryTree::getArraySizeForBinaryTree(nodes::BinaryTreeNode *root) {
//    ToDo
//    return 0;

    BinaryTree bt(root);
    return (int) pow(2, bt.depth()) - 1;
}
void BinaryTree::generateArrayFromTree(nodes::BinaryTreeNode *root, int i, int *ary, unsigned int length) {
//    ToDo
}
unsigned int BinaryTree::depth() {
    return depthDfs(this->root);
}
unsigned int BinaryTree::depthDfs(nodes::BinaryTreeNode *root) {
    return (!root) ? 0 : (1 + std::max(depthDfs(root->left), depthDfs(root->right)));
}

}  // namespace dsa::lib::trees