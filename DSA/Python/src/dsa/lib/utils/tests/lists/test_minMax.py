from unittest import TestCase

from dsa.lib.utils import lists


class MaxSizeTest(TestCase):
    def test_empty(self):
        self.assertIsNone(self.maxSize([]))

    def test_oneElement(self):
        a = [[1]]
        actual = self.maxSize(a)
        self.assertIs(a[0], actual)
        self.assertEqual(a[0], actual)

    def test_multiResults_returnFirst(self):
        a = [[1], [1]]
        actual = self.maxSize(a)
        self.assertIs(a[0], actual)
        self.assertEqual(a[0], actual)

    def test_case1(self):
        a = [[1], [1, 1]]
        actual = self.maxSize(a)
        self.assertIs(a[1], actual)
        self.assertEqual(a[1], actual)

    @staticmethod
    def maxSize(nums):
        return lists.maxSize(nums)


class MinSizeTest(TestCase):
    def test_empty(self):
        self.assertIsNone(self.minSize([]))

    def test_oneElement(self):
        a = [[1]]
        actual = self.minSize(a)
        self.assertIs(a[0], actual)
        self.assertEqual(a[0], actual)

    def test_multiResults_returnFirst(self):
        a = [[1], [1]]
        actual = self.minSize(a)
        self.assertIs(a[0], actual)
        self.assertEqual(a[0], actual)

    def test_case1(self):
        a = [[1], [1, 1]]
        actual = self.minSize(a)
        self.assertIs(a[0], actual)
        self.assertEqual(a[0], actual)

    @staticmethod
    def minSize(nums):
        return lists.minSize(nums)
