#include "lib/utils.h"
#include "testing.h"

namespace dsa
{
    namespace lib
    {
        namespace utils
        {
            namespace
            {
                class ArrayRstripTest : public dsa::testing::DSATest
                {
                };

                TEST_F(ArrayRstripTest, case1)
                {
                    // Arrange;
                    // Act;
                    int ary[] = {1, 2, 0};
                    int *actual = arrayRstrip(ary);

                    // Assert;
                    int res = actual[1];
                    EXPECT_EQ(2, res);
                    // EXPECT_ARRAY_EQ(expected, actual);
                }

            } // namespace
        }     // namespace utils
    }         // namespace lib
} // namespace dsa