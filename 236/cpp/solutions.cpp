#include "lib/trees.h"
#include "nodes.h"

using lib::BinaryTree;
using dsa::nodes::BinaryTreeNode;

class Solution
{
public:
    BinaryTreeNode *lowestCommonAncestor(BinaryTreeNode *root, BinaryTreeNode *p, BinaryTreeNode *q)
    {
        BinaryTree *bt;
        bt = new BinaryTree(root);
        return bt->lowestCommonAncestor(p, q);
    }
};