from unittest import TestCase

from dsa.lib.utils.lists import binary_search


class BinarySearchTest(TestCase):
    def test_emptyList(self):
        self.assertEqual(-1, binary_search([], 1))

    def test_oneElement(self):
        self.assertEqual(0, binary_search([1], 1))
        self.assertEqual(-1, binary_search([1], 2))

    def test_evenList(self):
        self.assertEqual(0, binary_search([1, 2], 1))
        self.assertEqual(2, binary_search([1, 2, 3, 4], 3))
        self.assertEqual(-1, binary_search([1, 2, 3, 4], 25))

    def test_oddList(self):
        self.assertEqual(0, binary_search([1], 1))
        self.assertEqual(-1, binary_search([1], 5))
        self.assertEqual(2, binary_search([1, 2, 3], 3))
        self.assertEqual(4, binary_search([1, 2, 3, 4, 5], 5))
