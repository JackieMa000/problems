import unittest
from typing import List


class Solution:
    # DP dp[i][j] means the minimum path sum from bottom to the position [i, j]
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        # dp Initialize
        m = len(triangle)
        dp = [[0 for _ in range(len(triangle[row]))] for row in range(m)]
        dp[m - 1] = triangle[m - 1]

        # dp formula
        for i in range(m - 2, -1, -1):
            n = len(triangle[i])
            for j in range(n):
                dp[i][j] = triangle[i][j] + min(dp[i + 1][j], dp[i + 1][j + 1])

        # dp result
        return dp[0][0]


class Solution1:
    # DP 一维数组. 状态压缩. min_sum[j] means the minimum path sum from bottom to position j of the current row.
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        # dp Initialize
        min_sum = triangle[-1]

        # dp formula
        m = len(triangle)
        for i in range(m - 2, -1, -1):
            n = len(triangle[i])
            for j in range(n):
                min_sum[j] = triangle[i][j] + min(min_sum[j], min_sum[j + 1])

        # dp result
        return min_sum[0]


class MyTestCase(unittest.TestCase):
    def test_something(self):
        input = [[2], [3, 4], [6, 5, 7], [4, 1, 8, 3]]
        self.assertEqual(11, Solution().minimumTotal(input))


class MyTestCase1(unittest.TestCase):
    def test_something(self):
        input = [[2], [3, 4], [6, 5, 7], [4, 1, 8, 3]]
        self.assertEqual(11, Solution1().minimumTotal(input))


if __name__ == '__main__':
    unittest.main()
