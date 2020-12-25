#ifndef LIB_TREES_BT_H
#define LIB_TREES_BT_H

#include "tree.h"

namespace dsa::lib::trees {

class BinaryTree : public Tree {
 private:
    static BinaryTreeNode *lowestCommonAncestorDfs(BinaryTreeNode *root,
                                                   BinaryTreeNode *p,
                                                   BinaryTreeNode *q);
    static void generateArrayFromTree(BinaryTreeNode *root, pos_t i, int *ary, length_t length);
    static depth_t depthDfs(BinaryTreeNode *root);
    static BinaryTreeNode *getTreeNodeByIdxBfs(BinaryTreeNode *root, pos_t idx);
    static BinaryTreeNode *getNodeByValBfs(BinaryTreeNode *root, int val);
    static BinaryTreeNode *getNodeByValBfs1(BinaryTreeNode *root, int val);
    static BinaryTreeNode *getNodeByValDfs(BinaryTreeNode *root, int val);

 protected:
    BinaryTreeNode *root;

 public:
    explicit BinaryTree(BinaryTreeNode *root);

    static void destroy(BinaryTreeNode *root);

    arrayStruct toArray() override;
    depth_t depth() override;
    BinaryTreeNode *getNodeByIndex(pos_t idx) override;
    BinaryTreeNode *getNodeByValue(int val) override;

    virtual BinaryTreeNode *lowestCommonAncestor(BinaryTreeNode *p, BinaryTreeNode *q);
    static length_t getArraySizeForBinaryTree(BinaryTreeNode *root);
};

}  // namespace dsa::lib::trees

#endif