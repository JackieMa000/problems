import unittest
from typing import List

from dsa.lib.math.nums.three_sum import ThreeSum


class ThreeSumTest(unittest.TestCase):
    def test_case1(self):
        self.assertEqual([[0, 0, 0]], self.three_sum([0, 0, 0, 0]))
        self.assertEqual([[-2, 0, 2]], self.three_sum([-2, 0, 0, 2, 2]))
        self.assertEqual([[-1, 0, 1]], self.three_sum([-1, 0, 1, 0]))

    def test_case2(self):
        self.assertIn([-1, -1, 2], [[-1, -1, 2], [-1, 0, 1]])
        self.assertIn([-1, 0, 1], [[-1, -1, 2], [-1, 0, 1]])

    @staticmethod
    def three_sum(nums: List[int]):
        return ThreeSum().threeSum(nums)
