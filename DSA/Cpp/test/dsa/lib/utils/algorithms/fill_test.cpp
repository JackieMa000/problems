#include <list>
#include <vector>

#include <dsa/lib/libdef.h>
#include <dsa/lib/utils/algorithm.hpp>
#include <dsa/testing/dsatest.h>

namespace dsa {
namespace {

void assertFill(std::vector<int> &&expected, std::vector<int> &&v) {
    dsa::fill(v.begin(), v.end(), 1);
    EXPECT_EQ(expected, v);
}
TEST(FillTest, case1) {
    assertFill({1, 1, 1}, {0, 0, 0});
}

TEST(FillNTest, case1) {
    int nums[] = {0, 0, 0};
    int expected[] = {1, 1, 0};
    dsa::fill_n(nums, 2, 1);
    EXPECT_LIST_EQ(expected, nums, nums + arylen(nums));
}

}  // namespace
}  // namespace dsa
