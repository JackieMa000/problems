# https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/

import unittest
from typing import List


class Solution:
    # 空间压缩，滚动数组
    def maxProfit(self, prices: List[int]) -> int:
        if not prices: return 0
        n = len(prices)
        MP = [[0, 0, 0] for _ in range(2)]
        # Initialize the data for the first day
        MP[0] = [0, -prices[0], 0]

        # MP[i-1, 0]只能表示前一天卖了一股, 因为MP[i][2] = MP[i-1][0]
        for i in range(1, n):
            x, y = i % 2, (i - 1) % 2
            MP[x][0] = max(MP[y][0], MP[y][1] + prices[i])
            MP[x][1] = max(MP[y][1], MP[y][2] - prices[i])
            MP[x][2] = MP[y][0]

        return max(MP[(n - 1) % 2][0], MP[(n - 1) % 2][2])

    # 状态压缩。使用二维数据 MP[i,j]. j=(0, 1, 2). 2表示为冷冻期
    def maxProfit_1(self, prices: List[int]) -> int:
        if not prices: return 0
        n = len(prices)
        MP = [[0, 0, 0] for _ in range(n)]
        # Initialize the data for the first day
        MP[0] = [0, -prices[0], 0]

        # MP[i-1, 0]只能表示前一天卖了一股, 因为MP[i][2] = MP[i-1][0]
        for i in range(1, n):
            MP[i][0] = max(MP[i - 1][0], MP[i - 1][1] + prices[i])
            MP[i][1] = max(MP[i - 1][1], MP[i - 1][2] - prices[i])
            MP[i][2] = MP[i - 1][0]

        return max(MP[n - 1][0], MP[n - 1][2])

    def maxProfit_1(self, prices: List[int]) -> int:
        if not prices: return 0
        n = len(prices)
        MP = [[[0, 0] for _ in range(2)] for _ in range(n)]
        # Initialize the data for the first day
        MP[0][0] = [0, -prices[0]]

        for i in range(1, n):
            MP[i][0][0] = max(MP[i - 1][0][0], MP[i - 1][0][1] + prices[i])
            MP[i][1][0] = MP[i - 1][0][0]
            MP[i][0][1] = max(MP[i - 1][0][1], MP[i - 1][1][0] - prices[i])

        return max(map(lambda x: x[0], MP[-1]))


class MyTestCase(unittest.TestCase):
    def test_something(self):
        self.assertEqual(3, Solution().maxProfit([1, 2, 3, 0, 2]))
        self.assertEqual(7, Solution().maxProfit([6, 1, 6, 4, 3, 0, 2]))


if __name__ == '__main__':
    unittest.main()
