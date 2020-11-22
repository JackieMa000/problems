#include <dsa/lib/math/nums/two_sum.hpp>
#include "nums_test.h"
namespace dsa::lib::math::nums {
namespace {

class TwoSumTest : public NumsTest {
 protected:
    static std::vector<int> twoSum(std::vector<int> &nums, int target) {
        return TwoSum::twoSum(nums, target);
    }
};
TEST_F(TwoSumTest, case1) {
    std::vector<int> nums = {2, 7, 11, 5};
    std::vector<int> actual = twoSum(nums, 9);
    std::vector<int> expected = {0, 1};
    EXPECT_EQ(expected, actual);
}
TEST_F(TwoSumTest, case2) {
    std::vector<int> nums = {3, 2, 4};
    std::vector<int> actual = twoSum(nums, 6);
    std::vector<int> expected = {1, 2};
    EXPECT_EQ(expected, actual);
}
TEST_F(TwoSumTest, case3) {
    std::vector<int> nums = {3, 3};
    std::vector<int> actual = twoSum(nums, 6);
    std::vector<int> expected = {0, 1};
    EXPECT_EQ(expected, actual);
}
TEST_F(TwoSumTest, case4) {
    std::vector<int> nums = {3, 3};
    std::vector<int> actual = twoSum(nums, 7);
    std::vector<int> expected = {};
    EXPECT_EQ(expected, actual);
}

}
}
