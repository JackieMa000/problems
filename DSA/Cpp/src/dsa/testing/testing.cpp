#include "testing.h"
#include "dsa/lib/lists/arrays/array.h"

namespace dsa::testing {

void DSATest::EXPECT_ARRAY_EQ(int *expected, unsigned int expectedLength, int *actual, unsigned int actualLength) {
    EXPECT_EQ(expectedLength, actualLength)
                    << "Array lengths not equal"
                    << "\n expectedLength: " << expectedLength << "\n actualLength: " << actualLength;

    if (expectedLength == 0 || actualLength == 0 || expectedLength != actualLength)
        return;

    EXPECT_EQ(*(expected + (expectedLength - 1)), *(actual + (actualLength - 1)))
                    << "Arrays not equal"
                    << "\n expected array on index " << expectedLength - 1 << " = " << expected[expectedLength - 1]
                    << "\n actual array on index " << actualLength - 1 << " = " << actual[actualLength - 1];

    if (expectedLength > 1 && actualLength > 1) {
        int newExpected[expectedLength - 1];
        lib::lists::arrays::Array expArray(expected, expectedLength);
        expArray.copy(newExpected, 0, expectedLength - 2);

        int newActual[actualLength - 1];
        lib::lists::arrays::Array actArray(actual, actualLength);
        actArray.copy(newActual, 0, actualLength - 2);

        EXPECT_ARRAY_EQ(newExpected, expectedLength - 1, newActual, actualLength - 1);
    }
}

void DSATest::EXPECT_ARRAY_EQ_LINKEDLIST(int *ary, unsigned int length, nodes::ListNode *head) {
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

void DSATest::EXPECT_ARRAY_EQ_TREE(int *ary, unsigned int length, nodes::BinaryTreeNode *root) {
    EXPECT_ARRAY_EQ_TREE_DFS(ary, length, root, 0);
}

void DSATest::EXPECT_ARRAY_EQ_TREE_DFS(int *ary, unsigned int length, nodes::BinaryTreeNode *root, unsigned int i) {
    // ToDo: Add error message for failed test.
    if (i >= length) return;
    if (!root) {
        EXPECT_EQ(0, *(ary + i));
        return;
    }
    EXPECT_EQ(root->val, *(ary + i));
    EXPECT_ARRAY_EQ_TREE_DFS(ary, length, root->left, 2 * i + 1);
    EXPECT_ARRAY_EQ_TREE_DFS(ary, length, root->right, 2 * i + 2);
}

}  // namespace dsa::testing