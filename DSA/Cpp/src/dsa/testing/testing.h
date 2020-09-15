#include <gtest/gtest.h>

#include "dsa/nodes.h"

#ifndef TESTING_H
#define TESTING_H

namespace dsa::testing {

class DSATest : public ::testing::Test {
 protected:
    void
    EXPECT_ARRAY_EQ(int *expected, int expectedLength, int *actual, int actualLength);

    static void
    EXPECT_ARRAY_EQ_LINKEDLIST(int ary[], int length, nodes::ListNode *head);
};

}  // namespace dsa::testing

#endif  // TESTING_H