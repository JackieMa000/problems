#include <list>
#include <vector>

#include <dsa/lib/libdef.h>
#include <dsa/lib/utils/algorithm.hpp>
#include <dsa/testing/dsatest.h>

namespace dsa {
namespace {

template<class T>
void assertMax(const T &a, const T &b, const T &expected) {
    EXPECT_EQ(&dsa::max(a, b), &expected);
}
TEST(MaxTest, case1) {
    int x = 0, y = 0;
    assertMax(x, y, x);
    assertMax(y, x, y);
}
TEST(MaxTest, case2) {
    int x = 0, y = 1;
    assertMax(x, y, y);
    assertMax(y, x, y);
}
TEST(MaxTest, case3) {
    int x = 1, y = 0;
    assertMax(x, y, x);
    assertMax(y, x, x);
}
TEST(MaxTest, staticAssert) {
    constexpr int x = 1, y = 0;
    static_assert(&dsa::max(x, y) == &x);
    static_assert(&dsa::max(y, x) == &x);
}

template<class T, class Compare>
void assertMaxComp(const T &a, const T &b, Compare comp, const T &expected) {
    EXPECT_EQ(&dsa::max(a, b, comp), &expected);
}
TEST(MaxCompTest, case1) {
    int x = 0, y = 0;
    assertMaxComp(x, y, std::greater<>(), x);
    assertMaxComp(y, x, std::greater<>(), y);
}
TEST(MaxCompTest, case2) {
    int x = 0, y = 1;
    assertMaxComp(x, y, std::greater<>(), x);
    assertMaxComp(y, x, std::greater<>(), x);
}
TEST(MaxCompTest, case3) {
    int x = 1, y = 0;
    assertMaxComp(x, y, std::greater<>(), y);
    assertMaxComp(y, x, std::greater<>(), y);
}
TEST(MaxCompTest, staticAssert) {
    constexpr int x = 1, y = 0;
    static_assert(&dsa::max(x, y, std::greater<>()) == &y);
    static_assert(&dsa::max(y, x, std::greater<>()) == &y);
}

TEST(MaxInitListTest, case1) {
    EXPECT_EQ(3, dsa::max({2, 3, 1}));
    EXPECT_EQ(3, dsa::max({2, 1, 3}));
    EXPECT_EQ(3, dsa::max({3, 1, 2}));
    EXPECT_EQ(3, dsa::max({3, 2, 1}));
    EXPECT_EQ(3, dsa::max({1, 2, 3}));
    EXPECT_EQ(3, dsa::max({1, 3, 2}));
}
TEST(MaxInitListTest, staticAssert) {
    static_assert(std::max({1, 3, 2}) == 3);
    static_assert(std::max({2, 1, 3}) == 3);
    static_assert(std::max({3, 2, 1}) == 3);
}

TEST(MaxInitListCompTest, case1) {
    EXPECT_EQ(1, dsa::max({2, 3, 1}, std::greater<>()));
    EXPECT_EQ(1, dsa::max({2, 1, 3}, std::greater<>()));
    EXPECT_EQ(1, dsa::max({3, 1, 2}, std::greater<>()));
    EXPECT_EQ(1, dsa::max({3, 2, 1}, std::greater<>()));
    EXPECT_EQ(1, dsa::max({1, 2, 3}, std::greater<>()));
    EXPECT_EQ(1, dsa::max({1, 3, 2}, std::greater<>()));
}
TEST(MaxInitListCompTest, staticAssert) {
    static_assert(std::max({1, 3, 2}, std::greater<>()) == 1);
    static_assert(std::max({2, 1, 3}, std::greater<>()) == 1);
    static_assert(std::max({3, 2, 1}, std::greater<>()) == 1);
}

TEST(MaxElementTest, array) {
    int nums[] = {2, 4, 6, 8, 7, 5, 3, 1};
    int *actual = dsa::max_element(nums, nums + aryLength(nums));
    EXPECT_EQ(8, *actual);
}
TEST(MaxElementTest, list) {
    std::list<int> nums = {2, 4, 6, 8, 7, 5, 3, 1};
    auto actual = dsa::max_element(nums.begin(), nums.end());
    EXPECT_EQ(8, *actual);
}
TEST(MaxElementTest, vector) {
    std::vector<int> nums = {2, 4, 6, 8, 7, 5, 3, 1};
    auto actual = dsa::max_element(nums.begin(), nums.end());
    EXPECT_EQ(8, *actual);
}
TEST(MaxElementTest, staticAssert) {
    static constexpr int nums[] = {2, 4, 6, 8, 7, 5, 3, 1};
    static_assert(*dsa::max_element(nums, nums + 8) == 8);
}

TEST(MaxElementCompTest, array) {
    int nums[] = {2, 4, 6, 8, 7, 5, 3, 1};
    EXPECT_EQ(8, *dsa::max_element(nums, nums + aryLength(nums), std::less<>()));
    EXPECT_EQ(1, *dsa::max_element(nums, nums + aryLength(nums), std::greater<>()));
}
TEST(MaxElementCompTest, list) {
    std::list<int> nums = {2, 4, 6, 8, 7, 5, 3, 1};
    EXPECT_EQ(8, *dsa::max_element(nums.begin(), nums.end(), std::less<>()));
    EXPECT_EQ(1, *dsa::max_element(nums.begin(), nums.end(), std::greater<>()));
}
TEST(MaxElementCompTest, vector) {
    std::vector<int> nums = {2, 4, 6, 8, 7, 5, 3, 1};
    EXPECT_EQ(8, *dsa::max_element(nums.begin(), nums.end(), std::less<>()));
    EXPECT_EQ(1, *dsa::max_element(nums.begin(), nums.end(), std::greater<>()));
}
TEST(MaxElementCompTest, staticAssert) {
    static constexpr int nums[] = {2, 4, 6, 8, 7, 5, 3, 1};
    static_assert(*dsa::max_element(nums, nums + 8, std::less<>()) == 8);
}

}
}
