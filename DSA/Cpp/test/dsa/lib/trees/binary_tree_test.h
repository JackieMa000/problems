#ifndef DSA_TEST_DSA_LIB_TREES_BINARY_TREE_TEST_H_
#define DSA_TEST_DSA_LIB_TREES_BINARY_TREE_TEST_H_

#include <dsa/lib/arrays/array.h>
#include "tree_test.h"

namespace dsa::lib::trees {

class BinaryTreeTest : public TreeTest {
 protected:
    [[nodiscard]] static BinaryTreeNode *arrayToTree(int *ary, length_t length) {
        arrays::Array array(ary, length);
        return array.toBinaryTree();
    }
};

}

#endif //DSA_TEST_DSA_LIB_TREES_BINARY_TREE_TEST_H_
