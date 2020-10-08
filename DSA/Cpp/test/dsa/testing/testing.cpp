#include "testing.h"

namespace dsa::testing {

void DSATest::EXPECT_ARRAY_EQ(int *expected, length_t expectedLength, int *actual, length_t actualLength) {
    expectArrayEQDfs(expected, expectedLength, actual, actualLength);

}
void DSATest::expectArrayEQDfs(const int *expected,
                               length_t expectedLength,
                               const int *actual,
                               length_t actualLength) {
    EXPECT_EQ(expectedLength, actualLength)
                    << "Array lengths not equal"
                    << "\n expectedLength: " << expectedLength << "\n actualLength: " << actualLength;

    if (expectedLength == 0 || actualLength == 0 || expectedLength != actualLength) return;

    EXPECT_EQ(*(expected + (expectedLength - 1)), *(actual + (actualLength - 1)))
                    << "Arrays not equal"
                    << "\n expected array on index " << expectedLength - 1 << " = "
                    << *(expected + (expectedLength - 1))
                    << "\n actual array on index " << actualLength - 1 << " = " << *(actual + (actualLength - 1));

    if (expectedLength > 1 && actualLength > 1) {
        expectArrayEQDfs(expected, expectedLength - 1, actual, actualLength - 1);
    }
}

void DSATest::EXPECT_ARRAY_EQ_LINKEDLIST(int *ary, length_t length, nodes::ListNode *head) {
    // ToDo: Add error message for failed test.
    int i = 0;
    while (head && i < length) {
        EXPECT_EQ(*(ary + i), head->val);
        i++;
        head = head->next;
    }
    EXPECT_EQ(length, i);
    EXPECT_EQ(nullptr, head);
}

void DSATest::EXPECT_ARRAY_EQ_TREE(int *ary, length_t length, nodes::BinaryTreeNode *root) {
    expectArrayEQTreeDfs(ary, length, root, 0);
}

void DSATest::expectArrayEQTreeDfs(int *ary, length_t length, nodes::BinaryTreeNode *root, pos_t i) {
    // ToDo: Add error message for failed test.
    if (i >= length) return;
    if (!root) {
        EXPECT_EQ(0, *(ary + i));
        return;
    }
    EXPECT_EQ(root->val, *(ary + i));
    expectArrayEQTreeDfs(ary, length, root->left, 2 * i + 1);
    expectArrayEQTreeDfs(ary, length, root->right, 2 * i + 2);
}

}  // namespace dsa::testing