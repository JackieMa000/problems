#include <dsa/lib/math/nums/max_sliding_window.hpp>
#include "nums_test.h"
namespace dsa::lib::math::nums {
namespace {

class MaxSlidingWindowTest : public NumsTest {
 protected:
    static std::vector<int> maxSlidingWindow(std::vector<int> &nums, int k) {
        return MaxSlidingWindow::maxSlidingWindow(nums, k);
    }
};
TEST_F(MaxSlidingWindowTest, case1) {
    std::vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    std::vector<int> expected = {3, 3, 5, 5, 6, 7};
    std::vector<int> actual = maxSlidingWindow(nums, 3);
    EXPECT_EQ(expected, actual);
}
TEST_F(MaxSlidingWindowTest, case2) {
    std::vector<int> nums = {1};
    std::vector<int> expected = {1};
    std::vector<int> actual = maxSlidingWindow(nums, 1);
    EXPECT_EQ(expected, actual);
}
TEST_F(MaxSlidingWindowTest, case3) {
    std::vector<int> nums = {1, -1};
    std::vector<int> expected = {1, -1};
    std::vector<int> actual = maxSlidingWindow(nums, 1);
    EXPECT_EQ(expected, actual);
}
TEST_F(MaxSlidingWindowTest, case4) {
    std::vector<int> nums = {9, 11};
    std::vector<int> expected = {11};
    std::vector<int> actual = maxSlidingWindow(nums, 2);
    EXPECT_EQ(expected, actual);
}
TEST_F(MaxSlidingWindowTest, case5) {
    std::vector<int> nums = {4, -1};
    std::vector<int> expected = {4};
    std::vector<int> actual = maxSlidingWindow(nums, 2);
    EXPECT_EQ(expected, actual);
}

}
}
