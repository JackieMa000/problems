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

}
}
