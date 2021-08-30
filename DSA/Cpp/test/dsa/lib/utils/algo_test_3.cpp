#include <forward_list>

#include <dsa/lib/utils/algorithm.hpp>
#include <dsa/lib/libdef.h>

namespace dsa {
namespace {

template<class ForwardIterator, class ValueType>
void expectMaxSizeElement(ValueType expected, ForwardIterator first, ForwardIterator last) {
    EXPECT_EQ(expected, *dsa::maxSizeElement(first, last));
}
TEST(MaxSizeElementTest, stringElement) {
    std::vector<std::string> v = {"a", "ab", "abc"};
    std::string expected = "abc";
    expectMaxSizeElement(expected, v.begin(), v.end());
}
TEST(MaxSizeElementTest, stringArrayElement) {
    std::string ss[] = {"a", "ab", "abc"};
    std::string expected = "abc";
    expectMaxSizeElement(expected, ss, ss + aryLength(ss));
}
TEST(MaxSizeElementTest, intListElement) {
    std::vector<std::list<int>> v = {{1}, {1, 2}, {1, 2, 3}};
    std::list<int> expected = {1, 2, 3};
    expectMaxSizeElement(expected, v.begin(), v.end());
}
TEST(MaxSizeElementTest, charListElement) {
    std::vector<std::list<char>> v = {{'a'}, {'a', 'b'}, {'a', 'b', 'c'}};
    std::list<char> expected = {'a', 'b', 'c'};
    expectMaxSizeElement(expected, v.begin(), v.end());
}
TEST(MaxSizeElementTest, charArrayElement) {
    std::vector<std::vector<char>> v = {{'a'}, {'a', 'b'}, {'a', 'b', 'c'}};
    std::vector<char> expected = {'a', 'b', 'c'};
    expectMaxSizeElement(expected, v.begin(), v.end());
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
