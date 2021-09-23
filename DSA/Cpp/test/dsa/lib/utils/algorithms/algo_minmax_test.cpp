#include <list>
#include <vector>

#include <dsa/lib/libdef.h>
#include <dsa/lib/utils/algorithm.hpp>
#include <dsa/testing/dsatest.h>

namespace dsa {
namespace {

template<class T>
void
assertMinMax(const T &a, const T &b, const T &x, const T &y) {
    std::pair<const T &, const T &> p = dsa::minmax(a, b);
    EXPECT_EQ(&p.first, &x);
    EXPECT_EQ(&p.second, &y);
}
TEST(MinMaxTest, case1) {
    int x = 0, y = 0;
    assertMinMax(x, y, x, y);
    assertMinMax(y, x, y, x);
}
TEST(MinMaxTest, case2) {
    int x = 0, y = 1;
    assertMinMax(x, y, x, y);
    assertMinMax(y, x, x, y);
}
TEST(MinMaxTest, case3) {
    int x = 1, y = 0;
    assertMinMax(x, y, y, x);
    assertMinMax(y, x, y, x);
}
TEST(MinMaxTest, staticAssert) {
    constexpr static int x = 1, y = 0;
    constexpr auto p1 = dsa::minmax(x, y);
    static_assert(p1.first == y);
    static_assert(p1.second == x);

    constexpr auto p2 = dsa::minmax(y, x);
    static_assert(p2.first == y);
    static_assert(p2.second == x);
}

template<class T, class Compare>
inline
void assertMinMaxComp(const T &a, const T &b, Compare comp, const T &x, const T &y) {
    std::pair<const T &, const T &> p = dsa::minmax(a, b, comp);
    EXPECT_EQ(&p.first, &x);
    EXPECT_EQ(&p.second, &y);
}
TEST(MinMaxCompTest, case1) {
    int x = 0, y = 0;
    assertMinMaxComp(x, y, std::greater<>(), x, y);
    assertMinMaxComp(y, x, std::greater<>(), y, x);
}
TEST(MinMaxCompTest, case2) {
    int x = 0, y = 1;
    assertMinMaxComp(x, y, std::greater<>(), y, x);
    assertMinMaxComp(y, x, std::greater<>(), y, x);
}
TEST(MinMaxCompTest, case3) {
    int x = 1, y = 0;
    assertMinMaxComp(x, y, std::greater<>(), x, y);
    assertMinMaxComp(y, x, std::greater<>(), x, y);
}
TEST(MinMaxCompTest, staticAssert) {
    constexpr static int x = 1, y = 0;
    constexpr auto p1 = dsa::minmax(x, y, std::greater<>());
    static_assert(p1.first == x);
    static_assert(p1.second == y);

    constexpr auto p2 = dsa::minmax(y, x, std::greater<>());
    static_assert(p2.first == x);
    static_assert(p2.second == y);
}

inline void assertMinMaxInitList(std::initializer_list<int> ls, std::pair<int, int> expected) {
    EXPECT_EQ(dsa::minmax(ls), expected);
}
TEST(MinMaxInitListTest, case1) {
    assertMinMaxInitList({1, 2, 3}, {1, 3});
    assertMinMaxInitList({1, 3, 2}, {1, 3});
    assertMinMaxInitList({2, 1, 3}, {1, 3});
    assertMinMaxInitList({2, 3, 1}, {1, 3});
    assertMinMaxInitList({3, 1, 2}, {1, 3});
    assertMinMaxInitList({3, 2, 1}, {1, 3});
}
TEST(MinMaxInitListTest, staticAssert) {
    static_assert(dsa::minmax({1, 2, 3}) == std::pair<int, int>({1, 3}));
    static_assert((dsa::minmax({1, 3, 2}) == std::pair<int, int>(1, 3)));
    static_assert((dsa::minmax({2, 1, 3}) == std::pair<int, int>(1, 3)));
    static_assert((dsa::minmax({2, 3, 1}) == std::pair<int, int>(1, 3)));
    static_assert((dsa::minmax({3, 1, 2}) == std::pair<int, int>(1, 3)));
    static_assert((dsa::minmax({3, 2, 1}) == std::pair<int, int>(1, 3)));
}

inline void assertMinMaxInitListComp(std::initializer_list<int> ls, std::pair<int, int> expected) {
    EXPECT_EQ(dsa::minmax(ls, std::greater<>()), expected);
}
TEST(MinMaxInitListCompTest, case1) {
    assertMinMaxInitListComp({1, 2, 3}, {3, 1});
    assertMinMaxInitListComp({1, 3, 2}, {3, 1});
    assertMinMaxInitListComp({2, 1, 3}, {3, 1});
    assertMinMaxInitListComp({2, 3, 1}, {3, 1});
    assertMinMaxInitListComp({3, 1, 2}, {3, 1});
    assertMinMaxInitListComp({3, 2, 1}, {3, 1});
}
TEST(MinMaxInitListCompTest, staticAssert) {
    static_assert((dsa::minmax({1, 2, 3}, std::greater<>()) == std::pair<int, int>(3, 1)));
    static_assert((dsa::minmax({1, 3, 2}, std::greater<>()) == std::pair<int, int>(3, 1)));
    static_assert((dsa::minmax({2, 1, 3}, std::greater<>()) == std::pair<int, int>(3, 1)));
    static_assert((dsa::minmax({2, 3, 1}, std::greater<>()) == std::pair<int, int>(3, 1)));
    static_assert((dsa::minmax({3, 1, 2}, std::greater<>()) == std::pair<int, int>(3, 1)));
    static_assert((dsa::minmax({3, 2, 1}, std::greater<>()) == std::pair<int, int>(3, 1)));
}

TEST(MinMaxElementTest, array) {
    int nums[] = {2, 4, 6, 8, 7, 5, 3, 1};
    auto actual = dsa::minmax_element(nums, nums + arylen(nums));
    EXPECT_EQ(1, *actual.first);
    EXPECT_EQ(8, *actual.second);
}
TEST(MinMaxElementTest, list) {
    std::list<int> nums = {2, 4, 6, 8, 7, 5, 3, 1};
    auto actual = dsa::minmax_element(nums.begin(), nums.end());
    EXPECT_EQ(1, *actual.first);
    EXPECT_EQ(8, *actual.second);
}
TEST(MinMaxElementTest, vector) {
    std::vector<int> nums = {2, 4, 6, 8, 7, 5, 3, 1};
    auto actual = dsa::minmax_element(nums.begin(), nums.end());
    EXPECT_EQ(1, *actual.first);
    EXPECT_EQ(8, *actual.second);
}
TEST(MinMaxElementTest, staticAssert) {
    static constexpr int nums[] = {2, 4, 6, 8, 7, 5, 3, 1};
    constexpr auto actual = dsa::minmax_element(nums, nums + arylen(nums));
    static_assert(*actual.first == 1);
    static_assert(*actual.second == 8);
}

TEST(MinMaxElementCompTest, array) {
    int nums[] = {2, 4, 6, 8, 7, 5, 3, 1};
    auto p = dsa::minmax_element(nums, nums + arylen(nums), std::greater<>());
    EXPECT_EQ(8, *p.first);
    EXPECT_EQ(1, *p.second);
}
TEST(MinMaxElementCompTest, list) {
    std::list<int> nums = {2, 4, 6, 8, 7, 5, 3, 1};
    auto p = dsa::minmax_element(nums.begin(), nums.end(), std::greater<>());
    EXPECT_EQ(8, *p.first);
    EXPECT_EQ(1, *p.second);
}
TEST(MinMaxElementCompTest, vector) {
    std::vector<int> nums = {2, 4, 6, 8, 7, 5, 3, 1};
    auto p = dsa::minmax_element(nums.begin(), nums.end(), std::greater<>());
    EXPECT_EQ(8, *p.first);
    EXPECT_EQ(1, *p.second);
}
TEST(MinMaxElementCompTest, staticAssert) {
    static constexpr int nums[] = {2, 4, 6, 8, 7, 5, 3, 1};
    constexpr auto p = dsa::minmax_element(nums, nums + 8, std::less<>());
    static_assert(*p.first == 1);
    static_assert(*p.second == 8);
}

}
}
