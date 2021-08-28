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

}
}
