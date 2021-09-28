from typing import List
from unittest import TestCase

from dsa.lib.algo.sort.counting_sort.counting_sort_int import CountingSortInt


class CountingSortIntTestCase(TestCase):
    def assertCountingSort(self, expected: List[int], nums: List[int]) -> None:
        self.countingSort(nums)
        self.assertEqual(expected, nums)

    @staticmethod
    def countingSort(nums: List[int]) -> None:
        CountingSortInt(nums).sort()

    def assertMinMax(self, nums: List[int], min_: int, max_: int) -> None:
        cs = CountingSortInt(nums)
        cs.init_fields()

        self.assertEqual(min_, cs.min)
        self.assertEqual(max_, cs.max)

    def assertCountsSize(self, nums: List[int], expected: int) -> None:
        cs = CountingSortInt(nums)
        cs.init_fields()
        self.assertEqual(expected, cs.COUNTS_SIZE)

    def assertStoreCounts(self, nums: List[int], expected: List[int]) -> None:
        cs = CountingSortInt(nums)
        cs.init_fields()
        cs.store_counts()

        self.assertEqual(expected, cs.counts)

    def assertAccCounts(self, nums: List[int], expected: List[int]) -> None:
        cs = CountingSortInt(nums)
        cs.init_fields()
        cs.store_counts()
        cs.accumulate_counts()

        self.assertEqual(expected, cs.counts)

    def assertCountsIndexOf(self, nums: List[int], num: int, expected: int) -> None:
        cs = CountingSortInt(nums)
        cs.init_minMax()

        self.assertEqual(expected, cs.countsIndexOf(num))

    def test_emptyArray(self):
        self.assertCountingSort([], [])

    def test_oneElement(self):
        self.assertCountingSort([1], [1])

    def test_sorts(self):
        self.assertCountingSort([0, 1], [1, 0])
        self.assertCountingSort([1, 2, 3], [3, 2, 1])
        self.assertCountingSort([1, 2, 3, 4, 5, 6], [4, 5, 6, 3, 2, 1])
        self.assertCountingSort([5, 6, 7, 11, 12, 13], [12, 11, 13, 5, 6, 7])
        self.assertCountingSort([0, 0, 2, 2, 3, 3, 3, 5], [2, 5, 3, 0, 2, 3, 0, 3])

        self.assertCountingSort([-2, -1], [-1, -2])
        self.assertCountingSort([-5, -4, -2], [-2, -4, -5])
        self.assertCountingSort([-2, -1, 0], [0, -1, -2])
        self.assertCountingSort([-7, -2, 3], [-2, -7, 3])

    def test_minMax(self):
        self.assertMinMax([1], 1, 1)
        self.assertMinMax([1, 1], 1, 1)
        self.assertMinMax([1, 2, 3], 1, 3)
        self.assertMinMax([8, 2, 9], 2, 9)

    def test_countsSize(self):
        self.assertCountsSize([0, 0], 1)
        self.assertCountsSize([1, 1], 1)
        self.assertCountsSize([0, 1, 1], 2)
        self.assertCountsSize([2, 4, 8], 7)

        self.assertCountsSize([1, 2, 3], 3)
        self.assertCountsSize([1, 4, 1], 4)
        self.assertCountsSize([3, 4, 2], 3)

    def test_storeCounts(self):
        self.assertStoreCounts([1, 2, 3], [1, 1, 1])
        self.assertStoreCounts([1, 4, 1], [2, 0, 0, 1])
        self.assertStoreCounts([3, 4, 2], [1, 1, 1])

    def test_accCounts(self):
        self.assertAccCounts([1, 2, 3], [1, 2, 3])
        self.assertAccCounts([1, 4, 1], [2, 2, 2, 3])
        self.assertAccCounts([3, 4, 2], [1, 2, 3])

    def test_countsIndexOf(self):
        self.assertCountsIndexOf([1, 2, 3], 2, 1)
        self.assertCountsIndexOf([1, 2, 3], 2, 1)
        self.assertCountsIndexOf([8, 2, 9], 9, 7)
