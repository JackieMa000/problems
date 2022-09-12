from unittest import TestCase

from ..findMedianSortedArrays import Solution


class FindMedianSortedArraysTest(TestCase):
    def test_findMedianSortedArrays(self):
        self.assertEqual(2.0, self.findMedianSortedArrays([1, 3], [2]))
        self.assertEqual(2.5, self.findMedianSortedArrays([1, 2], [3, 4]))

    @staticmethod
    def findMedianSortedArrays(nums1, nums2):
        return Solution().findMedianSortedArrays(nums1, nums2)
