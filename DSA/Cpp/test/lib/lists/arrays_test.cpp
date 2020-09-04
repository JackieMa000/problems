#include "testing.h"
#include "lib/lists/arrays.h"

namespace lib
{
    namespace
    {
        class ArrayTest : public dsa::testing::DSATest
        {
        };

        TEST_F(ArrayTest, case2) {
            EXPECT_EQ(1, 1);
        }

        class ArrayListTest : public dsa::testing::DSATest
        {
        };

    } // namespace
} // namespace lib