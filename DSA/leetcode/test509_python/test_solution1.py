import unittest
from typing import List


class Solution:
    # 升维 矩阵相乘
    def fib(self, N: int) -> int:
        if N <= 1: return N

        M = [[1, 1], [1, 0]]
        res = self.matrixPow(M, N - 1)
        return res[0][0]

    def matrixPow(self, matrix: List[List[int]], n: int) -> List[List[int]]:
        if n == 1: return matrix
        if n & 1: return self.multiply(matrix, self.matrixPow(matrix, n - 1))
        return self.matrixPow(self.multiply(matrix, matrix), n >> 1)

    def multiply(self, M1: List[List[int]], M2: List[List[int]]) -> List[List[int]]:
        a = M1[0][0] * M2[0][0] + M1[0][1] * M2[1][0]
        b = M1[0][0] * M2[0][1] + M1[0][1] * M2[1][1]
        c = M1[1][0] * M2[0][0] + M1[1][1] * M2[1][0]
        d = M1[1][0] * M2[0][1] + M1[1][1] * M2[1][1]

        return [[a, b], [c, d]]


class MyTestCase(unittest.TestCase):
    def test_something(self):
        self.assertEqual(0, Solution().fib(0))
        self.assertEqual(1, Solution().fib(1))
        self.assertEqual(1, Solution().fib(2))
        self.assertEqual(2, Solution().fib(3))
        self.assertEqual(3, Solution().fib(4))


if __name__ == '__main__':
    unittest.main()
