from unittest import TestCase

from dsa.lib.utils import lists


class SwapTestCase(TestCase):
    @staticmethod
    def swap(ls, i: int, j: int):
        lists.swap(ls, i, j)

    def assertSwap(self, expected, ls, i: int, j: int):
        self.swap(ls, i, j)
        self.assertEqual(expected, ls)

    def test_swap(self):
        self.assertSwap([1], [1], 0, 0)
        self.assertSwap([2, 1], [1, 2], 0, 1)
        self.assertSwap([2, 1, 3], [1, 2, 3], 0, 1)