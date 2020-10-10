#ifndef DSA_TEST_DSA_LIB_LIB_TEST_H_
#define DSA_TEST_DSA_LIB_LIB_TEST_H_

#include <dsa/testing/testing.h>
#include <dsa/lib/arrays/array.h>

namespace dsa::lib {

class LibTest : public testing::DSATest {
 protected:
    [[nodiscard]] static BinaryTreeNode *arrayToBinaryTree(int *ary, length_t length) {
        arrays::Array array(ary, length);
        return array.toBinaryTree();
    }
};

}
#endif //DSA_TEST_DSA_LIB_LIB_TEST_H_
