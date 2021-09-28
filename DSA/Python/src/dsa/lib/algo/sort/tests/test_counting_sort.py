from unittest import TestCase

from dsa.lib.algo.sort import counting_sort


class CountingSortTest(TestCase):
    def test_sortInt(self):
        nums = [1, 3, 2]
        counting_sort.sortInt(nums)
        self.assertEqual([1, 2, 3], nums)

    def test_sortIntPlace(self):
        nums = [13, 32, 21]
        counting_sort.sortIntPlace(nums, 1)
        self.assertEqual([21, 32, 13], nums)

    def test_sortStr(self):
        ss = ["ae", "ce", "be"]
        counting_sort.sortStr(ss, 0)
        self.assertEqual(["ae", "be", "ce"], ss)
