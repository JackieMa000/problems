#include <vector>

#include "dsa/nodes.h"
#include "bt.h"

#ifndef LIB_TREES_BST_H
#define LIB_TREES_BST_H

namespace dsa {
namespace lib {
namespace trees {

class BinarySearchTree : BinaryTree
{
private:
    static std::vector<int>
    preorderDfs(nodes::BinaryTreeNode* root, std::vector<int> lst);
    static std::vector<int>*
    inorderDfs(nodes::BinaryTreeNode* root, std::vector<int>* lst);
    static std::vector<int>&
    postorderDfs(nodes::BinaryTreeNode* root, std::vector<int>& lst);

    static bool
    isValidBST(nodes::BinaryTreeNode* root, nodes::BinaryTreeNode* minNode, nodes::BinaryTreeNode* maxNode);

    static nodes::BinaryTreeNode*
    lowestCommonAncestorDfs(nodes::BinaryTreeNode* root, nodes::BinaryTreeNode* p, nodes::BinaryTreeNode* q);

    static nodes::BinaryTreeNode*
    lowestCommonAncestorBfs(nodes::BinaryTreeNode* root, nodes::BinaryTreeNode* p, nodes::BinaryTreeNode* q);

public:
    BinarySearchTree(nodes::BinaryTreeNode* root);
    ~BinarySearchTree();

    std::vector<int>
    preorder();
    std::vector<int>*
    inorder();
    std::vector<int>&
    postorder();

    bool
    isValid();

    nodes::BinaryTreeNode*
    lowestCommonAncestor(nodes::BinaryTreeNode* p, nodes::BinaryTreeNode* q);
};

}  // namespace trees
}  // namespace lib
}  // namespace dsa

#endif