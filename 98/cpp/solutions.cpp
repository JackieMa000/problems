#include "nodes.h"

using namespace nodes;

// LowerBound and UpperBound.
// BST Rule:
// left(all nodes) < root < right(all nodes)
// Biggest on the left < root < smallest on the right
class Solution1
{
public:
    bool isValidBST(BinaryTreeNode *root) {
        return isValid(root, nullptr, nullptr);
    }

private:
    bool isValid(BinaryTreeNode *root, BinaryTreeNode *minNode, BinaryTreeNode *maxNode) {
        // Terminator
        if (!root) return true;

        //Lower Bound
        if (minNode && root->val <= minNode->val) return false;

        //Upper Bound
        if (maxNode && root->val >= maxNode->val) return false;

        // Recursive case
        return isValid(root->left, minNode, root) && isValid(root->right, root, maxNode);
    }
};

//inorder traversal.
//inorder Rule: left(all nodes) < root < right(all nodes), or prev < cur.
class Scratch1
{
public:
    bool isValidBST(BinaryTreeNode *root) {
        BinaryTreeNode *prev = nullptr;
        return isValid(root, prev);
    }

private:
    bool isValid(BinaryTreeNode *root, BinaryTreeNode *&prev) {
        // Terminator
        if (!root) return true;

        // Left Tree. Recursive case
        if (!isValid(root->left, prev)) return false;

        // Root. Process or Logic, Action.
        if (prev && prev->val >= root->val) return false;

        // Right Tree. Recursive case
        prev = root;
        return isValid(root->right, prev);
    }
};