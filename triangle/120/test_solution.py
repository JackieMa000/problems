"Leetcode https://leetcode-cn.com/problems/triangle/"

import sys
import unittest
from typing import List


class Solution:
    # DP
    def minimumTotal_1(self, triangle: List[List[int]]) -> int:
        dp = [[0 for _ in row] for row in triangle]
        m = len(triangle)
        dp[m - 1] = triangle[m - 1]
        for i in range(m - 2, -1, -1):
            n = len(triangle[i])
            for j in range(n):
                dp[i][j] = triangle[i][j] + min(dp[i + 1][j], dp[i + 1][j + 1])
        return dp[0][0]

    # DP 一维数组. 状态压缩
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        min_sum = triangle[-1]
        m = len(triangle)
        for i in range(m - 2, -1, -1):
            n = len(triangle[i])
            for j in range(n):
                min_sum[j] = triangle[i][j] + min(min_sum[j], min_sum[j + 1])
        return min_sum[0]

    # 回溯 DFS
    def minimumTotal_2(self, triangle: List[List[int]]) -> int:
        self.min_sum = sys.maxsize
        self.triangle = triangle
        self._dfs(0, 0, 0)
        return self.min_sum

    def _dfs(self, i, j, sum):
        # Recursion Terminator
        if i >= len(self.triangle):
            if self.min_sum > sum: self.min_sum = sum
            return

        # Process
        sum += self.triangle[i][j]

        # Recursion case. Drill down
        self._dfs(i + 1, j, sum)
        self._dfs(i + 1, j + 1, sum)


def minimum_total(input):
    return Solution().minimumTotal(input)


class MyTestCase(unittest.TestCase):
    def test_something(self):
        input = [[2], [3, 4], [6, 5, 7], [4, 1, 8, 3]]
        self.assertEqual(11, minimum_total(input))


if __name__ == '__main__':
    unittest.main()
