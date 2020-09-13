#include <gtest/gtest.h>

#include "dsa/nodes.h"

#ifndef TESTING_H
#define TESTING_H

namespace dsa {
namespace testing {

class DSATest : public ::testing::Test
{
protected:
    int static*
    copyArray(int ary[], int start, int end);

public:
    void
    EXPECT_ARRAY_EQ(int expected[], int expectedLength, int actual[], int actualLength);
    void
    EXPECT_ARRAY_EQ_LINKEDLIST(int ary[], int length, nodes::ListNode* head);
};

}  // namespace testing
}  // namespace dsa

#endif  // TESTING_H