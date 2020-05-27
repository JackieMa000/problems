import sys
import unittest
from typing import List


class Solution:
    # Divide & Conque
    def maxSubArray(self, nums: List[int]) -> int:
        return self.helper(nums, 0, len(nums) - 1)

    def helper(self, nums: List[int], left: int, right: int) -> int:
        # Terminator
        if left > right: return -sys.maxsize - 1

        mid = left + (right - left) // 2
        # left max sum
        lmax = self.helper(nums, left, mid - 1)
        # Right max sum
        rmax = self.helper(nums, mid + 1, right)
        # Mid max sum
        # Mid left max sum
        ml = 0;
        sum = 0
        for i in range(mid - 1, left - 1, -1):
            sum += nums[i]
            ml = max(ml, sum)
        # Mid right max sum
        mr = 0;
        sum = 0
        for i in range(mid + 1, right + 1):
            sum += nums[i]
            mr = max(mr, sum)

        return max(lmax, rmax, ml + nums[mid] + mr)

    def maxSubArray_1(self, nums: List[int]) -> int:
        def dnc(nums, l, r):
            if not nums or r < l:
                return 0, 0, 0, 0
            if l == r:
                return nums[l], nums[l], nums[l], nums[l]
            m = (l + r) // 2
            llms, lrms, lmms, ls = dnc(nums, l, m)  # left max, right max, mid max, sum of left
            rlms, rrms, rmms, rs = dnc(nums, m + 1, r)  # left max, right max, mid max, sum of right
            lms = max(llms, ls + rlms)
            rms = max(rrms, rs + lrms)
            mms = max(lmms, rmms, lrms + rlms)
            s = ls + rs
            return lms, rms, mms, s  # left max sum, right max sum, mid max sum, sum of merge

        return dnc(nums, 0, len(nums) - 1)[2]


class MyTestCase(unittest.TestCase):
    def test_something(self):
        self.assertEqual(6, Solution().maxSubArray([-2, 1, -3, 4, -1, 2, 1, -5, 4]))
