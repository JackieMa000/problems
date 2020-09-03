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
            void EXPECT_ARRAY_EQ(int ary1[], int ary2[]);
        };
    } // namespace testing
} // namespace dsa
#endif // TESTING_H