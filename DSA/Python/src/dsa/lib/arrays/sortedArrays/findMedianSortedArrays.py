# LeetCode4
from typing import List


class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        nums = self.merge(nums1, nums2)
        n = len(nums)

        is_odd: bool = (n & 1 == 1)
        return float(nums[n // 2]) if is_odd else \
            float((nums[(n - 1) // 2] + nums[n // 2]) / 2)

    def merge(self, nums1, nums2):
        """
        :param nums1:
        :param nums2:
        :return:  merged sorted array
        """
        n1, n2 = len(nums1), len(nums2)
        n = n1 + n2

        nums = []
        i1, i2 = 0, 0

        while i1 < n1 and i2 < n2:
            if nums1[i1] < nums2[i2]:
                nums.append(nums1[i1])
                i1 += 1
            else:
                nums.append(nums2[i2])
                i2 += 1

        if len(nums) < n:
            if i1 < n1:
                nums += nums1[i1:]
            else:
                nums += nums2[i2:]

        return nums
