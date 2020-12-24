from unittest import TestCase

from solutions import Solution1, Solution2
from dsa.lib.tests.fixture import LibTestCase as TestFixture


class SolutionTest(TestCase):
    def test_empty_tree_is_BST(self):
        self.assertTrue(self.is_valid([]))

    def test_one_node_is_BST(self):
        self.assertTrue(self.is_valid([1]))

    def test_not_BST(self):
        self.assertFalse(self.is_valid([5, 1, 4, 0, 6, 3, 6]))
        self.assertFalse(self.is_valid([1, 1]))

    def test_is_BST(self):
        self.assertTrue(self.is_valid([0, 0, -1]))
        self.assertTrue(self.is_valid([3, 1, 5, 0, 2]))
        self.assertTrue(self.is_valid([5, 1, 8, 0, 2, 6, 9]))
        self.assertTrue(self.is_valid([5, 1, 6, -3, 2, 0, 7]))
        self.assertTrue(self.is_valid([5, 3, 9, 1, 4, 8, 15]))

    @staticmethod
    def is_valid(ary):
        return Solution1().isValidBST(TestFixture.array_to_binary_tree(ary))
