import unittest
from typing import List


class Solution:
    def fib(self, N: int) -> int:
        found = [0] * (N + 1)
        return self.helper(N, found)

    def helper(self, N: int, found: List[int]) -> int:
        if found[N]: return found[N]
        if N <= 1: found[N] = N; return N
        found[N] = self.helper(N - 1, found) + self.helper(N - 2, found)
        return found[N]

    # Recursive. Memorization
    def fib_2(self, N: int) -> int:
        if N <= 1: return N

        found = [0] * (N + 1)
        found[1] = 1
        return self.helper_2(N, found)

    def helper_2(self, N: int, found: List[int]) -> int:
        if N <= 1: return N
        if found[N]: return found[N]
        found[N] = self.helper_2(N - 1, found) + self.helper_2(N - 2, found)
        return found[N]

    # Recursive
    def fib_1(self, N: int) -> int:
        if N <= 1: return N
        return self.fib(N - 1) + self.fib(N - 2)


class MyTestCase(unittest.TestCase):
    def test_something(self):
        self.assertEqual(0, Solution().fib(0))
        self.assertEqual(1, Solution().fib(1))
        self.assertEqual(1, Solution().fib(2))
        self.assertEqual(2, Solution().fib(3))
        self.assertEqual(3, Solution().fib(4))


if __name__ == '__main__':
    unittest.main()
