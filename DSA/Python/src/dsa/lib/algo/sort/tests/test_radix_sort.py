from unittest import TestCase

from dsa.lib.algo.sort import radix_sort


class RadixSortTest(TestCase):
    def assertRadixSort(self, expected, nums):
        radix_sort.sort(nums)
        self.assertEqual(expected, nums)

    def test_empty(self):
        self.assertRadixSort([], [])

    def test_oneElement(self):
        self.assertRadixSort([1], [1])

    def test_sorts(self):
        self.assertRadixSort([1, 23, 45, 121, 432, 564, 788], [121, 432, 564, 23, 1, 45, 788])


class RadixSortStrTest(TestCase):
    def assertRadixSort(self, expected, ss):
        radix_sort.sortStr(ss)
        self.assertEqual(expected, ss)

    def test_empty(self):
        self.assertRadixSort([], [])

    def test_oneElement(self):
        self.assertRadixSort(["ab"], ["ab"])

    def test_sorts(self):
        self.assertRadixSort(["hac", "hke", "hzg", "iba", "ikf"], ["hke", "iba", "hzg", "ikf", "hac"])
