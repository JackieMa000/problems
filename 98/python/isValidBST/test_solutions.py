from unittest import TestCase

from isValidBST.solutions import Scratch1, Solution1
from lib.lists.arrays import Array


class Solution1TestCase(TestCase):
    def setUp(self):
        self.solution = Scratch1()

    def test_case1(self):
        self.assertTrue(self.solution.isValidBST(Array([3, 1, 5, None, 2]).to_binary_tree()))
        self.assertTrue(self.solution.isValidBST(Array([5, 1, 8, 0, 2, 6, 9]).to_binary_tree()))
        self.assertTrue(self.solution.isValidBST(Array([5, 1, 6, -3, 2, None, 7]).to_binary_tree()))

    def test_case2(self):
        self.assertFalse(self.solution.isValidBST(Array([5, 1, 4, 0, 6, 3, 6]).to_binary_tree()))
        self.assertFalse(self.solution.isValidBST(Array([5, 1, 6, -3, 2, 3, 7]).to_binary_tree()))
        self.assertFalse(self.solution.isValidBST(Array([1, 1]).to_binary_tree()))


class Solution2TestCase(TestCase):
    def setUp(self):
        self.solution = Solution1()

    def test_case1(self):
        self.assertTrue(self.solution.isValidBST(Array([3, 1, 5, None, 2]).to_binary_tree()))
        self.assertTrue(self.solution.isValidBST(Array([5, 1, 8, 0, 2, 6, 9]).to_binary_tree()))
        self.assertTrue(self.solution.isValidBST(Array([5, 1, 6, -3, 2, None, 7]).to_binary_tree()))

    def test_case2(self):
        self.assertFalse(self.solution.isValidBST(Array([5, 1, 4, 0, 6, 3, 6]).to_binary_tree()))
        self.assertFalse(self.solution.isValidBST(Array([0, None, -1]).to_binary_tree()))
        self.assertFalse(self.solution.isValidBST(Array([1, 1]).to_binary_tree()))
