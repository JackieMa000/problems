#include "dsa/nodes.h"
#include "tree.h"

#ifndef LIB_TREES_BT_H
#define LIB_TREES_BT_H

namespace dsa::lib::trees {

class BinaryTree : Tree
{
private:
    void
    destroy(nodes::BinaryTreeNode* root);
    static nodes::BinaryTreeNode*
    lowestCommonAncestorDfs(nodes::BinaryTreeNode* root, nodes::BinaryTreeNode* p, nodes::BinaryTreeNode* q);

protected:
    nodes::BinaryTreeNode* root;

public:
    BinaryTree(nodes::BinaryTreeNode* root);
    virtual ~BinaryTree();

    int*
    toArray();
    int
    depth();
    virtual nodes::BinaryTreeNode*
    lowestCommonAncestor(nodes::BinaryTreeNode* p, nodes::BinaryTreeNode* q);
};

}  // namespace dsa::lib::trees

#endif