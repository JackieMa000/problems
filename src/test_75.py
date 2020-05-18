# https://leetcode-cn.com/problems/sort-colors/

import unittest
from typing import List


class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        sums = [0 for _ in range(max(nums) + 1)]
        for i in range(len(nums)):
            sums[nums[i]] += 1

        count = 0
        for i in range(len(sums)):
            for _ in range(sums[i]):
                nums[count] = i
                count += 1

        return nums

    def sortColors_1(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        sums = [0 for _ in range(max(nums) + 1)]
        for i in range(len(nums)):
            sums[nums[i]] += 1

        nums = []
        for i in range(len(sums)):
            nums += [i] * sums[i]

        return nums


class MyTestCase(unittest.TestCase):
    def test_something(self):
        self.assertEqual([0, 0, 1, 1, 2, 2], Solution().sortColors([2, 0, 2, 1, 1, 0]))


if __name__ == '__main__':
    unittest.main()
