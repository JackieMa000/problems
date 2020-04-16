"Leetcode https://leetcode-cn.com/problems/maximum-product-subarray/"

import sys
import unittest


class Solution(object):
    # DFS. 回溯. 穷举. Recursion
    def maxProduct(self, nums: list) -> int:
        if not nums: return 0
        self.max = -sys.maxsize - 1
        self._dfs(nums, 0, 0)
        return self.max

    def _dfs(self, nums, i, j):
        # Terminator
        if i >= len(nums) or j >= len(nums): return
        # Process
        product = 1
        for num in nums[i:j + 1]:
            product *= num
            if product > self.max:
                self.max = product
        # Recursive case
        self._dfs(nums, i, j + 1)
        self._dfs(nums, i + 1, j + 1)

    # DFS. 回溯. 穷举.
    def maxProduct_4(self, nums: list) -> int:
        if not nums: return 0
        max = -sys.maxsize - 1
        m = len(nums)
        for i in range(m):
            for j in range(i, m):
                sub_nums = nums[i:j+1]
                product = 1
                n = len(sub_nums)
                for k in range(n):
                    product *=sub_nums[k]
                if product > max:
                    max = product
        return max

    # DP  一维数组
    def maxProduct_3(self, nums: list) -> int:
        if not nums: return 0
        res, curMax, curMin = nums[0], nums[0], nums[0]
        for i in range(1, len(nums)):
            cur = nums[i]
            curMax, curMin = max(curMax * cur, curMin * cur, cur), min(curMax * cur, curMin * cur, cur)
            if curMax > res:
                res = curMax
        return res

    # DP 二维数组  扩展性强. 滚动数组，状态压缩，逻辑压缩
    def maxProduct_2(self, nums: list) -> int:
        if not nums: return 0
        dp = [[0, 0] for _ in range(2)]
        dp[0][0], dp[0][1], res = nums[0], nums[0], nums[0]
        for i in range(1, len(nums)):
            x, y = i % 2, (i - 1) % 2
            dp[x][0] = max(dp[y][0] * nums[i], dp[y][1] * nums[i], nums[i])
            dp[x][1] = min(dp[y][0] * nums[i], dp[y][1] * nums[i], nums[i])
            res = max(res, dp[x][0])
        return res

    # DP 二维数组  扩展性强. 最直接的解法，没有tricks，没有状态压缩
    def maxProduct_1(self, nums: list) -> int:
        if not nums: return 0
        dp = [[0, 0] for _ in nums]
        dp[0] = [nums[0] for _ in range(2)]
        for i in range(1, len(nums)):
            if nums[i] >= 0:
                dp[i][0] = max(dp[i - 1][0] * nums[i], nums[i])
                dp[i][1] = min(dp[i - 1][1] * nums[i], nums[i])
            else:
                dp[i][0] = max(dp[i - 1][1] * nums[i], nums[i])
                dp[i][1] = min(dp[i - 1][0] * nums[i], nums[i])

        return max(map(lambda x: x[0], dp))


def max_product(input):
    return Solution().maxProduct(input)


class MyTestCase(unittest.TestCase):
    def test_something(self):
        input = [2, 3, -2, 4]
        self.assertEqual(6, max_product(input))
        input = [-2, 0, -1]
        self.assertEqual(0, max_product(input))
        input = []
        self.assertEqual(0, max_product(input))
        input = [0, 2]
        self.assertEqual(2, max_product(input))
        input = [-4,-3,-2]
        self.assertEqual(12, max_product(input))


if __name__ == '__main__':
    unittest.main()
