#ifndef DSA_TEST_DSA_TESTING_DSATEST_H_
#define DSA_TEST_DSA_TESTING_DSATEST_H_

#include "testing.h"

#define EXPECT_LIST_EQ(expected, actualFirst, actualLast) \
    ::dsa::testing::DSATest::EXPECT_LIST_EQ(expected, actualFirst, actualLast);

#define EXPECT_LIST_EQ_FULL(expectedFirst, expectedLast, actualFirst, actualLast) \
    ::dsa::testing::DSATest::EXPECT_LIST_EQ(expectedFirst, expectedLast, actualFirst, actualLast);

#define EXPECT_EQ_TREE(first, last, root) ::dsa::testing::DSATest:EXPECT_EQ_TREE(first, last, root);

#endif //DSA_TEST_DSA_TESTING_DSATEST_H_
