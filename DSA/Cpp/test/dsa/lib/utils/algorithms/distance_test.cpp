#include <list>
#include <vector>

#include <dsa/lib/utils/algorithm.hpp>

namespace dsa {
namespace {

TEST(DistanceTest, array) {
    int nums[] = {1, 2, 3};
    long actual = dsa::distance(nums, nums);
    EXPECT_EQ(actual, 0);
}
TEST(DistanceTest, array1) {
    int nums[] = {1, 2, 3};
    auto actual = dsa::distance(nums, nums + 3);
    EXPECT_EQ(actual, 3);
}
TEST(DistanceTest, list) {
    std::list<int> nums = {1, 2, 3};
    auto actual = dsa::distance(nums.begin(), nums.end());
    EXPECT_EQ(actual, 3);
}
TEST(DistanceTest, vector) {
    std::vector<int> nums = {1, 2, 3};
    auto actual = dsa::distance(nums.begin(), nums.end());
    EXPECT_EQ(actual, 3);
}

}
}