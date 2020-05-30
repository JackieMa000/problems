import sys
import unittest
from typing import List


class Solution:
    # DFS with memorization
    def lengthOfLIS(self, nums: List[int]) -> int:
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
        # Including the current element in the LIS
        if prevpos < 0 or nums[prevpos] < nums[curpos]:
            taken = 1 + self.DFS(nums, curpos, curpos + 1, visited)
        # Not including
        notaken: int = self.DFS(nums, prevpos, curpos + 1, visited)

        visited[prevpos + 1][curpos] = max(taken, notaken)
        return visited[prevpos + 1][curpos]

    # Brute Force 穷举，回朔
    def lengthOfLIS_1(self, nums: List[int]) -> int:
        if not nums: return 0
        return self._dfs(nums, -sys.maxsize - 1, 0)

    def _dfs(self, nums, prev, curpos):
        # Terminator
        if curpos == len(nums): return 0
        taken = 0
        # Recursive case
        if nums[curpos] > prev:
            taken = 1 + self._dfs(nums, nums[curpos], curpos + 1)
        notaken = self._dfs(nums, prev, curpos + 1)
        return max(taken, notaken)


class MyTestCase(unittest.TestCase):
    def test_something(self):
        self.assertEqual(0, Solution().lengthOfLIS([]))
        self.assertEqual(4, Solution().lengthOfLIS([10, 9, 2, 5, 3, 7, 101, 18]))
        self.assertEqual(5, Solution().lengthOfLIS([10, 9, 2, 5, 3, 7, 101, 18, 20]))
        self.assertEqual(4, Solution().lengthOfLIS([10, 11, 12, 13, 1, 2, 3, 4]))
