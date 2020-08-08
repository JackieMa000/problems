import sys
import unittest
from typing import List


class Solution:
    # DFS. Memorization
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        found = [[sys.maxsize + 1 for _ in range(len(triangle[row]))] for row in range(len(triangle))]
        return self.minsum_dfs(triangle, 0, 0, found)

    def minsum_dfs(self, triangle: List[List[int]], i: int, j: int, found: List[List[int]]) -> int:
        # terminator
        if i >= len(triangle): return 0
        if found[i][j] != sys.maxsize + 1: return found[i][j]
        # Recursive
        down_left = self.minsum_dfs(triangle, i + 1, j, found)
        down_right = self.minsum_dfs(triangle, i + 1, j + 1, found)
        found[i][j] = triangle[i][j] + min(down_left, down_right)

        return found[i][j]


class Solution1:
    # 回溯 DFS
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        return self.minsum_dfs(triangle, 0, 0)

    def minsum_dfs(self, triangle: List[List[int]], i: int, j: int) -> int:
        # terminator
        if i >= len(triangle): return 0
        # Recursive
        down_left = self.minsum_dfs(triangle, i + 1, j)
        down_right = self.minsum_dfs(triangle, i + 1, j + 1)
        return triangle[i][j] + min(down_left, down_right)


class Solution2:
    # 回溯 DFS
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        self.min_sum = sys.maxsize
        self.triangle = triangle
        self._dfs(0, 0, 0)
        return self.min_sum

    def _dfs(self, i: int, j: int, sum: int):
        # Terminator
        if i >= len(self.triangle):
            if self.min_sum > sum: self.min_sum = sum
            return

        # Process
        sum += self.triangle[i][j]

        # Recursion case. Drill down
        self._dfs(i + 1, j, sum)
        self._dfs(i + 1, j + 1, sum)


class MyTestCase(unittest.TestCase):
    def test_something(self):
        input = [[2], [3, 4], [6, 5, 7], [4, 1, 8, 3]]
        self.assertEqual(11, Solution().minimumTotal(input))


class MyTestCase1(unittest.TestCase):
    def test_something(self):
        input = [[2], [3, 4], [6, 5, 7], [4, 1, 8, 3]]
        self.assertEqual(11, Solution1().minimumTotal(input))


class MyTestCase2(unittest.TestCase):
    def test_something(self):
        input = [[2], [3, 4], [6, 5, 7], [4, 1, 8, 3]]
        self.assertEqual(11, Solution2().minimumTotal(input))
