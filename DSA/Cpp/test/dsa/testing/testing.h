#ifndef DSA_TESTING_H
#define DSA_TESTING_H

#include <gtest/gtest.h>
#include <dsa/dsadef.h>
#include "dsa/nodes/nodes.h"

namespace dsa::testing {

class DSATest : public ::testing::Test {
 protected:
    static void EXPECT_ARRAY_EQ(int *expected, length_t expectedLength, int *actual, length_t actualLength);
    static void EXPECT_ARRAY_EQ_LINKEDLIST(int *ary, length_t length, nodes::ListNode *head);
    static void EXPECT_ARRAY_EQ_TREE(int *ary, length_t length, nodes::BinaryTreeNode *root);

 private:
    static void expectArrayEQTreeDfs(int *ary, length_t length, nodes::BinaryTreeNode *root, pos_t i);
    static void expectArrayEQDfs(const int *expected,
                                 length_t expectedLength,
                                 const int *actual,
                                 length_t actualLength);
    static void EXPECT_ARRAY_EQ(const array_s &expected, const array_s &actual);
};

}  // namespace dsa::testing

#endif  // TESTING_H