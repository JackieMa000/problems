#include "nodes.h"

#include "lib/trees.cpp"

using namespace nodes;
using namespace lib;

class Solution1
{
public:
    bool isValidBST(BinaryTreeNode *root)
    {
        BinarySearchTree bst(root);
        return bst.isValid();
    }
};

//inorder traversal.
//inorder Rule: left(all nodes) < root < right(all nodes), or prev < cur.
class Scratch1
{
public:
    bool isValidBST(BinaryTreeNode *root)
    {
        BinaryTreeNode *prev = nullptr;
        return isValid(root, prev);
    }

private:
    bool isValid(BinaryTreeNode *root, BinaryTreeNode *&prev)
    {
        // Terminator
        if (!root)
            return true;

        // Left Tree. Recursive case
        if (!isValid(root->left, prev))
            return false;

        // Root. Process or Logic, Action.
        if (prev && prev->val >= root->val)
            return false;

        // Right Tree. Recursive case
        prev = root;
        return isValid(root->right, prev);
    }
};