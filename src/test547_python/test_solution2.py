import unittest
from typing import List


class UnionFind:
    def __init__(self, n):
        self.count = n
        # Initialize the UnionFind by defining the parents are themselves
        self.parents = [i for i in range(n)]
        # The rank for everyone, every cycle.
        self.rank = [0] * n

    def find_root(self, node: int) -> int:
        if self.parents[node] != node:
            self.parents[node] = self.find_root(self.parents[node])

        return self.parents[node]

    def union(self, node_x: int, node_y: int):
        # find root
        rootx = self.find_root(node_x)
        rooty = self.find_root(node_y)

        # take the edge case
        if rootx == rooty: return

        # compare rank and union
        # recaculate the rank value and count value
        if self.rank[rootx] == self.rank[rooty]:
            self.parents[rootx] = rooty
            self.rank[rooty] += 1
        elif self.rank[rootx] < self.rank[rooty]:
            self.parents[rootx] = rooty
        else:
            self.parents[rooty] = rootx

        self.count -= 1


class Solution:
    def findCircleNum(self, M: List[List[int]]) -> int:
        if not M or not M[0]: return 0

        m, n = len(M), len(M[0])

        # Initialize the UnionFind for everybody. Because they at least know themselves.
        # A -> A. So A can be a friend cycle with himself. So we should initialize the
        # UnionFind for n persons.
        uf = UnionFind(n)

        # Traverse the matrix
        # 对角线遍历
        for i in range(m):
            # j starts from i+1. Becase we already union the parents for everyone which by
            # defining their parents are themselves.
            # Take the case of i = j which means the
            # same person(let's say he's A) when we initialize
            # the UnionFind in the UnionFind construction.
            for j in range(i + 1, n):
                if M[i][j] == 1:
                    uf.union(i, j)

        return uf.count


class MyTestCase(unittest.TestCase):
    def test_something(self):
        matrix = [[1, 1, 0, 0, 1],
                  [1, 1, 0, 0, 0],
                  [0, 0, 1, 1, 0],
                  [0, 0, 1, 1, 0],
                  [1, 0, 0, 0, 1]]
        self.assertEqual(2, Solution().findCircleNum(matrix))
        matrix = [[1, 1, 0],
                  [1, 1, 0],
                  [0, 0, 1]]
        self.assertEqual(2, Solution().findCircleNum(matrix))
        matrix = [[1, 1, 0],
                  [1, 1, 1],
                  [0, 1, 1]]
        self.assertEqual(1, Solution().findCircleNum(matrix))
