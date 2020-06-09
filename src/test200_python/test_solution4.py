import unittest
from typing import List

from .quickUF import UnionFind


class Solution:
    # Union&Find
    def numIslands(self, grid: List[List[str]]) -> int:
        if not grid or not grid[0]: return 0

        uf = UnionFind(grid)
        m, n = len(grid), len(grid[0])

        directions = [(0, 1), (0, -1), (-1, 0), (1, 0)]

        for i in range(m):
            for j in range(n):
                if grid[i][j] == '0': continue
                for d in directions:
                    x, y = d[0] + i, d[1] + j
                    if 0 <= x < m and 0 <= y < n and grid[x][y] == '1':
                        uf.union(i * n + j, x * n + y)
        return uf.count


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
