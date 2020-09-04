#include "testing.h"
#include "lib/lists/arrays.h"

namespace lib
{
    namespace
    {
        class ArrayTest : public dsa::testing::DSATest
        {
        };

        TEST_F(ArrayTest, case1)
        {
            EXPECT_EQ(1, 1);
        }

        TEST_F(ArrayTest, case2)
        {
            EXPECT_INT_EQ(1, 1);
        }

        TEST_F(ArrayTest, case3)
        {
            int expected[] = {1, 2, 3};
            int actual[] = {1, 2, 3};
            int expectedSize = sizeof(expected)/4;
            int actualSize = sizeof(actual)/4;
            EXPECT_ARRAY_EQ(expected, expectedSize, actual, actualSize);
        }

        class ArrayListTest : public dsa::testing::DSATest
        {
        };

    } // namespace
} // namespace lib