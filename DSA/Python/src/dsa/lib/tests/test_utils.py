import dsa.lib.utils
from dsa.lib.tests.test_lib import LibTestCase


class ArrayRstripTestCase(LibTestCase):
    def test_empty_array(self):
        self.assertEqual([], dsa.lib.utils.array_rstrip([]))

    def test_length1_element0(self):
        self.assertEqual([], dsa.lib.utils.array_rstrip([0]))

    def test_last_element_not0(self):
        self.assertEqual([1, 2], dsa.lib.utils.array_rstrip([1, 2]))

    def test_last_element0(self):
        actual = dsa.lib.utils.array_rstrip([1, 0])
        self.assertEqual([1], actual)
        self.assertEqual([1], dsa.lib.utils.array_rstrip([1, 0, 0]))
        self.assertEqual([1, 2], dsa.lib.utils.array_rstrip([1, 2, 0, 0]))
        self.assertEqual([3, 1, 5, 0, 2], dsa.lib.utils.array_rstrip([3, 1, 5, 0, 2, 0, 0]))
