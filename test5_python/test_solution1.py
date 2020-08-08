import unittest


class Solution:
    # dp[i][j] means whether or not it's panlindrome from i to j(including a[j])
    def longestPalindrome(self, s: str) -> str:
        if not s or len(s) == 1: return s

        n = len(s)
        dp = [[False for _ in range(n)] for _ in range(n)]

        # Initialize
        for i in range(n):
            dp[i][i] = True

        res = ''
        for i in range(n - 1, -1, -1):
            for j in range(i, n):
                dp[i][j] = (s[i] == s[j] and (j - i < 3 or dp[i + 1][j - 1]))

                if dp[i][j] and j - i + 1 > len(res):
                    res = s[i:j + 1]

        return res


class MyTestCase(unittest.TestCase):
    def test_something(self):
        self.assertEqual("aba", Solution().longestPalindrome("babad"))
        self.assertEqual("bb", Solution().longestPalindrome("cbbd"))
        self.assertEqual("a", Solution().longestPalindrome("a"))
        self.assertEqual("", Solution().longestPalindrome(""))
        self.assertEqual("aaaa", Solution().longestPalindrome("aaaa"))
