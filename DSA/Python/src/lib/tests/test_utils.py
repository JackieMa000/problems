import lib.utils
from testing import DSATestCase


class ArrayRstripTestCase(DSATestCase):
    def test_empty_array(self):
        self.assertEqual([], lib.utils.array_rstrip([]))

    def test_length1_element0(self):
        self.assertEqual([], lib.utils.array_rstrip([0]))

    def test_last_element_not0(self):
        self.assertEqual([1, 2], lib.utils.array_rstrip([1, 2]))

    def test_last_element0(self):
        actual = lib.utils.array_rstrip([1, 0])
        self.assertEqual([1], actual)
        self.assertEqual([1], lib.utils.array_rstrip([1, 0, 0]))
        self.assertEqual([1, 2], lib.utils.array_rstrip([1, 2, 0, 0]))
        self.assertEqual([3, 1, 5, 0, 2], lib.utils.array_rstrip([3, 1, 5, 0, 2, 0, 0]))
