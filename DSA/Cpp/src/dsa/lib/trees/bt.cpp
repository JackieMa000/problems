#include <queue>
#include <cmath>

#include <dsa/lib/utils.hpp>
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
/**
 * Binary Tree LCA Rule:
 * lca(root, p, q): find the lca in the tree.
 * 1. root is null -> null
 * 2. p or q is root -> root
 * 3. p is on the left/right subtree, and q is on the right/left subtree, respectively -> root
 * 4. p and q both are on the left/right subtree, means lca is on the left/right, return left/right respectively.
 */
BinaryTreeNode *BinaryTree::lowestCommonAncestorDfs(BinaryTreeNode *root, BinaryTreeNode *p, BinaryTreeNode *q) {
    if (!root || root == p || root == q) { return root; }

    BinaryTreeNode *left = lowestCommonAncestorDfs(root->left, p, q);
    BinaryTreeNode *right = lowestCommonAncestorDfs(root->right, p, q);
    return (left && right) ? root : !left ? right : left;
}

array_s BinaryTree::toArray() {
    array_s as{nullptr, 0};
    if (this->root) {
        length_t length = getArraySizeForBinaryTree(root);
        int *ary = new int[length];
        for (int i = 0; i < length; ++i) *(ary + i) = 0;

        generateArrayFromTree(root, 0, ary, length);
        as = {ary, utils::arrayRstrip(ary, length)};
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

std::vector<int> BinaryTree::preorderTraversal() {
    std::vector<int> lst;
    preorderDfs(this->root, lst);
    return lst;
}
void BinaryTree::preorderDfs(BinaryTreeNode *root, std::vector<int> &lst) {
    if (root) {
        lst.push_back(root->val);
        preorderDfs(root->left, lst);
        preorderDfs(root->right, lst);
    }
}
std::vector<int> BinaryTree::preorderDfs1(BinaryTreeNode *root, std::vector<int> lst) {
    if (root) {
        lst.push_back(root->val);
        lst = preorderDfs1(root->left, lst);
        lst = preorderDfs1(root->right, lst);
    }
    return lst;
}
std::vector<int> BinaryTree::inorderTraversal() {
    std::vector<int> lst;
    inorderDfs(this->root, lst);
    return lst;
}
void BinaryTree::inorderDfs(BinaryTreeNode *root, std::vector<int> &lst) {
    if (root) {
        inorderDfs(root->left, lst);
        lst.push_back(root->val);
        inorderDfs(root->right, lst);
    }
}
std::vector<int> BinaryTree::postorderTraversal() {
    std::vector<int> lst;
    postorderDfs(this->root, lst);
    return lst;
}
void BinaryTree::postorderDfs(BinaryTreeNode *root, std::vector<int> &lst) {
    if (root) {
        postorderDfs(root->left, lst);
        postorderDfs(root->right, lst);
        lst.push_back(root->val);
    }
}
std::vector<std::vector<int>> BinaryTree::levelOrder() {
//    return levelOrderBfs(root);
    std::vector<std::vector<int>> result = std::vector<std::vector<int>>();
    levelOrderDfs(this->root, 0, result);
    return result;
}
/**
 * Rule: BFS
 * queue -> currentLevelResult -> Result
 * currentLevelResult: saving the node values for the current level, 1D-array
 * Result: saving the final result for all the levels, 2D-array
 * queue: for BFS traversing the tree by level,
 *  consuming the nodes for the current level, producing the children nodes for next level
 *  Loop for the current level, do the logic(saving the node values to the currentLevelResult), produce for the next level
 * Loop on the whole tree:
 *  Loop on the level:
 *      ....
 *
 */
std::vector<std::vector<int>> BinaryTree::levelOrderBfs(BinaryTreeNode *root) {
    std::vector<std::vector<int>> result;

    if (root) {
        std::queue<BinaryTreeNode *> queue;
        queue.push(root);
        while (!queue.empty()) {
            std::vector<int> levelResult;
            int levelSize = queue.size();
            for (int i = 0; i < levelSize; ++i) {
                root = queue.front();
                queue.pop();

                levelResult.push_back(root->val);

                if (root->left) { queue.push(root->left); }
                if (root->right) { queue.push(root->right); }
            }
            result.push_back(levelResult);
        }
    }

    return result;
}
/**
 * Rule: DFS
 * currentLevelResult -> Result
 * saving the current level node values to the currentLevelResult.
 * get the currentLevelResult by the level number parameter from Result
 * generate the currentLevelResult when it does not exist in the result.
 */
void BinaryTree::levelOrderDfs(BinaryTreeNode *root, int level, std::vector<std::vector<int>> &result) {
    if (root) {
        if (result.size() < level + 1) { result.emplace_back(); }
        result[level].push_back(root->val);
        levelOrderDfs(root->left, level + 1, result);
        levelOrderDfs(root->right, level + 1, result);
    }
}

}  // namespace dsa::lib::trees
