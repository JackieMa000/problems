import unittest


class Solution:
    def longestPalindrome(self, s: str) -> str:
        if not s or len(s) == 1: return s
        res = ''

        for i in range(len(s)):
            odd = self.expand_around_center(s, i, i)  # Palindrome Odd case
            even = self.expand_around_center(s, i, i + 1)  # Palindrome Even case
            res = max(res, odd, even, key=len)

        return res

    def expand_around_center(self, s: str, left: int, right: int) -> str:
        while 0 <= left and right < len(s) and s[left] == s[right]:
            left -= 1
            right += 1

        return s[left + 1: right]


class MyTestCase(unittest.TestCase):
    def test_something(self):
        self.assertEqual("bab", Solution().longestPalindrome("babad"))
        self.assertEqual("bb", Solution().longestPalindrome("cbbd"))
        self.assertEqual("a", Solution().longestPalindrome("a"))
        self.assertEqual("", Solution().longestPalindrome(""))
        self.assertEqual("aaaa", Solution().longestPalindrome("aaaa"))


if __name__ == '__main__':
    unittest.main()
