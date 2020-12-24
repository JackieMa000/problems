from typing import List
from unittest import TestCase

from dsa.lib.algo.sort.bubble_sort import BubbleSort


class BubbleSortTest(TestCase):
    def test_one_num(self):
        ary: List[int] = [1]
        BubbleSort.sort(ary)
        self.assertEqual([1], ary)

    def test_case1(self):
        ary: List[int] = [4, 5, 6, 3, 2, 1]
        BubbleSort.sort(ary)
        self.assertEqual([1, 2, 3, 4, 5, 6], ary)
