from unittest import TestCase

from dsa.lib.math.nums.two_sum import TwoSum


class TestTwoSum(TestCase):
    def test_two_sum(self):
        self.assertEqual([0, 1], self.two_sum([2, 7, 11, 15], 9))
        self.assertEqual([1, 2], self.two_sum([3, 2, 4], 6))
        self.assertEqual([0, 1], self.two_sum([3, 3], 6))
        self.assertEqual([], self.two_sum([1, 2], 7))

    @staticmethod
    def two_sum(nums, target):
        return TwoSum.twoSum(nums, target)
