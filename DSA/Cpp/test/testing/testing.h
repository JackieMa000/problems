#include <gtest/gtest.h>

#ifndef TESTING_H
#define TESTING_H

namespace dsa
{
    namespace testing
    {
        class DSATest : public ::testing::Test
        {
        public:
            void EXPECT_ARRAY_EQ(int expected[], int expectedSize, int actual[], int actualSize);
            void EXPECT_INT_EQ(int expected, int actual);
        };

    } // namespace testing
} // namespace dsa

#endif // TESTING_H