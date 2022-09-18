#include <dsa/lib/math/ds/palindrome.hpp>

namespace dsa::lib::math::ds {
namespace {

std::string getLongestPalindrome(std::string &&s) {
    auto r1 = Palindrome().longestPalindrome(s);
    auto r2 = Palindrome().longestPalindrome1(s);
    assert(r1 == r2 && "Results from 2 same functions are different.");

    return r1;
}
TEST(LongestPalindromeTest, emptyString) {
    EXPECT_EQ("", getLongestPalindrome(""));
}
TEST(LongestPalindromeTest, oneChar) {
    EXPECT_EQ("a", getLongestPalindrome("a"));
}
TEST(LongestPalindromeTest, case1) {
    EXPECT_EQ("aa", getLongestPalindrome("aa"));
    EXPECT_EQ("bab", getLongestPalindrome("babd"));
    EXPECT_EQ("bb", getLongestPalindrome("cbbd"));
    EXPECT_EQ("aaaa", getLongestPalindrome("aaaa"));
}

}  // namespace
}  // namespace dsa::lib::math::ds
