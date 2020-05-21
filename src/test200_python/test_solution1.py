import unittest
from typing import List


class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        self.grid = grid
        if not self.grid or not self.grid[0]: return 0

        self.dx = [0, 0, -1, 1]
        self.dy = [1, -1, 0, 0]

        self.m, self.n = len(self.grid), len(self.grid[0])
        count = 0
        for i in range(self.m):
            for j in range(self.n):
                if self.grid[i][j] == '1':
                    count += 1
                    self.floodfill_dfs(i, j)
        return count

    def floodfill_dfs(self, i: int, j: int) -> None:
        # Terminator. Boundry
        if i >= self.m or i < 0 or j >= self.n or j < 0 or self.grid[i][j] == '0': return

        # Process
        self.grid[i][j] = '0'
        # Recursive Case
        for k in range(4):
            x, y = self.dx[k] + i, self.dy[k] + j
            self.floodfill_dfs(x, y)


class MyTestCase(unittest.TestCase):
    def test_empty(self):
        grid = [[]]
        self.assertEqual(0, Solution().numIslands(grid))

    def test_one_island(self):
        grid = [["1", "1", "1", "1", "0"], ["1", "1", "0", "1", "0"], ["1", "1", "0", "0", "0"],
                ["0", "0", "0", "0", "0"]]
        self.assertEqual(1, Solution().numIslands(grid))

        grid = [["1", "1", "1"], ["0", "1", "0"], ["1", "1", "1"]]
        self.assertEqual(1, Solution().numIslands(grid))

    def test_three_islands(self):
        grid = [["1", "1", "0", "0", "0"], ["1", "1", "0", "0", "0"], ["0", "0", "1", "0", "0"],
                ["0", "0", "0", "1", "1"]]
        self.assertEqual(3, Solution().numIslands(grid))


if __name__ == '__main__':
    unittest.main()
