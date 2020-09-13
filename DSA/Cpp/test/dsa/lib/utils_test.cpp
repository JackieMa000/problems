#include "dsa/testing/testing.h"
#include "dsa/lib/utils.h"

namespace dsa {
namespace lib {
namespace utils {
namespace {
class ArrayRstripTest : public dsa::testing::DSATest
{
};

TEST_F(ArrayRstripTest, case1)
{
    // Arrange;
    // Act;
    int ary[] = {1, 2, 0};
    int* actual = arrayRstrip(ary);

    // Assert;
    int res = actual[1];
    EXPECT_EQ(2, res);
    // EXPECT_ARRAY_EQ(expected, actual);
}

TEST_F(ArrayRstripTest, case2)
{
    EXPECT_EQ(1, 1);
}

}  // namespace
}  // namespace utils
}  // namespace lib
}  // namespace dsa