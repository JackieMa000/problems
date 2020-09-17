#ifndef TESTING_H
#define TESTING_H

#include <gtest/gtest.h>
#include "dsa/nodes.h"

namespace dsa::testing {

class DSATest : public ::testing::Test {
 protected:
    static void EXPECT_ARRAY_EQ(int *expected, unsigned int expectedLength, int *actual, unsigned int actualLength);
    static void EXPECT_ARRAY_EQ_LINKEDLIST(int *ary, unsigned int length, nodes::ListNode *head);
    static void EXPECT_ARRAY_EQ_TREE(int *ary, unsigned int length, nodes::BinaryTreeNode *root);

 private:
    static void EXPECT_ARRAY_EQ_TREE_DFS(int *ary, unsigned int length, nodes::BinaryTreeNode *root, unsigned int i);
};

}  // namespace dsa::testing

#endif  // TESTING_H