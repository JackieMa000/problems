#include <forward_list>

#include <dsa/lib/utils/algorithm.hpp>
#include <dsa/lib/libdef.h>

namespace dsa {
namespace {

template<class ForwardIterator>
void expectMaxSizeElement(ForwardIterator expected, ForwardIterator first, ForwardIterator last) {
    EXPECT_EQ(expected, dsa::maxSizeElement(first, last));
    EXPECT_EQ(*expected, *dsa::maxSizeElement(first, last));
}
TEST(MaxSizeElementTest, empty) {
    std::vector<std::vector<int>> v = {};
    EXPECT_EQ(v.begin(), dsa::maxSizeElement(v.begin(), v.end()));
}
TEST(MaxSizeElementTest, oneElement) {
    std::vector<std::vector<int>> v = {{0}};
    expectMaxSizeElement(v.begin(), v.begin(), v.end());
}
TEST(MaxSizeElementTest, multResults_returnFirst) {
    std::vector<std::vector<int>> v = {{0}, {1}};
    expectMaxSizeElement(v.begin(), v.begin(), v.end());
}
TEST(MaxSizeElementTest, stringElement) {
    std::vector<std::string> v = {"a", "ab", "abc"};
    expectMaxSizeElement(v.begin() + 2, v.begin(), v.end());
}
TEST(MaxSizeElementTest, stringArrayElement) {
    std::string ss[] = {"a", "ab", "abc"};
    expectMaxSizeElement(ss + 2, ss, ss + arylen(ss));
}
TEST(MaxSizeElementTest, intListElement) {
    std::vector<std::list<int>> v = {{1}, {1, 2}, {1, 2, 3}};
    expectMaxSizeElement(v.begin() + 2, v.begin(), v.end());
}
TEST(MaxSizeElementTest, charListElement) {
    std::vector<std::list<char>> v = {{'a'}, {'a', 'b'}, {'a', 'b', 'c'}};
    expectMaxSizeElement(v.begin() + 2, v.begin(), v.end());
}
TEST(MaxSizeElementTest, charArrayElement) {
    std::vector<std::vector<char>> v = {{'a'}, {'a', 'b'}, {'a', 'b', 'c'}};
    expectMaxSizeElement(v.begin() + 2, v.begin(), v.end());
}

template<class ForwardIterator>
void expectMinSizeElement(ForwardIterator expected, ForwardIterator first, ForwardIterator last) {
    EXPECT_EQ(expected, dsa::minSizeElement(first, last));
    EXPECT_EQ(*expected, *dsa::minSizeElement(first, last));
}
TEST(MinSizeElementTest, empty) {
    std::vector<std::vector<int>> v = {};
    EXPECT_EQ(v.begin(), dsa::minSizeElement(v.begin(), v.end()));
}
TEST(MinSizeElementTest, oneElement) {
    std::vector<std::vector<int>> v = {{0}};
    expectMinSizeElement(v.begin(), v.begin(), v.end());
}
TEST(MinSizeElementTest, multResults_returnFirst) {
    std::vector<std::vector<int>> v = {{0}, {1}};
    expectMinSizeElement(v.begin(), v.begin(), v.end());
}
TEST(MinSizeElementTest, stringElement) {
    std::vector<std::string> v = {"a", "ab", "abc"};
    expectMinSizeElement(v.begin(), v.begin(), v.end());
}
TEST(MinSizeElementTest, stringArrayElement) {
    std::string ss[] = {"a", "ab", "abc"};
    expectMinSizeElement(ss, ss, ss + arylen(ss));
}
TEST(MinSizeElementTest, intListElement) {
    std::vector<std::list<int>> v = {{1}, {1, 2}, {1, 2, 3}};
    expectMinSizeElement(v.begin(), v.begin(), v.end());
}
TEST(MinSizeElementTest, charListElement) {
    std::vector<std::list<char>> v = {{'a'}, {'a', 'b'}, {'a', 'b', 'c'}};
    expectMinSizeElement(v.begin(), v.begin(), v.end());
}
TEST(MinSizeElementTest, charArrayElement) {
    std::vector<std::vector<char>> v = {{'a'}, {'a', 'b'}, {'a', 'b', 'c'}};
    expectMinSizeElement(v.begin(), v.begin(), v.end());
}

TEST(EqualTest, inputIterator) {
    std::list<int> ia = {0, 1, 2, 3, 4, 5};
    std::list<int> ib = {0, 1, 2, 5, 4, 5};

    typedef typename std::list<int>::iterator it;
    auto c = typename std::iterator_traits<it>::iterator_category();
    auto _ = static_cast<std::input_iterator_tag>(c);
    assert(typeid(c) != typeid(std::random_access_iterator_tag));

    EXPECT_TRUE(dsa::equal(ia.begin(), ia.end(), ia.begin()));
    EXPECT_TRUE(dsa::equal(ia.begin(), ia.end(), ia.begin(), std::equal_to<>()));

    EXPECT_TRUE(dsa::equal(ia.begin(), ia.end(), ia.begin(), ia.end()));
    EXPECT_TRUE(dsa::equal(ia.begin(), ia.end(), ia.begin(), ia.end(), std::equal_to<>()));

    EXPECT_FALSE(dsa::equal(ia.begin(), ia.end(), ib.begin()));
    EXPECT_FALSE(dsa::equal(ia.begin(), ia.end(), ib.begin(), std::equal_to<>()));

    EXPECT_FALSE(dsa::equal(ia.begin(), ia.end(), ib.begin(), ib.end()));
    EXPECT_FALSE(dsa::equal(ia.begin(), ia.end(), ib.begin(), ib.end(), std::equal_to<>()));

    EXPECT_FALSE(dsa::equal(ia.begin(), ia.end(), ia.begin(), --ia.end()));
    EXPECT_FALSE(dsa::equal(ia.begin(), ia.end(), ia.begin(), --ia.end(), std::equal_to<>()));
}
TEST(EqualTest, randomAccessIterator) {
    int ia[] = {0, 1, 2, 3, 4, 5};
    int ib[] = {0, 1, 2, 5, 4, 5};

    auto c = typename std::iterator_traits<int *>::iterator_category();
    assert(typeid(c) == typeid(std::random_access_iterator_tag));

    EXPECT_TRUE(dsa::equal(std::begin(ia), std::end(ia), std::begin(ia), std::end(ia)));
    EXPECT_TRUE(dsa::equal(std::begin(ia), std::end(ia), std::begin(ia), std::end(ia), std::equal_to<>()));

    EXPECT_FALSE(dsa::equal(std::begin(ia), std::end(ia), std::begin(ib), std::end(ib)));
    EXPECT_FALSE(dsa::equal(std::begin(ia), std::end(ia), std::begin(ib), std::end(ib), std::equal_to<>()));

    EXPECT_FALSE(dsa::equal(std::begin(ia), std::end(ia), std::begin(ia), std::end(ia) - 1));
    EXPECT_FALSE(dsa::equal(std::begin(ia), std::end(ia), std::begin(ia), std::end(ia) - 1, std::equal_to<>()));
}
TEST(EqualTest, constexpr) {
    constexpr int ia[] = {1, 3, 6, 7};
    constexpr int ib[] = {1, 3};
    constexpr int ic[] = {1, 3, 5, 7};

    static_assert(!dsa::equal(std::begin(ia), std::end(ia), std::begin(ic)));
    static_assert(!dsa::equal(std::begin(ia), std::end(ia), std::begin(ic), std::equal_to<>()));

    static_assert(!dsa::equal(std::begin(ia), std::end(ia), std::begin(ic), std::end(ic)));
    static_assert(!dsa::equal(std::begin(ia), std::end(ia), std::begin(ic), std::end(ic), std::equal_to<>()));

    static_assert(dsa::equal(std::begin(ib), std::end(ib), std::begin(ic)));
    static_assert(dsa::equal(std::begin(ib), std::end(ib), std::begin(ic), std::equal_to<>()));

    static_assert(!dsa::equal(std::begin(ib), std::end(ib), std::begin(ic), std::end(ic)));
    static_assert(!dsa::equal(std::begin(ib), std::end(ib), std::begin(ic), std::end(ic), std::equal_to<>()));
}

}
}
