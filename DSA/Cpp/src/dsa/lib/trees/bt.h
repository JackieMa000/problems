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
    static void generateArrayFromTree(nodes::BinaryTreeNode *root, pos_t i, int *ary, length_t length);
    static depth_t depthDfs(nodes::BinaryTreeNode *root);

 protected:
    nodes::BinaryTreeNode *root;

 public:
    explicit BinaryTree(nodes::BinaryTreeNode *root);

    static void destroy(nodes::BinaryTreeNode *root);

    std::tuple<length_t, int *> toArray() override;
    depth_t depth() override;
    virtual nodes::BinaryTreeNode *lowestCommonAncestor(nodes::BinaryTreeNode *p, nodes::BinaryTreeNode *q);
    static length_t getArraySizeForBinaryTree(nodes::BinaryTreeNode *root);
};

}  // namespace dsa::lib::trees

#endif