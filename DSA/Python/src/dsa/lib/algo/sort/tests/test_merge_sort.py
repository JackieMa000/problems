from typing import List
from unittest import TestCase

from dsa.lib.algo.sort.merge_sort import MergeSort


class MergeSortTest(TestCase):
    def test_case1(self):
        ary: List[int] = [1]
        self.sort(ary, len(ary))
        self.assertEqual([1], ary)

    def test_case2(self):
        ary: List[int] = [4, 5, 6, 3, 2, 1]
        self.sort(ary, len(ary))
        self.assertEqual([1, 2, 3, 4, 5, 6], ary)

    def test_case3(self):
        ary: List[int] = [12, 11, 13, 5, 6, 7]
        self.sort(ary, len(ary))
        self.assertEqual([5, 6, 7, 11, 12, 13], ary)

    @staticmethod
    def sort(ary: List[int], n: int) -> None:
        MergeSort().sort(ary, n)
