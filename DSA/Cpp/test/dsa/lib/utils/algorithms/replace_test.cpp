#include <list>
#include <vector>

#include <dsa/lib/libdef.h>
#include <dsa/lib/utils/algorithm.hpp>
#include <dsa/testing/dsatest.h>
#include <dsa/lib/utils/math.hpp>

namespace dsa {
namespace {

TEST(ReplaceTest, array) {
    int nums[] = {1, 2, 3};
    int expected[] = {1, 0, 3};
    dsa::replace(nums, nums + 3, 2, 0);
    EXPECT_LIST_EQ(expected, nums, nums + arylen(nums));
}
TEST(ReplaceTest, vector) {
    std::vector<int> nums = {1, 2, 3};
    std::vector<int> expected = {1, 0, 3};

    dsa::replace(nums.begin(), nums.end(), 2, 0);
    EXPECT_EQ(expected, nums);
}

TEST(ReplaceIfTest, array) {
    int nums[] = {1, 2, 3};
    int expected[] = {0, 2, 0};
    dsa::replace_if(nums, nums + 3, dsa::isOdd, 0);
    EXPECT_LIST_EQ(expected, nums, nums + arylen(nums));
}
TEST(ReplaceIfTest, vector) {
    std::vector<int> nums = {1, 2, 3};
    std::vector<int> expected = {0, 2, 0};

    dsa::replace_if(nums.begin(), nums.end(), dsa::isOdd, 0);
    EXPECT_EQ(expected, nums);
}

}  // namespace
}  // namespace dsa
