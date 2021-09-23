#include <array>
#include <vector>

#include <dsa/lib/utils/algorithm.hpp>

namespace dsa {
namespace {

template<class RandomAccessIterator>
void assertLStrip(RandomAccessIterator expected, RandomAccessIterator first, RandomAccessIterator last) {
    EXPECT_EQ(expected, lstrip(first, last));
}
TEST(LStripTest, empty_returnFirst) {
    std::vector<int> v = {};
    assertLStrip(v.begin(), v.begin(), v.end());
}
TEST(LStripTest, all0s_returnLast) {
    std::vector<int> v = {0};
    assertLStrip(v.end(), v.begin(), v.end());
}
TEST(LStripTest, all0s_returnLast1) {
    std::vector<int> v = {0, 0, 0};
    assertLStrip(v.end(), v.begin(), v.end());
}
TEST(LStripTest, leftNot0s) {
    std::vector<int> v = {1, 2, 3};
    assertLStrip(v.begin(), v.begin(), v.end());
}
TEST(LStripTest, left0s) {
    std::vector<int> v = {0, 1, 2};
    assertLStrip(v.begin() + 1, v.begin(), v.end());
}
TEST(LStripTest, left0s1) {
    std::vector<int> v = {0, 0, 1, 0, 2};
    assertLStrip(v.begin() + 2, v.begin(), v.end());
}
TEST(LStripTest, constexpr) {
    static constexpr std::array<int, 3> a = {0, 1, 2};
    constexpr auto first = lstrip(a.begin(), a.end());
    static_assert(first == a.begin() + 1);
}

template<class RandomAccessIterator>
void assertRStrip(RandomAccessIterator expected, RandomAccessIterator first, RandomAccessIterator last) {
    EXPECT_EQ(expected, rstrip(first, last));
}
TEST(RStripTest, empty_returnFirst) {
    std::vector<int> v = {};
    assertRStrip(v.begin(), v.begin(), v.end());
}
TEST(RStripTest, all0s_returnFirst) {
    std::vector<int> v = {0};
    assertRStrip(v.begin(), v.begin(), v.end());
}
TEST(RStripTest, all0s_returnFirst1) {
    std::vector<int> v = {0, 0, 0};
    assertRStrip(v.begin(), v.begin(), v.end());
}
TEST(RStripTest, rightNot0s) {
    std::vector<int> v = {1, 2, 3};
    assertRStrip(v.end(), v.begin(), v.end());
}
TEST(RStripTest, right0s) {
    std::vector<int> v = {1, 2, 0};
    assertRStrip(v.end() - 1, v.begin(), v.end());
}
TEST(RStripTest, right0s1) {
    std::vector<int> v = {1, 0, 2, 0, 0};
    assertRStrip(v.end() - 2, v.begin(), v.end());
}
TEST(RStripTest, constexpr) {
    static constexpr std::array<int, 3> a = {1, 2, 0};
    constexpr auto last = rstrip(a.begin(), a.end());
    static_assert(last == a.end() - 1);
}

template<class RandomAccessIterator>
void assertStrip(RandomAccessIterator expectedFirst,
                 RandomAccessIterator expectedLast,
                 RandomAccessIterator first,
                 RandomAccessIterator last) {
    auto[actualFirst, actualLast] = strip(first, last);
    EXPECT_EQ(expectedFirst, actualFirst);
    EXPECT_EQ(expectedLast, actualLast);
}
TEST(StripTest, empty_returnFirstLast) {
    std::vector<int> v = {};
    assertStrip(v.begin(), v.end(), v.begin(), v.end());
}
TEST(StripTest, all0s_returnLast) {
    std::vector<int> v = {0};
    assertStrip(v.end(), v.end(), v.begin(), v.end());
}
TEST(StripTest, all0s_returnLast1) {
    std::vector<int> v = {0, 0, 0};
    assertStrip(v.end(), v.end(), v.begin(), v.end());
}
TEST(StripTest, leftRightNot0s) {
    std::vector<int> v = {1, 2, 3};
    assertStrip(v.begin(), v.end(), v.begin(), v.end());
}
TEST(StripTest, leftRight0s) {
    std::vector<int> v = {0, 1, 2, 0};
    assertStrip(v.begin() + 1, v.end() - 1, v.begin(), v.end());
}
TEST(StripTest, leftRight0s1) {
    std::vector<int> v = {0, 0, 1, 0, 2, 0, 0};
    assertStrip(v.begin() + 2, v.end() - 2, v.begin(), v.end());
}
TEST(StripTest, constexpr) {
    static constexpr std::array<int, 4> a = {0, 1, 2, 0};
    constexpr auto actual = strip(a.begin(), a.end());
    static_assert(actual.first == a.begin() + 1);
    static_assert(actual.second == a.end() - 1);
}

}
}
