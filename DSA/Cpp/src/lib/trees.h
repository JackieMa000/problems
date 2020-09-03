#include <vector>

#include "nodes.h"

#ifndef LIB_TREES_H
#define LIB_TREES_H

namespace lib
{
    class Tree
    {
    public:
        virtual int *toArray() = 0;
        virtual int depth() = 0;
    };

    class BinaryTree : Tree
    {
    protected:
        dsa::nodes::BinaryTreeNode *root;

    private:
        void destroy(dsa::nodes::BinaryTreeNode *root);
        static dsa::nodes::BinaryTreeNode *lowestCommonAncestorDfs(dsa::nodes::BinaryTreeNode *root, 
        dsa::nodes::BinaryTreeNode *p, dsa::nodes::BinaryTreeNode *q);

    public:
        BinaryTree(dsa::nodes::BinaryTreeNode *root);
        virtual ~BinaryTree();

        int *toArray();
        int depth();
        dsa::nodes::BinaryTreeNode *lowestCommonAncestor(dsa::nodes::BinaryTreeNode *p, dsa::nodes::BinaryTreeNode *q);
    };

    class BinarySearchTree : BinaryTree
    {
    private:
        static std::vector<int> preorderDfs(dsa::nodes::BinaryTreeNode *root, std::vector<int> lst);
        static std::vector<int> *inorderDfs(dsa::nodes::BinaryTreeNode *root, std::vector<int> *lst);
        static std::vector<int> &postorderDfs(dsa::nodes::BinaryTreeNode *root, std::vector<int> &lst);

        static bool isValidBST(dsa::nodes::BinaryTreeNode *root, dsa::nodes::BinaryTreeNode *minNode,
                               dsa::nodes::BinaryTreeNode *maxNode);

    public:
        BinarySearchTree(dsa::nodes::BinaryTreeNode *root);
        ~BinarySearchTree();

        std::vector<int> preorder();
        std::vector<int> *inorder();
        std::vector<int> &postorder();

        bool isValid();
    };

} // namespace lib

#endif