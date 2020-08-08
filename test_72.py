# https://leetcode.com/problems/edit-distance/

import unittest


class Solution:
    # DP
    def minDistance(self, word1: str, word2: str) -> int:
        m, n = len(word1), len(word2)
        dp = [[-1 for _ in range(n + 1)] for _ in range(m + 1)]

        for i in range(m + 1): dp[i][0] = i
        for j in range(n + 1): dp[0][j] = j

        for i in range(1, m + 1):
            for j in range(1, n + 1):
                dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j - 1] + 1,
                               dp[i - 1][j - 1] + (0 if word1[i - 1] == word2[j - 1] else 1))

        return dp[m][n]

    # DP
    # 状态定义 dp[i][j] word1前i个字符转换成word2前j个字符所需的最少操作数
    # dp[0]表示空字符串
    # 状态转移方程的两种理解方式：
    # 1. dp[i-1, j] word1 insert, dp[i, j-1] word2 insert. dp[i-1, j-1]替换
    # 2. word1 增加一个字符变为dp[i, j],那么上一个状态就是dp[i-1, j].
    # word1 删除一个字符变为dp[i, j], 那么上一个状态就是dp[i+1, j]，各自往前走一步，变为dp[i, j-1]. dp[i-1, j-1]替换
    def minDistance_1(self, word1: str, word2: str) -> int:
        m, n = len(word1), len(word2)
        dp = [[-1 for _ in range(n + 1)] for _ in range(m + 1)]

        for i in range(m + 1): dp[i][0] = i
        for j in range(n + 1): dp[0][j] = j

        for i in range(1, m + 1):
            for j in range(1, n + 1):
                if word1[i - 1] == word2[j - 1]:
                    dp[i][j] = dp[i - 1][j - 1]
                else:
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + 1

        return dp[m][n]


class MyTestCase(unittest.TestCase):
    def test_something(self):
        self.assertEqual(3, Solution().minDistance('horse', 'ros'))
        self.assertEqual(5, Solution().minDistance('intention', 'execution'))


if __name__ == '__main__':
    unittest.main()
