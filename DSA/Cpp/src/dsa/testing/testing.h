#ifndef TESTING_H
#define TESTING_H

#include <gtest/gtest.h>
#include "dsa/nodes.h"

namespace dsa::testing {

class DSATest : public ::testing::Test {
 protected:
    void
    EXPECT_ARRAY_EQ(int *expected, unsigned int expectedLength, int *actual, unsigned int actualLength);

    static void
    EXPECT_ARRAY_EQ_LINKEDLIST(int ary[], int length, nodes::ListNode *head);
};

}  // namespace dsa::testing

#endif  // TESTING_H