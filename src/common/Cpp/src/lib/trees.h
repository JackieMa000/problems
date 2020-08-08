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

    class BinaryTree : public Tree
    {
    private:
        const nodes::BinaryTreeNode *root;

        void destroy(const nodes::BinaryTreeNode *root);

    public:
        BinaryTree(nodes::BinaryTreeNode *root);
        ~BinaryTree();

        int *toArray();
        int depth();
    };

} // namespace lib

#endif