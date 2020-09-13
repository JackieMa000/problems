#include "dsa/nodes.h"
#include "tree.h"

#ifndef LIB_TREES_BT_H
#define LIB_TREES_BT_H

namespace dsa {
namespace lib {
namespace trees {

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
    nodes::BinaryTreeNode*
    lowestCommonAncestor(nodes::BinaryTreeNode* p, nodes::BinaryTreeNode* q);
};

}  // namespace trees
}  // namespace lib
}  // namespace dsa

#endif