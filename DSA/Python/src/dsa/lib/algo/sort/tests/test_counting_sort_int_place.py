from typing import List
from unittest import TestCase

from dsa.lib.algo.sort.counting_sort_int import CountingSortIntPlace


class CountingSortIntPlaceTestCase(TestCase):
    def assertCountingSortPlace(self, nums, place, expected):
        self.countingSort(nums, place)
        self.assertEqual(expected, nums)

    @staticmethod
    def countingSort(nums: List[int], place: int) -> None:
        CountingSortIntPlace(nums, place).sort()

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

    def test_unitPlace(self):
        self.assertCountingSortPlace([2, 1, 3], 1, [1, 2, 3])
        self.assertCountingSortPlace([22, 11, 31], 1, [11, 31, 22])
        self.assertCountingSortPlace([121, 432, 564, 23, 1, 45, 788], 1, [121, 1, 432, 23, 564, 45, 788])

    def test_tensPlace(self):
        self.assertCountingSortPlace([22, 11, 31], 10, [11, 22, 31])
        self.assertCountingSortPlace([121, 1, 432, 23, 564, 45, 788], 10, [1, 121, 23, 432, 45, 564, 788])

    def test_hundredsPlace(self):
        self.assertCountingSortPlace([222, 111, 311], 100, [111, 222, 311])
        self.assertCountingSortPlace([1, 121, 23, 432, 45, 564, 788], 100, [1, 23, 45, 121, 432, 564, 788])
