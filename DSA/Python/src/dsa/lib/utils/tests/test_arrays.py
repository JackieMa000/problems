from unittest import TestCase

from dsa.lib.utils import arrays


class ArrayRStripTest(TestCase):
    def test_empty_array(self):
        self.assertEqual([], arrays.rStrip([]))

    def test_length1_element0(self):
        self.assertEqual([], arrays.rStrip([0]))

    def test_last_element_not0(self):
        self.assertEqual([1, 2], arrays.rStrip([1, 2]))

    def test_last_element0(self):
        self.assertEqual([1], arrays.rStrip([1, 0]))
        self.assertEqual([1], arrays.rStrip([1, 0, 0]))
        self.assertEqual([1, 2], arrays.rStrip([1, 2, 0, 0]))
        self.assertEqual([3, 1, 5, 0, 2], arrays.rStrip([3, 1, 5, 0, 2, 0, 0]))


class MaxSizeElementTest(TestCase):
    def test_empty(self):
        self.assertIsNone(self.maxSizeElement([]))

    def test_oneElement(self):
        a = [[1]]
        actual = self.maxSizeElement(a)
        self.assertIs(a[0], actual)
        self.assertEqual(a[0], actual)

    def test_case1(self):
        a = [[1], [1, 1]]
        self.assertEqual(a[1], self.maxSizeElement(a))

    def test_multiResult(self):
        self.assertEqual([1], self.maxSizeElement([[1], [1]]))

    @staticmethod
    def maxSizeElement(nums):
        return arrays.maxSizeElement(nums)


class MinSizeElementTest(TestCase):
    def test_empty(self):
        self.assertIsNone(self.minSizeElement([]))

    def test_oneElement(self):
        self.assertEqual([1], self.minSizeElement([[1]]))

    def test_case1(self):
        self.assertEqual([1], self.minSizeElement([[1], [1, 1]]))

    def test_multiResults(self):
        self.assertEqual([1], self.minSizeElement([[1], [1]]))

    @staticmethod
    def minSizeElement(nums):
        return arrays.minSizeElement(nums)
