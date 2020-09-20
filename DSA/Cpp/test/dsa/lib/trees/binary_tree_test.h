#ifndef DSA_TEST_DSA_LIB_TREES_BINARY_TREE_TEST_H_
#define DSA_TEST_DSA_LIB_TREES_BINARY_TREE_TEST_H_

#include "tree_test.h"

namespace dsa::lib::trees {

class BinaryTreeTest : public TreeTest {};
class ToArrayTest : public BinaryTreeTest {};

class DepthTest : public BinaryTreeTest {
 public:
    static unsigned int getTreeDepth(nodes::BinaryTreeNode *root) {
        BinaryTree bt(root);
        return bt.depth();
    }

    static nodes::BinaryTreeNode *generateTreeFromArray(int *ary, unsigned long size) {
        lists::arrays::Array array(ary, size);
        return array.toBinaryTree();
    }
};

}

#endif //DSA_TEST_DSA_LIB_TREES_BINARY_TREE_TEST_H_
