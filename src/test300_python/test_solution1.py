import unittest
from typing import List


class Solution:
    # DP
    def lengthOfLIS_1(self, nums: List[int]) -> int:
        if not nums: return 0
        n = len(nums)
        # dp[j]到达位置i的最长子序列的长度，包含a[j]
        # DP方程：dp[j] = max(dp[i]) + 1. i: (0, j-1)
        # Initialize
        dp = [1 for _ in range(n)]
        for j in range(1, n):
            for i in range(j):
                if nums[i] < nums[j]:
                    dp[j] = max(dp[j], dp[i] + 1)
        return max(dp)

    # DP
    def lengthOfLIS(self, nums: List[int]) -> int:
        if not nums: return 0
        n = len(nums)
        # dp[j]到达位置i的最长子序列的长度，包含a[j]
        # DP方程：dp[j] = max(dp[i]) + 1. i: (0, j-1)
        dp = [1 for _ in range(n)]
        for j in range(1, n):
            subs = [0]
            for i in range(j):
                if nums[i] < nums[j]:
                    subs.append(dp[i])
            dp[j] = max(subs) + 1
        return max(dp)


class MyTestCase(unittest.TestCase):
    def test_something(self):
        self.assertEqual(0, Solution().lengthOfLIS([]))
        self.assertEqual(4, Solution().lengthOfLIS([10, 9, 2, 5, 3, 7, 101, 18]))
        self.assertEqual(5, Solution().lengthOfLIS([10, 9, 2, 5, 3, 7, 101, 18, 20]))
        self.assertEqual(4, Solution().lengthOfLIS([10, 11, 12, 13, 1, 2, 3, 4]))
