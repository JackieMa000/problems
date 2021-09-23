#include <list>
#include <vector>

#include <dsa/lib/libdef.h>
#include <dsa/lib/utils/algorithm.hpp>
#include <dsa/testing/dsatest.h>

namespace dsa {
namespace {

TEST(ReverseTest, arrayOneElement) {
    int nums[] = {0};
    int expected[] = {0};
    dsa::reverse(nums, nums + arylen(nums));
    EXPECT_LIST_EQ(expected, nums, nums + arylen(nums));
}
TEST(ReverseTest, array) {
    int nums[] = {1, 2, 3};
    int expected[] = {3, 2, 1};
    dsa::reverse(nums, nums + arylen(nums));
    EXPECT_LIST_EQ(expected, nums, nums + arylen(nums));
}
TEST(ReverseTest, list) {
    std::list<int> nums = {1, 2, 3};
    std::list<int> expected = {3, 2, 1};
    dsa::reverse(nums.begin(), nums.end());
    EXPECT_EQ(expected, nums);
}
TEST(ReverseTest, vector) {
    std::vector<int> nums = {1, 2, 3};
    std::vector<int> expected = {3, 2, 1};
    dsa::reverse(nums.begin(), nums.end());
    EXPECT_EQ(expected, nums);
}

}
}