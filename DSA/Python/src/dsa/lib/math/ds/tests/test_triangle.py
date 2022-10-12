from unittest import TestCase

from dsa.lib.math.ds.triangle import Triangle


class MinimumTotalTest(TestCase):
    def test_case1(self):
        self.assertEqual(11, self.minimumTotal([
            [2],
            [3, 4],
            [6, 5, 7],
            [4, 1, 8, 3]]
        ))
        self.assertEqual(-10, self.minimumTotal([[-10]]))

    @staticmethod
    def minimumTotal(triangle):
        r = Triangle().minimumTotal(triangle)
        r1 = Triangle().minimumTotal1(triangle)
        r2 = Triangle().minimumTotal2(triangle)
        r3 = Triangle().minimumTotal3(triangle)
        assert r == r1 == r2 == r3, "Results from multiple same functions are different.";

        return r
