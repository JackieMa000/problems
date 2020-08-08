import unittest
from typing import List


# SortFind. Two points
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        n = len(nums)
        if n < 3: return []

        res = []
        nums.sort()
        for i in range(n - 2):
            if i >= 1 and nums[i] == nums[i - 1]: continue
            left, right = i + 1, n - 1
            while left < right:
                s = nums[i] + nums[left] + nums[right]
                if s == 0:
                    res.append([nums[i], nums[left], nums[right]])
                    while left < right and nums[left] == nums[left + 1]: left += 1
                    while left < right and nums[right] == nums[right - 1]: right -= 1
                    left += 1;
                    right -= 1
                elif s < 0:
                    left += 1
                else:
                    right -= 1
        return res

    def threeSum_1(self, nums: List[int]) -> List[List[int]]:
        n = len(nums)
        if n < 3: return []

        res = []

        # 为了下边判重和双指针
        nums.sort()

        for i in range(n - 2):
            # 去除a重复
            if i >= 1 and nums[i] == nums[i - 1]:
                continue
            left, right = i + 1, n - 1
            while left < right:
                s = nums[i] + nums[left] + nums[right]
                if s == 0:
                    res.append([nums[i], nums[left], nums[right]])
                    # 判重
                    while left < right and nums[left] == nums[left + 1]:
                        left += 1
                    while left < right and nums[right] == nums[right - 1]:
                        right -= 1
                    right -= 1
                    left += 1
                elif s < 0:
                    left += 1
                else:
                    right -= 1
        return res


class MyTestCase(unittest.TestCase):
    def test_something(self):
        self.assertEqual([[0, 0, 0]], Solution().threeSum([0, 0, 0, 0]))
        self.assertEqual([[-2, 0, 2]], Solution().threeSum([-2, 0, 0, 2, 2]))
        self.assertEqual([[-1, 0, 1]], Solution().threeSum([-1, 0, 1, 0]))
        self.assertEqual([[-1, -1, 2], [-1, 0, 1]], Solution().threeSum([-1, 0, 1, 2, -1, -4]))
