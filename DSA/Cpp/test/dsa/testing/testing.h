#ifndef DSA_TESTING_H
#define DSA_TESTING_H

#include <gtest/gtest.h>
#include <dsa/dsadef.h>
#include "dsa/nodes/nodes.h"

namespace dsa::testing {

class DSATest : public ::testing::Test {
 public:
    template<class InputIterator1, class InputIterator2>
    static void EXPECT_LIST_EQ(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2);

//    ToDo: All the 3 functions can be replaced by EXPECT_LIST_EQ.
    static void EXPECT_ARRAY_EQ(const array_s &expected, const array_s &actual);
    static void EXPECT_ARRAY_EQ(int *expected, length_t expectedLength, int *actual, length_t actualLength);
    static void EXPECT_ARRAY_EQ_LINKEDLIST(int *ary, length_t length, nodes::ListNode *head);

    static void EXPECT_ARRAY_EQ_TREE(int *ary, length_t length, nodes::BinaryTreeNode *root);

 private:
    static void expectArrayEQTreeDfs(int *ary, length_t length, nodes::BinaryTreeNode *root, pos_t i);
    static void expectArrayEQDfs(const int *expected,
                                 length_t expectedLength,
                                 const int *actual,
                                 length_t actualLength);
};

template<class InputIterator1, class InputIterator2>
void DSATest::EXPECT_LIST_EQ(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2) {
    EXPECT_TRUE(std::equal(first1, last1, first2));
}

}  // namespace dsa::testing

#endif  // DSA_TESTING_H