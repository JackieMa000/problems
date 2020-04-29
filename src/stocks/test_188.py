# https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/

import unittest
from typing import List

from stocks import common


class Solution:
    def maxProfit(self, k: int, prices: List[int]) -> int:
        return common.Solution().maxProfit(k, prices)


class MyTestCase(unittest.TestCase):
    def test_something(self):
        self.assertEqual(0, Solution().maxProfit(2, []))
        self.assertEqual(2, Solution().maxProfit(2, [2, 4, 1]))
        self.assertEqual(7, Solution().maxProfit(2, [3, 2, 6, 5, 0, 3]))
        self.assertEqual(7, Solution().maxProfit(2, [7, 1, 5, 3, 6, 4]))
        self.assertEqual(4, Solution().maxProfit(2, [1, 2, 3, 4, 5]))
        self.assertEqual(0, Solution().maxProfit(2, [7, 6, 4, 3, 1]))
        self.assertEqual(0, Solution().maxProfit(1, [2, 1]))
        self.assertEqual(7, Solution().maxProfit(100, [7, 1, 5, 3, 6, 4]))
        self.assertEqual(0, Solution().maxProfit(100, [2, 1]))
        self.assertEqual(2, Solution().maxProfit(100, [2, 4, 1]))
        self.assertEqual(18, Solution().maxProfit(5, [5, 5, 4, 9, 3, 8, 5, 5, 1, 6, 8, 3, 4]))
        self.assertEqual(6, Solution().maxProfit(2, [3, 3, 5, 0, 0, 3, 1, 4]))


if __name__ == '__main__':
    unittest.main()
