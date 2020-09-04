#include "nodes.h"
#include "lib/trees.h"

using namespace dsa::nodes;
using namespace dsa::lib;

class Solution1
{
public:
    BinaryTreeNode *lowestCommonAncestor(BinarySearchTree root, BinaryTreeNode *p, BinaryTreeNode *q)
    {
        BinarySearchTree *bst;
        bst = new BinarySearchTree(root);
        return bst->lowestCommonAncestor(p, q);
    }
};