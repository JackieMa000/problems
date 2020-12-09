#include <vector>
#include <dsa/lib/math/nums/three_sum.hpp>
#include "nums_test.h"
namespace dsa::lib::math::nums {
namespace {

class ThreeSumTest : public NumsTest {
 protected:
    static std::vector<std::vector<int>> threeSum(std::vector<int> nums) {
        return ThreeSum::threeSum(nums);
    };
};
TEST_F(ThreeSumTest, case1) {
    std::vector<int> nums = {-1, 0, 1, 2, -1, 4};
    std::vector<std::vector<int>> expected = {{-1, -1, 2}, {-1, 0, 1}};
    std::vector<std::vector<int>> actual = threeSum(nums);
    EXPECT_EQ(expected, actual);
}
TEST_F(ThreeSumTest, case2) {
    std::vector<int> nums = {};
    std::vector<std::vector<int>> expected = {};
    std::vector<std::vector<int>> actual = threeSum(nums);
    EXPECT_EQ(expected, actual);
}
TEST_F(ThreeSumTest, case3) {
    std::vector<int> nums = {0};
    std::vector<std::vector<int>> expected = {};
    std::vector<std::vector<int>> actual = threeSum(nums);
    EXPECT_EQ(expected, actual);
}

}
}

