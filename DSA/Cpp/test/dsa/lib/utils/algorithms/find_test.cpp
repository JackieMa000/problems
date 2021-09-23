#include <list>
#include <vector>

#include <dsa/lib/libdef.h>
#include <dsa/lib/utils/algorithm.hpp>

namespace dsa {
namespace {

TEST(FindTest, vector) {
    std::vector<int> nums = {1, 2, 3};
    auto actual = dsa::find(nums.begin(), nums.end(), 2);
    EXPECT_EQ(2, *actual);
}
TEST(FindIfTest, array) {
    int nums[] = {1, -2, -3};
    auto actual = dsa::find_if(nums, nums + arylen(nums), [](int x) { return x < 0; });
    EXPECT_EQ(-2, *actual);
    EXPECT_EQ(1, dsa::distance(nums, actual));
}
TEST(FindIfNotTest, list) {
    std::list<int> nums = {-1, 2, 3};
    auto actual = dsa::find_if_not(nums.begin(), nums.end(), [](int x) { return x < 0; });
    EXPECT_EQ(2, *actual);
    EXPECT_EQ(1, dsa::distance(nums.begin(), actual));
}

}
}