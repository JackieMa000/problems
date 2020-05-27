import unittest


class Solution:
    def myPow(self, x: float, n: int) -> float:
        if n == 0: return 1
        if n < 0: return self.myPow(1 / x, -n)
        if n & 1: return x * self.myPow(x, n - 1)
        return self.myPow(x * x, n >> 1)  # even n

    # Divide & Conquer. 位运算，非递归，using while loop
    def myPow_1(self, x: float, n: int) -> float:
        if n < 0:
            x = 1 / x
            n = -n

        pow = 1
        while n:
            if n & 1:
                pow *= x
            x *= x
            n >>= 1

        return pow


class MyTestCase(unittest.TestCase):
    def test_something(self):
        self.assertEqual(1, Solution().myPow(2, 0))
        self.assertEqual(2, Solution().myPow(2, 1))
        self.assertEqual(4, Solution().myPow(2, 2))
        self.assertEqual(8, Solution().myPow(2, 3))
        self.assertEqual(1 / 4, Solution().myPow(2, -2))
        self.assertEqual(1024.00000, float("{0:.5f}".format(Solution().myPow(2.00000, 10))))
        self.assertEqual(9.26100, float("{0:.5f}".format(Solution().myPow(2.10000, 3))))
        self.assertEqual(0.25000, float("{0:.5f}".format(Solution().myPow(2.00000, -2))))
        self.assertEqual(1024, Solution().myPow(2, 10))
