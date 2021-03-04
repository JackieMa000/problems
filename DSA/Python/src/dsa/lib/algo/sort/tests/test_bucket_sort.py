from typing import List
from unittest import TestCase

from dsa.lib.algo.sort.bucket_sort import BucketSort


class BucketSortTestCase(TestCase):
    def test_minMax(self):
        self.assertMinMax([1, 1], 1, 1)
        self.assertMinMax([2, 1], 1, 2)
        self.assertMinMax([1, 2, 3], 1, 3)
        self.assertMinMax([1, 1, 1], 1, 1)
        self.assertMinMax([4, 2, 8], 2, 8)

    def assertMinMax(self, nums: List[int], min_: int, max_: int) -> None:
        bs = BucketSort(nums)
        bs.sort()
        self.assertEqual(min_, bs.min)
        self.assertEqual(max_, bs.max)

    def test_bucketCount(self):
        self.assertBucketCount([1, 2, 3], 2, 2)
        self.assertBucketCount([1, 4, 5], 2, 3)
        self.assertBucketCount([2, 4, 9], 3, 3)

    def assertBucketCount(self, nums: List[int], capacity: int, count: int) -> None:
        bs = BucketSort(nums, capacity)
        bs.sort()
        self.assertEqual(count, bs.bucketCount)

    def test_emptyNums(self):
        nums: List[int] = []
        self.sort(nums)
        self.assertEqual([], nums)

    def test_oneNum(self):
        nums: List[int] = [1]
        self.sort(nums)
        self.assertEqual([1], nums)

    def test_case1(self):
        nums = [4, 5, 6, 3, 2, 1]
        expected = [1, 2, 3, 4, 5, 6]
        self.sort(nums)
        self.assertEqual(expected, nums)

    def test_case2(self):
        nums = [12, 11, 13, 5, 6, 7]
        expected = [5, 6, 7, 11, 12, 13]
        self.sort(nums)
        self.assertEqual(expected, nums)

    @staticmethod
    def sort(nums: List[int]) -> None:
        BucketSort(nums).sort()
