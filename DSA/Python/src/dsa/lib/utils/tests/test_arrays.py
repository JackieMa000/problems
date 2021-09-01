from dsa.lib.utils import arrays
from dsa.lib.tests.fixture import LibTestCase


class ArrayRstripTest(LibTestCase):
    def test_empty_array(self):
        self.assertEqual([], arrays.rstrip([]))

    def test_length1_element0(self):
        self.assertEqual([], arrays.rstrip([0]))

    def test_last_element_not0(self):
        self.assertEqual([1, 2], arrays.rstrip([1, 2]))

    def test_last_element0(self):
        self.assertEqual([1], arrays.rstrip([1, 0]))
        self.assertEqual([1], arrays.rstrip([1, 0, 0]))
        self.assertEqual([1, 2], arrays.rstrip([1, 2, 0, 0]))
        self.assertEqual([3, 1, 5, 0, 2], arrays.rstrip([3, 1, 5, 0, 2, 0, 0]))
