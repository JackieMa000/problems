from unittest import TestCase

from dsa.lib.math.ds.median import Median


class FindMedianSortedArraysTest(TestCase):
    def test_case1(self):
        self.assertEqual(2.0, self.findMedianSortedArrays([1, 3], [2]))
        self.assertEqual(2.5, self.findMedianSortedArrays([1, 2], [3, 4]))

    @staticmethod
    def findMedianSortedArrays(nums1, nums2):
        return Median().findMedianSortedArrays(nums1, nums2)
