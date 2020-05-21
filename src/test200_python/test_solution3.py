import collections
import unittest
from typing import List


class Solution:
    def isvalid(self, node: int) -> bool:
        i, j = node // self.n, node % self.n
        if i < 0 or i >= self.m or j < 0 or j >= self.n or self.grid[i][j] == '0' or node in self.found:
            return False
        return True

    def search_island_dfs(self, node: int) -> int:
        if not self.isvalid(node): return 0
        i, j = node // self.n, node % self.n
        self.found.add(node)

        for k in range(4):
            x, y = self.dx[k] + i, self.dy[k] + j
            node = x * self.n + y
            if node in self.found: continue
            self.search_island_dfs(node)

        return 1

    def generate_related_nodes(self, node: int) -> List[int]:
        i, j = node // self.n, node % self.n
        res = []
        for k in range(4):
            x, y = self.dx[k] + i, self.dy[k] + j
            if 0 <= x < self.m and 0 <= y < self.n and self.grid[x][y] == '1':
                res.append(x * self.n + y)
        return res

    def search_island_bfs(self, node: int) -> int:
        if not self.isvalid(node): return 0

        queue = collections.deque()
        queue.append(node)
        while queue:
            node = queue.popleft()
            if node in self.found: continue
            self.found.add(node)
            queue += self.generate_related_nodes(node)
        return 1

    def numIslands(self, grid: List[List[str]]) -> int:
        self.grid = grid
        if not self.grid or not self.grid[0]: return 0

        self.dx = [0, 0, -1, 1]
        self.dy = [1, -1, 0, 0]
        self.found = set()

        self.m, self.n = len(self.grid), len(self.grid[0])

        res = []
        for i in range(self.m):
            for j in range(self.n):
                if self.grid[i][j] == '1':
                    res.append(self.search_island_dfs(i * self.n + j))

        return sum(res)


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
