# https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

import sys
import unittest
from typing import List

from stocks import common


class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if not prices: return 0
        min = sys.maxsize
        max_profit = 0
        for i in range(len(prices)):
            if prices[i] < min:
                min = prices[i]
            if prices[i] - min > max_profit:
                max_profit = prices[i] - min
        return max_profit

    def maxProfit_2(self, prices: List[int]) -> int:
        if not prices: return 0
        min = sys.maxsize
        max_profit = 0
        for p in prices:
            if p < min:
                min = p
            if p - min > max_profit:
                max_profit = p - min
        return max_profit

    def maxProfit_1(self, prices: List[int]) -> int:
        return common.Solution().maxProfit(1, prices)


class MyTestCase(unittest.TestCase):
    def test_something(self):
        self.assertEqual(5, Solution().maxProfit([7, 1, 5, 3, 6, 4]))
        self.assertEqual(0, Solution().maxProfit([7, 6, 4, 3, 1]))


if __name__ == '__main__':
    unittest.main()
