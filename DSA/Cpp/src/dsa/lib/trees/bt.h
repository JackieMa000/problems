#ifndef LIB_TREES_BT_H
#define LIB_TREES_BT_H

#include <vector>
#include "tree.h"

namespace dsa::lib::trees {

class BinaryTree : public Tree {
 private:
    static BinaryTreeNode *lowestCommonAncestorDfs(BinaryTreeNode *root, BinaryTreeNode *p, BinaryTreeNode *q);
    static void generateArrayFromTree(BinaryTreeNode *root, pos_t i, int *ary, length_t length);
    static depth_t depthDfs(BinaryTreeNode *root);
    static BinaryTreeNode *getTreeNodeByIdxBfs(BinaryTreeNode *root, pos_t idx);
    static BinaryTreeNode *getNodeByValBfs(BinaryTreeNode *root, int val);
    static BinaryTreeNode *getNodeByValBfs1(BinaryTreeNode *root, int val);
    static BinaryTreeNode *getNodeByValDfs(BinaryTreeNode *root, int val);

    static std::vector<int> preorderDfs1(BinaryTreeNode *root, std::vector<int> lst);
    static void preorderDfs(BinaryTreeNode *root, std::vector<int> &lst);
    static void inorderDfs(BinaryTreeNode *root, std::vector<int> &lst);
    static void postorderDfs(BinaryTreeNode *root, std::vector<int> &lst);

 protected:
    BinaryTreeNode *root;

 public:
    explicit BinaryTree(BinaryTreeNode *root);

    static void destroy(BinaryTreeNode *root);
    static length_t getArraySizeForBinaryTree(BinaryTreeNode *root);

    array_s toArray() override;
    depth_t depth() override;
    BinaryTreeNode *getNodeByIndex(pos_t idx) override;
    BinaryTreeNode *getNodeByValue(int val) override;

//    LeetCode236
    virtual BinaryTreeNode *lowestCommonAncestor(BinaryTreeNode *p, BinaryTreeNode *q);
//    LeetCode144
    std::vector<int> preorderTraversal();
//    LeetCode94
    std::vector<int> inorderTraversal();
//    LeetCode145
    std::vector<int> postorderTraversal();
};

}  // namespace dsa::lib::trees

#endif