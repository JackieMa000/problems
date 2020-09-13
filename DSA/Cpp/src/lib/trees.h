#include <vector>
#include "nodes.h"

#ifndef LIB_TREES_H
#define LIB_TREES_H

namespace dsa {
namespace lib {
class Tree
{
public:
    virtual int*
    toArray() = 0;
    virtual int
    depth() = 0;
};

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

}  // namespace lib
}  // namespace dsa

#endif