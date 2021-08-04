#include "testing.h"

namespace dsa::testing {

void DSATest::EXPECT_ARRAY_EQ(const array_s &expected, const array_s &actual) {
    expectArrayEqDfs(expected.ary, expected.length, actual.ary, actual.length);

}
void DSATest::EXPECT_ARRAY_EQ(int *expected, length_t expectedLength, int *actual, length_t actualLength) {
    expectArrayEqDfs(expected, expectedLength, actual, actualLength);

}
void DSATest::expectArrayEqDfs(const int *expected, length_t expectedLength, const int *actual, length_t actualLength) {
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
        expectArrayEqDfs(expected, expectedLength - 1, actual, actualLength - 1);
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

}  // namespace dsa::testing