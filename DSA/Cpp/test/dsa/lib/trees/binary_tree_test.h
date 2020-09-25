#ifndef DSA_TEST_DSA_LIB_TREES_BINARY_TREE_TEST_H_
#define DSA_TEST_DSA_LIB_TREES_BINARY_TREE_TEST_H_

#include <dsa/lib/arrays/array.h>
#include "tree_test.h"

namespace dsa::lib::trees {

class BinaryTreeTest : public TreeTest {};

class ToArrayTest : public BinaryTreeTest {
 protected:
    inline static BinaryTreeNode *generateTreeFromArray(int *ary, length_t length) {
        lists::arrays::Array array(ary, length);
        return array.toBinaryTree();
    }
    inline static std::tuple<length_t, int *> toArray(BinaryTreeNode *root) {
        BinaryTree bt(root);
        return bt.toArray();
    }
    inline static void run(int ary[], length_t length) {
        BinaryTreeNode *root = generateTreeFromArray(ary, length);
        auto[actLen, actAry] = toArray(root);
        EXPECT_ARRAY_EQ(ary, length, actAry, actLen);

        BinaryTree::destroy(root);
        delete[] actAry;
    }
};

class DepthTest : public BinaryTreeTest {
 protected:
    static depth_t getTreeDepth(BinaryTreeNode *root) {
        BinaryTree bt(root);
        return bt.depth();
    }

    static BinaryTreeNode *generateTreeFromArray(int *ary, length_t length) {
        lists::arrays::Array array(ary, length);
        return array.toBinaryTree();
    }
};

class GetArraySizeForBinaryTree : public BinaryTreeTest {
 protected:
    static length_t act(int *ary, length_t length) {
        lists::arrays::Array array(ary, length);
        return BinaryTree::getArraySizeForBinaryTree(array.toBinaryTree());
    }
};

}

#endif //DSA_TEST_DSA_LIB_TREES_BINARY_TREE_TEST_H_
