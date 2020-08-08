# https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

import unittest
from typing import List


class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        maxProfit = 0
        for i in range(len(prices) - 1):
            if prices[i + 1] > prices[i]:
                maxProfit += (prices[i + 1] - prices[i])
        return maxProfit


class MyTestCase(unittest.TestCase):
    def test_solution(self):
        self.assertEqual(7, Solution().maxProfit([7, 1, 5, 3, 6, 4]))
        self.assertEqual(4, Solution().maxProfit([1, 2, 3, 4, 5]))
        self.assertEqual(0, Solution().maxProfit([7, 6, 4, 3, 1]))


if __name__ == '__main__':
    unittest.main()
