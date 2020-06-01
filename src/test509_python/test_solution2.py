import unittest


class Solution:
    # DP. Top Down
    def fib(self, N: int) -> int:
        if N <= 1: return N

    # DP 空间压缩
    def fib_2(self, N: int) -> int:
        if N <= 1: return N

        last_two, last_one = 0, 1
        res = 0

        for i in range(2, N + 1):
            res = last_one + last_two
            last_two, last_one = last_one, res

        return res

    # DP. Buttom Up
    def fib_1(self, N: int) -> int:
        if N <= 1: return N

        # Initialize
        dp = [-1] * (N + 1)
        dp[0] = 0
        dp[1] = 1
        for i in range(2, N + 1):
            dp[i] = dp[i - 1] + dp[i - 2]

        return dp[N]


class MyTestCase(unittest.TestCase):
    def test_something(self):
        self.assertEqual(0, Solution().fib(0))
        self.assertEqual(1, Solution().fib(1))
        self.assertEqual(1, Solution().fib(2))
        self.assertEqual(2, Solution().fib(3))
        self.assertEqual(3, Solution().fib(4))


if __name__ == '__main__':
    unittest.main()
