#include <dsa/lib/utils/utils.h>
#include <queue>
#include "bt.h"

namespace dsa::lib::trees {

BinaryTree::BinaryTree(BinaryTreeNode *root) : root(root) {}
void BinaryTree::destroy(BinaryTreeNode *root) {
    if (!root) return;
    if (root->left) destroy(root->left);
    if (root->right) destroy(root->right);
    delete root;
}

BinaryTreeNode *BinaryTree::lowestCommonAncestor(BinaryTreeNode *p, BinaryTreeNode *q) {
    return lowestCommonAncestorDfs(this->root, p, q);
}
BinaryTreeNode *BinaryTree::lowestCommonAncestorDfs(BinaryTreeNode *root, BinaryTreeNode *p, BinaryTreeNode *q) {
    if (!root || p == root || q == root) return root;
    BinaryTreeNode *left = lowestCommonAncestorDfs(root->left, p, q);
    BinaryTreeNode *right = lowestCommonAncestorDfs(root->right, p, q);

    return (left && right) ? root : !left ? right : left;
}

arrayStruct BinaryTree::toArray() {
    arrayStruct as{0, nullptr};
    if (this->root) {
        length_t length = getArraySizeForBinaryTree(root);
        int *ary = new int[length];
        for (int i = 0; i < length; ++i) *(ary + i) = 0;

        generateArrayFromTree(root, 0, ary, length);
        as = {utils::arrayRstrip(ary, length), ary};
    }
    return as;
}
void BinaryTree::generateArrayFromTree(BinaryTreeNode *root, pos_t i, int *ary, length_t length) {
    if (!root || i >= length) return;
    *(ary + i) = root->val;
    generateArrayFromTree(root->left, 2 * i + 1, ary, length);
    generateArrayFromTree(root->right, 2 * i + 2, ary, length);
}

length_t BinaryTree::getArraySizeForBinaryTree(BinaryTreeNode *root) {
    BinaryTree bt(root);
    return (length_t) (pow(2, bt.depth()) - 1);
}

depth_t BinaryTree::depth() {
    return depthDfs(this->root);
}
depth_t BinaryTree::depthDfs(BinaryTreeNode *root) {
    return (!root) ? 0 : (1 + std::max(depthDfs(root->left), depthDfs(root->right)));
}

BinaryTreeNode *BinaryTree::getNodeByIndex(pos_t idx) {
    return getTreeNodeByIdxBfs(this->root, idx);
}
BinaryTreeNode *BinaryTree::getTreeNodeByIdxBfs(BinaryTreeNode *root, pos_t idx) {
    std::queue<BinaryTreeNode *> queue;
    if (root) { queue.push(root); }

    int count = 0;
    while (!queue.empty()) {
        root = queue.front();
        queue.pop();
        if (++count - 1 == idx) { return root; }

        if (!root) { continue; }
        queue.push(root->left);
        queue.push(root->right);
    }

    return nullptr;
}
BinaryTreeNode *BinaryTree::getNodeByValue(int val) {
    return getNodeByValDfs(this->root, val);
}
BinaryTreeNode *BinaryTree::getNodeByValBfs(BinaryTreeNode *root, int val) {
    std::queue<BinaryTreeNode *> queue;
    if (root) { queue.push(root); }
    while (!queue.empty()) {
        root = queue.front();
        queue.pop();
        if (root->val == val) { return root; }

        if (root->left) { queue.push(root->left); }
        if (root->right) { queue.push(root->right); }
    }

    return nullptr;
}
BinaryTreeNode *BinaryTree::getNodeByValBfs1(BinaryTreeNode *root, int val) {
    std::queue<BinaryTreeNode *> queue;
    if (root) { queue.push(root); }
    while (!queue.empty()) {
        root = queue.front();
        queue.pop();
        if (!root) { continue; }
        if (root->val == val) { return root; }

        queue.push(root->left);
        queue.push(root->right);
    }

    return nullptr;
}
BinaryTreeNode *BinaryTree::getNodeByValDfs(BinaryTreeNode *root, int val) {
    if (!root) { return nullptr; }
    if (root->val == val) { return root; }

    BinaryTreeNode *left = getNodeByValDfs(root->left, val);
    BinaryTreeNode *right = getNodeByValDfs(root->right, val);
    return left ? left : right;
}

}  // namespace dsa::lib::trees