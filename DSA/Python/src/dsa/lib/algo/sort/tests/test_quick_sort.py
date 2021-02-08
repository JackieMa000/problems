from typing import List
from unittest import TestCase

from dsa.lib.algo.sort.quick_sort import QuickSort


class QuickSortTestCase(TestCase):
    def test_case1(self):
        ary: List[int] = [1]
        expected: List[int] = [1]
        self.sort(ary)
        self.assertEqual(expected, ary)

    def test_case2(self):
        ary: List[int] = [4, 5, 6, 3, 2, 1]
        expected: List[int] = [1, 2, 3, 4, 5, 6]
        self.sort(ary)
        self.assertEqual(expected, ary)

    def test_case3(self):
        ary: List[int] = [12, 11, 13, 5, 6, 7]
        expected: List[int] = [5, 6, 7, 11, 12, 13]
        self.sort(ary)
        self.assertEqual(expected, ary)

    @staticmethod
    def sort(ary: List[int]) -> None:
        QuickSort().sort(ary)
