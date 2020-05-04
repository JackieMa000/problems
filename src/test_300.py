# https://leetcode.com/problems/longest-increasing-subsequence/
import sys
import unittest
from typing import List


class Solution:
    # Recursion
    def greater_than_1(self, target: int, nums: List[int]) -> int:
        def dfs(left, right, target, nums):
            # Terminator
            if left > right: return left
            # Recursive case
            mid = left + (right - left) // 2
            if nums[mid] < target:
                return dfs(mid + 1, right, target, nums)
            else:
                return dfs(left, mid - 1, target, nums)

        return dfs(0, len(nums) - 1, target, nums)

    def greater_than(self, target: int, nums: List[int]) -> int:
        # Find the the position of smallest num in the list which is greater than n by Binary Search
        # Return the size of list if it's not found.
        # nums should be a sorted list
        left, right = 0, len(nums) - 1
        while left <= right:
            mid = left + (right - left) // 2
            if nums[mid] < target:
                left = mid + 1
            else:
                right = mid - 1
        return left

    # Binary Search. List[lis] is the list of largest increasing sequence. It doesn't mean that it's absolutely
    # increased, but the size of the list should be the same with increasing sequence.
    def lengthOfLIS(self, nums: List[int]) -> int:
        if not nums: return 0
        lis = [nums[0]]
        for i in range(1, len(nums)):
            pos = self.greater_than(nums[i], lis)
            if pos < len(lis):
                lis[pos] = nums[i]
            else:
                lis.append(nums[i])
        return len(lis)

    # DFS with memorization
    def lengthOfLIS_4(self, nums: List[int]) -> int:
        n = len(nums)
        visited = [[-1 for _ in range(n)] for _ in range(n + 1)]
        return self.DFS(nums, -1, 0, visited)

    def DFS(self, nums: list, prevpos: int, curpos: int, visited: List[list]):
        # Terminator
        if curpos == len(nums): return 0
        if visited[prevpos + 1][curpos] >= 0:
            return visited[prevpos + 1][curpos]

        # Recursive case
        taken: int = 0
        # Including
        if prevpos < 0 or nums[curpos] > nums[prevpos]:
            taken = 1 + self.DFS(nums, curpos, curpos + 1, visited)
        # Not including
        notaken: int = self.DFS(nums, prevpos, curpos + 1, visited)

        visited[prevpos + 1][curpos] = max(taken, notaken)
        return visited[prevpos + 1][curpos]

    # Brute Force 穷举，回朔
    def lengthOfLIS_3(self, nums: List[int]) -> int:
        if not nums: return 0
        return self._dfs(nums, 0, -sys.maxsize - 1)

    def _dfs(self, nums, curpos, prev):
        # Terminator
        if curpos == len(nums): return 0
        taken = 0
        # Recursive case
        if nums[curpos] > prev:
            taken = 1 + self._dfs(nums, curpos + 1, nums[curpos])
        notaken = self._dfs(nums, curpos + 1, prev)
        return max(taken, notaken)

    # DP
    def lengthOfLIS_2(self, nums: List[int]) -> int:
        if not nums: return 0
        n = len(nums)
        # dp[i]到达位置i的最长子序列的长度，包含a[i]
        # DP方程：dp[i] = max(dp[j]) + 1. j: (0, i-1)
        dp = [1 for _ in range(n)]
        for i in range(1, n):
            for j in range(i):
                if nums[j] < nums[i]:
                    dp[i] = max(dp[i], dp[j] + 1)
        return max(dp)

    # DP
    def lengthOfLIS_1(self, nums: List[int]) -> int:
        if not nums: return 0
        n = len(nums)
        # dp[i]到达位置i的最长子序列的长度，包含a[i]
        # DP方程：dp[i] = max(dp[j]) + 1. j: (0, i-1)
        dp = [1 for _ in range(n)]
        for i in range(1, n):
            subs = [0]
            for j in range(i):
                if nums[j] < nums[i]:
                    subs.append(dp[j])
            dp[i] = max(subs) + 1
        return max(dp)


class MyTestCase(unittest.TestCase):
    def test_something(self):
        self.assertEqual(0, Solution().lengthOfLIS([]))
        self.assertEqual(4, Solution().lengthOfLIS([10, 9, 2, 5, 3, 7, 101, 18]))
        self.assertEqual(5, Solution().lengthOfLIS([10, 9, 2, 5, 3, 7, 101, 18, 20]))
        self.assertEqual(4, Solution().lengthOfLIS([10, 11, 12, 13, 1, 2, 3, 4]))

    def test_greater_than(self):
        self.assertEqual(0, Solution().greater_than(1, []))
        self.assertEqual(0, Solution().greater_than(9, [10]))
        self.assertEqual(1, Solution().greater_than(4, [3, 6, 7, 10]))
        self.assertEqual(3, Solution().greater_than(10, [3, 6, 7, 10]))
        self.assertEqual(4, Solution().greater_than(11, [3, 6, 7, 10]))
        self.assertEqual(3, Solution().greater_than(8, [3, 6, 7, 10]))
        self.assertEqual(1, Solution().greater_than(5, [3, 6, 7, 10]))


if __name__ == '__main__':
    unittest.main()
