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

std::tuple<length_t, int *> BinaryTree::toArray() {
    length_t length = getArraySizeForBinaryTree(root);
    int *ary = new int[length];
    for (int i = 0; i < length; ++i) *(ary + i) = 0;

    generateArrayFromTree(root, 0, ary, length);
    return {(utils::arrayRstrip(ary, length)), ary};
}
void BinaryTree::generateArrayFromTree(nodes::BinaryTreeNode *root, pos_t i, int *ary, length_t length) {
    if (!root || i >= length) return;
    *(ary + i) = root->val;
    generateArrayFromTree(root->left, 2 * i + 1, ary, length);
    generateArrayFromTree(root->right, 2 * i + 2, ary, length);
}

length_t BinaryTree::getArraySizeForBinaryTree(nodes::BinaryTreeNode *root) {
    BinaryTree bt(root);
    return (length_t) (pow(2, bt.depth()) - 1);
}

depth_t BinaryTree::depth() {
    return depthDfs(this->root);
}
depth_t BinaryTree::depthDfs(nodes::BinaryTreeNode *root) {
    return (!root) ? 0 : (1 + std::max(depthDfs(root->left), depthDfs(root->right)));
}

}  // namespace dsa::lib::trees