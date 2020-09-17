#ifndef LIB_TREES_BT_H
#define LIB_TREES_BT_H

#include <tuple>
#include "dsa/nodes.h"
#include "tree.h"

namespace dsa::lib::trees {

class BinaryTree : Tree {
 private:
    static nodes::BinaryTreeNode *lowestCommonAncestorDfs(nodes::BinaryTreeNode *root,
                                                          nodes::BinaryTreeNode *p,
                                                          nodes::BinaryTreeNode *q);

 protected:
    nodes::BinaryTreeNode *root;

 public:
    explicit BinaryTree(nodes::BinaryTreeNode *root);

    static void destroy(nodes::BinaryTreeNode *root);

    std::tuple<unsigned int, int *> toArray() override;
    int depth() override;
    virtual nodes::BinaryTreeNode *lowestCommonAncestor(nodes::BinaryTreeNode *p, nodes::BinaryTreeNode *q);
};

}  // namespace dsa::lib::trees

#endif