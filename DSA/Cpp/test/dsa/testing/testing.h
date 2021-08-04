#ifndef DSA_TESTING_H
#define DSA_TESTING_H

#include <gtest/gtest.h>

#include <dsa/dsadef.h>
#include "dsa/nodes/nodes.h"

namespace dsa::testing {

class DSATest : public ::testing::Test {
 public:
    template<class InputIterator1, class InputIterator2>
    static void EXPECT_LIST_EQ(InputIterator2 expected, InputIterator1 actualFirst, InputIterator1 actualLast) {
        EXPECT_TRUE(std::equal(actualFirst, actualLast, expected));
    }

//  All the 3 functions below have the same functionalities as EXPECT_LIST_EQ.
    static void EXPECT_ARRAY_EQ(const array_s &expected, const array_s &actual);
    static void EXPECT_ARRAY_EQ(int *expected, length_t expectedLength, int *actual, length_t actualLength);
    static void EXPECT_ARRAY_EQ_LINKEDLIST(int *ary, length_t length, nodes::ListNode *head);

    template<class RandomAccessIterator>
    static void EXPECT_EQ_TREE(RandomAccessIterator first, RandomAccessIterator last, nodes::BinaryTreeNode *root) {
        expectEqTreeDfs(first, last, root, 0);
    }

 private:
    static void expectArrayEqDfs(const int *expected,
                                 length_t expectedLength,
                                 const int *actual,
                                 length_t actualLength);

    template<class RandomAccessIterator>
    static void expectEqTreeDfs(RandomAccessIterator first, RandomAccessIterator last,
                                nodes::BinaryTreeNode *root, pos_t i);

};

template<class RandomAccessIterator>
void DSATest::expectEqTreeDfs(RandomAccessIterator first, RandomAccessIterator last,
                              nodes::BinaryTreeNode *root, pos_t i) {
    typename std::iterator_traits<RandomAccessIterator>::difference_type n;
    n = last - first;

    if (i >= n) return;

    if (!root) {
        EXPECT_EQ(0, *(first + i));
        return;
    }
    EXPECT_EQ(root->val, *(first + i))
                    << "Array not equal Tree: "
                    << "\n  Index: " << i
                    << "\n  Expected: " << *(first + i)
                    << "\n  Actual: " << root->val;

    expectEqTreeDfs(first, last, root->left, 2 * i + 1);
    expectEqTreeDfs(first, last, root->right, 2 * i + 2);
}

}  // namespace dsa::testing

#endif  // DSA_TESTING_H