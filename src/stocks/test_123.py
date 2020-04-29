# https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/

import unittest
from typing import List

from stocks import common


class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        return self._helper(prices)

    def _helper(self, prices):
        return common.Solution().maxProfit(2, prices)


class MyTestCase(unittest.TestCase):
    def test_something(self):
        self.assertEqual(6, Solution().maxProfit([3, 3, 5, 0, 0, 3, 1, 4]))
        self.assertEqual(4, Solution().maxProfit([1, 2, 3, 4, 5]))
        self.assertEqual(0, Solution().maxProfit([7, 6, 4, 3, 1]))


if __name__ == '__main__':
    unittest.main()
