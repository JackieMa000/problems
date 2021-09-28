from unittest import TestCase

from dsa.lib.utils import lists


class LStripTest(TestCase):
    @staticmethod
    def lstripIt(nums):
        return lists._lstripIt(nums)

    @staticmethod
    def lstripDfs(nums):
        return lists._lstripDfs(nums)

    def assertLStrip(self, expected, nums):
        self.assertEqual(expected, self.lstripIt(nums))
        self.assertEqual(expected, self.lstripDfs(nums))

    def test_empty_returnEmpty(self):
        self.assertLStrip([], [])

    def test_all0s_returnEmpty(self):
        self.assertLStrip([], [0])
        self.assertLStrip([], [0, 0])

    def test_leftNot0s(self):
        self.assertLStrip([1], [1])
        self.assertLStrip([1, 2], [1, 2])

    def test_left0s(self):
        self.assertLStrip([1], [0, 1])
        self.assertLStrip([1], [0, 0, 1])
        self.assertLStrip([1, 2], [0, 0, 1, 2])
        self.assertLStrip([3, 1, 5, 0, 2], [0, 0, 3, 1, 5, 0, 2])


class RStripTest(TestCase):
    @staticmethod
    def rstripIt(nums):
        return lists._rstripIt(nums)

    @staticmethod
    def rstripDfs(nums):
        return lists._rstripDfs(nums)

    def assertRStrip(self, expected, nums):
        self.assertEqual(expected, self.rstripIt(nums))
        self.assertEqual(expected, self.rstripDfs(nums))

    def test_empty_returnEmpty(self):
        self.assertRStrip([], [])

    def test_all0s_returnEmpty(self):
        self.assertRStrip([], [0])
        self.assertRStrip([], [0, 0])

    def test_rightNot0s(self):
        self.assertRStrip([1], [1])
        self.assertRStrip([1, 2], [1, 2])

    def test_right0s(self):
        self.assertRStrip([1], [1, 0])
        self.assertRStrip([1], [1, 0, 0])
        self.assertRStrip([1, 2], [1, 2, 0, 0])
        self.assertRStrip([3, 1, 5, 0, 2], [3, 1, 5, 0, 2, 0, 0])


class StripTest(TestCase):
    @staticmethod
    def stripIt(nums):
        return lists._stripIt(nums)

    @staticmethod
    def stripDfs(nums):
        return lists._stripDfs(nums)

    def assertStrip(self, expected, nums):
        self.assertEqual(expected, self.stripIt(nums))
        self.assertEqual(expected, self.stripDfs(nums))

    def test_empty_returnEmpty(self):
        self.assertStrip([], [])

    def test_all0s_returnEmpty(self):
        self.assertStrip([], [0])
        self.assertStrip([], [0, 0])

    def test_leftRightNot0s(self):
        self.assertStrip([1], [1])
        self.assertStrip([1, 2], [1, 2])

    def test_leftRight0s(self):
        self.assertStrip([1], [0, 1, 0])
        self.assertStrip([1], [0, 0, 1, 0, 0])
        self.assertStrip([1, 2], [0, 0, 1, 2, 0, 0])
        self.assertStrip([3, 1, 5, 0, 2], [0, 0, 3, 1, 5, 0, 2, 0, 0])
