from typing import List
from unittest import TestCase

from dsa.lib.algo.sort.bucket_sort import BucketSort


class BucketSortTestCase(TestCase):
    def test_case1(self):
        nums: List[int] = [1]
        self.sort(nums)
        self.assertEqual([1], nums)

    def test_case2(self):
        nums: List[int] = [4, 5, 6, 3, 2, 1]
        self.sort(nums)
        self.assertEqual([1, 2, 3, 4, 5, 6], nums)

    def sort(self, nums: List[int]) -> None:
        BucketSort(nums).sort()
