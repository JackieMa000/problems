import unittest
from typing import List


class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        n1, n2 = len(nums1), len(nums2)
        n = n1 + n2
        nums = []

        i = 0
        i1, i2 = 0, 0
        while i1 < n1 and i2 < n2 and i <= n // 2:
            if nums1[i1] < nums2[i2]:
                nums.append(nums1[i1])
                i1 += 1
            else:
                nums.append(nums2[i2])
                i2 += 1
            i += 1

        if i - 1 < n // 2:
            if i1 == n1:
                nums += nums2[i2:]
            else:
                nums += nums1[i1:]

        if n & 1:
            return float(nums[n // 2])
        else:
            return float((nums[(n - 1) // 2] + nums[n // 2]) / 2)


class MyTestCase(unittest.TestCase):
    def test_something(self):
        self.assertEqual(2.0, Solution().findMedianSortedArrays([1, 3], [2]))
        self.assertEqual(2.5, Solution().findMedianSortedArrays([1, 2], [3, 4]))


if __name__ == '__main__':
    unittest.main()
