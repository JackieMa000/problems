# https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/

import unittest

from typing import List


class Solution:
    # 空间压缩，滚动数组
    def maxProfit(self, prices: List[int], fee: int) -> int:
        if not prices: return 0
        n = len(prices)
        MP = [[0, 0] for _ in range(2)]
        # Initialize the data for the 1st day
        MP[0] = [0, -prices[0] - fee]
        for i in range(1, n):
            x, y = i & 1, (i - 1) & 1
            MP[x][0] = max(MP[y][0], MP[y][1] + prices[i])
            MP[x][1] = max(MP[y][1], MP[y][0] - prices[i] - fee)
        return MP[(n - 1) & 1][0]

    def maxProfit_1(self, prices: List[int], fee: int) -> int:
        if not prices: return 0
        n = len(prices)
        MP = [[0, 0] for _ in range(n)]
        # Initialize the data for the 1st day
        MP[0] = [0, -prices[0] - fee]

        for i in range(1, n):
            MP[i][0] = max(MP[i - 1][0], MP[i - 1][1] + prices[i])
            MP[i][1] = max(MP[i - 1][1], MP[i - 1][0] - prices[i] - fee)

        return MP[n - 1][0]


class MyTestCase(unittest.TestCase):
    def test_something(self):
        prices = [1, 3, 2, 8, 4, 9]
        fee = 2
        self.assertEqual(8, Solution().maxProfit(prices, fee))


if __name__ == '__main__':
    unittest.main()
