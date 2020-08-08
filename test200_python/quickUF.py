import unittest
from typing import List


class UfNode:
    def __init__(self, value: int):
        self.value: int = value


class UnionFind:
    def __init__(self, grid: List[List[str]]):
        m, n = len(grid), len(grid[0])
        self.count = 0
        self.rank = [0] * (m * n)
        self.parents = [-1] * (m * n)
        for i in range(m):
            for j in range(n):
                if grid[i][j] == '1':
                    node = i * n + j
                    self.parents[node] = node
                    self.count += 1

    def find_root(self, node: int) -> int:
        if self.parents[node] != node:
            parent = self.parents[node]
            self.parents[node] = self.find_root(parent)  # 路径压缩
        return self.parents[node]

    def find_root_2(self, node: int) -> int:
        if self.parents[node] == node: return node
        parent = self.parents[node]
        self.parents[node] = self.find_root(parent)
        return self.parents[node]

    def find_root_3(self, node: int) -> int:
        while self.parents[node] != node:
            parent = self.parents[node]
            self.parents[node] = self.parents[parent]
            node = parent
        return node

    def find_root_4(self, node: int) -> int:
        for _ in range(len(self.parents)):
            if self.parents[node] == node:
                break
            parent = self.parents[node]
            self.parents[node] = self.parents[parent]
            node = parent
        return self.parents[node]

    def connected(self, node_x: int, node_y: int) -> int:
        return self.find_root(node_x) == self.find_root(node_y)

    def union(self, node_x: int, node_y: int) -> None:
        rootx = self.find_root(node_x)
        rooty = self.find_root(node_y)

        if rootx == rooty: return

        if self.rank[rootx] == self.rank[rooty]:
            self.parents[rootx] = rooty
            self.rank[rooty] += 1
        elif self.rank[rootx] < self.rank[rooty]:
            self.parents[rootx] = rooty
        else:
            self.parents[rooty] = rootx

        self.count -= 1


class UnionFind1:
    def __init__(self, parents: List[int]):
        self.parents = parents

    def find_root_recursion(self, node: int) -> int:
        if self.parents[node] != node:
            parent = self.parents[node]
            self.parents[node] = self.find_root_recursion(parent)  # 路径压缩
        return self.parents[node]

    def find_root_recursion1(self, node: int) -> int:
        if self.parents[node] == node: return node
        parent = self.parents[node]
        self.parents[node] = self.find_root_recursion1(parent)
        return self.parents[node]

    def find_root_while_loop(self, node: int) -> int:
        while self.parents[node] != node:
            parent = self.parents[node]
            self.parents[node] = self.parents[parent]
            node = parent
        return node

    def find_root_for_loop(self, node: int) -> int:
        for _ in range(len(self.parents)):
            if self.parents[node] == node:
                break
            parent = self.parents[node]
            self.parents[node] = self.parents[parent]
            node = parent
        return node


class MyTestCase(unittest.TestCase):
    def test_find_root_for_loop(self):
        parents = [0, 1, 1, 2, 3, 4]
        uf = UnionFind1(parents)
        uf.find_root_for_loop(5)
        self.assertEqual([0, 1, 1, 1, 2, 3], uf.parents)

    def test_find_root_while_loop(self):
        parents = [0, 1, 1, 2, 3, 4]
        uf = UnionFind1(parents)
        uf.find_root_while_loop(5)
        self.assertEqual([0, 1, 1, 1, 2, 3], uf.parents)

    def test_find_root_recursion(self):
        parents = [0, 1, 1, 2, 3, 4]
        uf = UnionFind1(parents)
        uf.find_root_recursion(5)
        self.assertEqual([0, 1, 1, 1, 1, 1], uf.parents)

    def test_find_root_recursion1(self):
        parents = [0, 1, 1, 2, 3, 4]
        uf = UnionFind1(parents)
        uf.find_root_recursion1(5)
        self.assertEqual([0, 1, 1, 1, 1, 1], uf.parents)
