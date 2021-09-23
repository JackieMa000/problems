#include <list>
#include <vector>

#include <dsa/lib/libdef.h>
#include <dsa/lib/utils/algorithm.hpp>
#include <dsa/testing/dsatest.h>

namespace dsa {
namespace {

TEST(MinTest, case1) {
    int x = 0;
    int y = 0;
    EXPECT_EQ(&x, &dsa::min(x, y));
    EXPECT_EQ(&y, &dsa::min(y, x));
}
TEST(MinTest, case2) {
    int x = 0;
    int y = 1;
    EXPECT_EQ(&x, &dsa::min(x, y));
    EXPECT_EQ(&x, &dsa::min(y, x));
}
TEST(MinTest, case3) {
    int x = 1;
    int y = 0;
    EXPECT_EQ(&y, &dsa::min(x, y));
    EXPECT_EQ(&y, &dsa::min(y, x));
}
TEST(MinTest, staticAssert) {
    constexpr int x = 1, y = 0;
    static_assert(&dsa::min(x, y) == &y);
    static_assert(&dsa::min(y, x) == &y);
}

TEST(MinCompTest, case1) {
    int x = 0;
    int y = 0;
    EXPECT_EQ(&x, &dsa::min(x, y, std::greater<>()));
}
TEST(MinCompTest, case2) {
    int x = 0;
    int y = 1;
    EXPECT_EQ(&y, &dsa::min(x, y, std::greater<>()));
}
TEST(MinCompTest, case3) {
    int x = 1;
    int y = 0;
    EXPECT_EQ(&x, &dsa::min(x, y, std::greater<>()));
}

TEST(MinInitListTest, case1) {
    EXPECT_EQ(1, dsa::min({2, 3, 1}));
    EXPECT_EQ(1, dsa::min({2, 1, 3}));
    EXPECT_EQ(1, dsa::min({3, 1, 2}));
    EXPECT_EQ(1, dsa::min({3, 2, 1}));
    EXPECT_EQ(1, dsa::min({1, 2, 3}));
    EXPECT_EQ(1, dsa::min({1, 3, 2}));
}

TEST(MinInitListCompTest, case1) {
    EXPECT_EQ(3, dsa::min({2, 3, 1}, std::greater<>()));
    EXPECT_EQ(3, dsa::min({2, 1, 3}, std::greater<>()));
    EXPECT_EQ(3, dsa::min({3, 1, 2}, std::greater<>()));
    EXPECT_EQ(3, dsa::min({3, 2, 1}, std::greater<>()));
    EXPECT_EQ(3, dsa::min({1, 2, 3}, std::greater<>()));
    EXPECT_EQ(3, dsa::min({1, 3, 2}, std::greater<>()));
}

TEST(MinElementTest, array) {
    int nums[] = {2, 4, 6, 8, 7, 5, 3, 1};
    int *actual = dsa::min_element(nums, nums + arylen(nums));
    EXPECT_EQ(1, *actual);
}
TEST(MinElementTest, list) {
    std::list<int> nums = {2, 4, 6, 8, 7, 5, 3, 1};
    auto actual = dsa::min_element(nums.begin(), nums.end());
    EXPECT_EQ(1, *actual);
}
TEST(MinElementTest, vector) {
    std::vector<int> nums = {2, 4, 6, 8, 7, 5, 3, 1};
    auto actual = dsa::min_element(nums.begin(), nums.end());
    EXPECT_EQ(1, *actual);
}
TEST(MinElementTest, staticAssert) {
    static constexpr int nums[] = {2, 4, 6, 8, 7, 5, 3, 1};
    static_assert(*dsa::min_element(nums, nums + 8) == 1);
}

TEST(MinElementCompTest, array) {
    int nums[] = {2, 4, 6, 8, 7, 5, 3, 1};
    EXPECT_EQ(1, *dsa::min_element(nums, nums + arylen(nums), std::less<>()));
    EXPECT_EQ(8, *dsa::min_element(nums, nums + arylen(nums), std::greater<>()));
}
TEST(MinElementCompTest, list) {
    std::list<int> nums = {2, 4, 6, 8, 7, 5, 3, 1};
    EXPECT_EQ(1, *dsa::min_element(nums.begin(), nums.end(), std::less<>()));
    EXPECT_EQ(8, *dsa::min_element(nums.begin(), nums.end(), std::greater<>()));
}
TEST(MinElementCompTest, vector) {
    std::vector<int> nums = {2, 4, 6, 8, 7, 5, 3, 1};
    EXPECT_EQ(1, *dsa::min_element(nums.begin(), nums.end(), std::less<>()));
    EXPECT_EQ(8, *dsa::min_element(nums.begin(), nums.end(), std::greater<>()));
}
TEST(MinElementCompTest, staticAssert) {
    static constexpr int nums[] = {2, 4, 6, 8, 7, 5, 3, 1};
    static_assert(*dsa::min_element(nums, nums + 8, std::less<>()) == 1);
}

}
}
