#include <forward_list>

#include <dsa/lib/utils/algorithm.hpp>
#include <dsa/lib/libdef.h>

namespace dsa {
namespace {

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

}
}