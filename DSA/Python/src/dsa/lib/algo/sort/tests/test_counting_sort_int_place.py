from typing import List
from unittest import TestCase

from dsa.lib.algo.sort.counting_sort_int import CountingSortIntPlace


class CountingSortIntPlaceTestCase(TestCase):
    @staticmethod
    def countingSort(nums: List[int], place: int) -> None:
        CountingSortIntPlace(nums, place).sort()

    def assertCountingSortPlace(self, nums, place, expected):
        self.countingSort(nums, place)
        self.assertEqual(expected, nums)

    def test_emptyArray(self):
        self.assertCountingSortPlace([], 0, [])
        self.assertCountingSortPlace([], 10, [])

    def test_oneElement(self):
        self.assertCountingSortPlace([1], 0, [1])
        self.assertCountingSortPlace([1], 10, [1])

    def test_placeExceeds_noSort(self):
        self.assertCountingSortPlace([2, 1, 3], 10, [2, 1, 3])
        self.assertCountingSortPlace([2, 11, 31], 10, [2, 11, 31])
        self.assertCountingSortPlace([22, 11, 31], 100, [22, 11, 31])
