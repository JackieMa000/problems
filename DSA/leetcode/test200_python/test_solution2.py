import unittest
from typing import List


class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        self.grid = grid
        if not self.grid or not self.grid[0]: return 0

        self.dx = [0, 0, -1, 1]
        self.dy = [1, -1, 0, 0]
        self.visited = set()

        self.m, self.n = len(self.grid), len(self.grid[0])
        count = 0
        for i in range(self.m):
            for j in range(self.n):
                if self.grid[i][j] == '1':
                    count += 1
                    self.floodfill_bfs(i * self.n + j)
        return count

    def floodfill_bfs(self, pos: int) -> None:
        queue = []
        queue.append(pos)
        while queue:
            node = queue.pop(0)
            if node in self.visited: continue
            self.grid[node // self.n][node % self.n] = '0'  # Process
            self.visited.add(node)
            nodes = self.generate_related_nodes(node)
            queue += nodes

    def generate_related_nodes(self, node: int) -> List[int]:
        i, j = node // self.n, node % self.n
        res = []
        for k in range(4):
            x, y = self.dx[k] + i, self.dy[k] + j
            if 0 <= x < self.m and 0 <= y < self.n and self.grid[x][y] == '1':
                res.append(x * self.n + y)
        return res


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
