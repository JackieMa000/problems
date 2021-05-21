#ifndef DSA_TEST_DSA_TESTING_DSATEST_H_
#define DSA_TEST_DSA_TESTING_DSATEST_H_

#include "testing.h"

#define EXPECT_ARRAY_EQ(expected, expectedLength, actual, actualLength) \
    ::dsa::testing::DSATest::EXPECT_ARRAY_EQ(expected, expectedLength, actual, actualLength);
#define EXPECT_ARRAY_EQ_LINKEDLIST(ary, length, head) \
    ::dsa::testing::DSATest::EXPECT_ARRAY_EQ_LINKEDLIST(ary, length, head);
#define EXPECT_ARRAY_EQ_TREE(ary, length, root) \
    ::dsa::testing::DSATest:EXPECT_ARRAY_EQ_TREE(ary, length, root);

#endif //DSA_TEST_DSA_TESTING_DSATEST_H_
