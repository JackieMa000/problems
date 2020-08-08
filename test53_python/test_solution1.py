import unittest
from typing import List


# DP
class Solution:
    # DP 状态压缩
    def maxSubArray(self, nums: List[int]) -> int:
        res = sum = nums[0]
        for i in range(1, len(nums)):
            sum = max(nums[i], sum + nums[i])
            res = max(res, sum)
        return res

    def maxSubArray_2(self, nums: List[int]) -> int:
        n = len(nums)
        # Initialize
        dp = [0] * n
        dp[0] = nums[0]

        for i in range(1, n):
            dp[i] = max(dp[i - 1] + nums[i], nums[i])

        return max(dp)

    # dp[i] means the max sum of contiguous sub array of 0~i, contains array[i]
    def maxSubArray_1(self, nums: List[int]) -> int:
        n = len(nums)
        dp = [0] * n
        dp[0] = nums[0]  # Initialize
        for i in range(1, n):
            dp[i] = nums[i] + (0 if dp[i - 1] < 0 else dp[i - 1])
        return max(dp)


class MyTestCase(unittest.TestCase):
    def test_something(self):
        self.assertEqual(6, Solution().maxSubArray([-2, 1, -3, 4, -1, 2, 1, -5, 4]))


if __name__ == '__main__':
    unittest.main()
