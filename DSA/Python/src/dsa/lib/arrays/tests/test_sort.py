from unittest import TestCase

from dsa.lib.arrays.sort import Sort


class SortColorsTest(TestCase):
    def test_case1(self):
        nums = [2, 0, 1]
        self.sortColors(nums)
        self.assertEqual([0, 1, 2], nums)

        nums1 = [2, 0, 2, 1, 1, 0]
        self.sortColors(nums1)
        self.assertEqual([0, 0, 1, 1, 2, 2], nums1)

    @staticmethod
    def sortColors(nums):
        return Sort().sortColors(nums)
