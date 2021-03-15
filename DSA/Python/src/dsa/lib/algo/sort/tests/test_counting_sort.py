from typing import List
from unittest import TestCase

from dsa.lib.algo.sort.counting_sort import CountingSort


class CountingSortTestCase(TestCase):
    def test_emptyArray(self):
        self.assertCountingSort([], [])

    def test_oneElement(self):
        self.assertCountingSort([1], [1])

    def test_sorts(self):
        self.assertCountingSort([1, 0], [0, 1])
        self.assertCountingSort([3, 2, 1], [1, 2, 3])
        self.assertCountingSort([4, 5, 6, 3, 2, 1], [1, 2, 3, 4, 5, 6])
        self.assertCountingSort([12, 11, 13, 5, 6, 7], [5, 6, 7, 11, 12, 13])
        self.assertCountingSort([2, 5, 3, 0, 2, 3, 0, 3], [0, 0, 2, 2, 3, 3, 3, 5])

        self.assertCountingSort([-1, -2], [-2, -1])
        self.assertCountingSort([-2, -4, -5], [-5, -4, -2])
        self.assertCountingSort([0, -1, -2], [-2, -1, 0])
        self.assertCountingSort([-2, -7, 3], [-7, -2, 3])

    def assertCountingSort(self, nums: List[int], expected: List[int]) -> None:
        self.counting_sort(nums)
        self.assertEqual(expected, nums)

    @staticmethod
    def counting_sort(nums: List[int]) -> None:
        CountingSort(nums).sort()

    def test_minMax(self):
        self.assertMinMax([1, 1], 1, 1)

    def assertMinMax(self, nums: List[int], min_: int, max_: int) -> None:
        cs = CountingSort(nums)
        cs.init_minMax()

        self.assertEqual(min_, cs.min)
        self.assertEqual(max_, cs.max)

    def test_countsIndexOf(self):
        self.assertCountsIndexOf([1, 2, 3], 2, 1)
        self.assertCountsIndexOf([1, 4, 1], 4, 3)
        self.assertCountsIndexOf([3, 4, 2], 2, 0)

    def assertCountsIndexOf(self, nums: List[int], num: int, index: int) -> None:
        cs = CountingSort(nums)
        cs.init_minMax()

        self.assertEqual(index, cs.countsIndexOf(num))

    def test_countsSize(self):
        self.assertCountsSize([0, 0], 1)
        self.assertCountsSize([1, 1], 1)
        self.assertCountsSize([0, 1, 1], 2)
        self.assertCountsSize([2, 4, 8], 7)

    def assertCountsSize(self, nums: List[int], expected: int) -> None:
        cs = CountingSort(nums)
        cs.init_minMax()
        cs.init_counts()

        self.assertEqual(expected, len(cs.counts))

    def test_storeCounts(self):
        self.assertStoreCounts([1, 2, 3], [1, 1, 1])
        self.assertStoreCounts([1, 4, 1], [2, 0, 0, 1])
        self.assertStoreCounts([3, 4, 2], [1, 1, 1])

    def assertStoreCounts(self, nums: List[int], expected: List[int]) -> None:
        cs = CountingSort(nums)
        cs.init_minMax()
        cs.init_counts()
        cs.store_counts()

        self.assertEqual(expected, cs.counts)

    def test_accuCounts(self):
        self.assertAccuCounts([1, 2, 3], [1, 2, 3])
        self.assertAccuCounts([1, 4, 1], [2, 2, 2, 3])
        self.assertAccuCounts([3, 4, 2], [1, 2, 3])

    def assertAccuCounts(self, nums: List[int], expected: List[int]) -> None:
        cs = CountingSort(nums)
        cs.init_minMax()
        cs.init_counts()
        cs.store_counts()
        cs.accumulate_counts()

        self.assertEqual(expected, cs.counts)
