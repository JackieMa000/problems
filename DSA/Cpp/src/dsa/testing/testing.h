#ifndef TESTING_H
#define TESTING_H

#include <gtest/gtest.h>
#include "dsa/nodes.h"

namespace dsa::testing {

class DSATest : public ::testing::Test {
 protected:
    static void EXPECT_ARRAY_EQ(int *expected, size_t expectedSize, int *actual, size_t actualSize);
    static void EXPECT_ARRAY_EQ_LINKEDLIST(int *ary, unsigned int length, nodes::ListNode *head);
    static void EXPECT_ARRAY_EQ_TREE(int *ary, unsigned int length, nodes::BinaryTreeNode *root);

 private:
    static void EXPECT_ARRAY_EQ_TREE_DFS(int *ary, unsigned int length, nodes::BinaryTreeNode *root, unsigned int i);
};

}  // namespace dsa::testing

#endif  // TESTING_H