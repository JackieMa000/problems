from unittest import TestCase

from dsa.lib.utils import nums


class LastDigitOfTest(TestCase):
    def test_lastDigitOf(self):
        self.assertLastDigitOf(0, 0)
        self.assertLastDigitOf(1, 1)
        self.assertLastDigitOf(10, 0)
        self.assertLastDigitOf(123, 3)

    def assertLastDigitOf(self, num, expected):
        self.assertEqual(expected, nums.lastDigitOf(num))


class PlaceValueOfTest(TestCase):
    def test_unitPlace(self):
        self.assertPlaceValueOf(0, 1, 0)
        self.assertPlaceValueOf(1, 1, 1)
        self.assertPlaceValueOf(123, 1, 3)

    def test_tensPlace(self):
        self.assertPlaceValueOf(123, 10, 2)

    def test_hundredsPlace(self):
        self.assertPlaceValueOf(123, 100, 1)

    def assertPlaceValueOf(self, num, place, expected):
        self.assertEqual(expected, nums.placeValueOf(num, place))
