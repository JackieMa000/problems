#include "testing.h"

namespace dsa::testing {

void DSATest::EXPECT_ARRAY_EQ(const array_s &expected, const array_s &actual) {
    expectArrayEQDfs(expected.ary, expected.length, actual.ary, actual.length);

}
void DSATest::EXPECT_ARRAY_EQ(int *expected, length_t expectedLength, int *actual, length_t actualLength) {
    expectArrayEQDfs(expected, expectedLength, actual, actualLength);

}
void DSATest::expectArrayEQDfs(const int *expected, length_t expectedLength, const int *actual, length_t actualLength) {
    EXPECT_EQ(expectedLength, actualLength)
                    << "Array lengths not equal:"
                    << "\n  ExpectedLength: " << expectedLength
                    << "\n  ActualLength: " << actualLength;

    if (expectedLength == 0 || actualLength == 0 || expectedLength != actualLength) return;

    EXPECT_EQ(*(expected + (expectedLength - 1)), *(actual + (actualLength - 1)))
                    << "Array not equal Array:"
                    << "\n  ExpectedIndex: " << expectedLength - 1
                    << "\n  Expected: " << *(expected + (expectedLength - 1))
                    << "\n  ActualIndex: " << actualLength - 1
                    << "\n  Actual: " << *(actual + (actualLength - 1));

    if (expectedLength > 1 && actualLength > 1) {
        expectArrayEQDfs(expected, expectedLength - 1, actual, actualLength - 1);
    }
}

void DSATest::EXPECT_ARRAY_EQ_LINKEDLIST(int *ary, length_t length, nodes::ListNode *head) {
    int i = 0;
    while (head && i < length) {
        EXPECT_EQ(*(ary + i), head->val)
                        << "Array not equal LinkedList:"
                        << "\n  Index: " << i
                        << "\n  Expected: " << *(ary + i)
                        << "\n  Actual: " << head->val;
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
    if (i >= length) return;
    if (!root) {
        EXPECT_EQ(0, *(ary + i));
        return;
    }
    EXPECT_EQ(root->val, *(ary + i))
                    << "Array not equal Tree: "
                    << "\n  Index: " << i
                    << "\n  Expected: " << *(ary + i)
                    << "\n  Actual: " << root->val;

    expectArrayEQTreeDfs(ary, length, root->left, 2 * i + 1);
    expectArrayEQTreeDfs(ary, length, root->right, 2 * i + 2);
}

}  // namespace dsa::testing