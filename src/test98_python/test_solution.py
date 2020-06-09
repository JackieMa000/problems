from unittest import TestCase

from converter_python.converter import Converter
from .solution import TreeNode, Solution1, Solution2, Solution3


class TestSolution1(TestCase):
    def setUp(self):
        self.solution = Solution1()
        self.converter = Converter()

    def test_ValidBST(self):
        root: TreeNode = self.converter.convert_array_to_tree([3, 1, 5, None, 2])
        self.assertTrue(self.solution.isValidBST(root))

        root: TreeNode = self.converter.convert_array_to_tree([5, 1, 8, 0, 2, 6, 9])
        self.assertTrue(self.solution.isValidBST(root))

        root: TreeNode = self.converter.convert_array_to_tree([5, 1, 6, -3, 2, None, 7])
        self.assertTrue(self.solution.isValidBST(root))

    def test_inValidBST(self):
        root: TreeNode = self.converter.convert_array_to_tree([5, 1, 4, 0, 6, 3, 6])
        self.assertFalse(self.solution.isValidBST(root))


class TestSolution2(TestCase):
    def setUp(self):
        self.solution = Solution2()
        self.converter = Converter()

    def test_ValidBST(self):
        root: TreeNode = self.converter.convert_array_to_tree([3, 1, 5, None, 2])
        self.assertTrue(self.solution.isValidBST(root))

        root: TreeNode = self.converter.convert_array_to_tree([5, 1, 8, 0, 2, 6, 9])
        self.assertTrue(self.solution.isValidBST(root))

        root: TreeNode = self.converter.convert_array_to_tree([5, 1, 6, -3, 2, None, 7])
        self.assertTrue(self.solution.isValidBST(root))

    def test_inValidBST(self):
        root: TreeNode = self.converter.convert_array_to_tree([5, 1, 4, 0, 6, 3, 6])
        self.assertFalse(self.solution.isValidBST(root))

        root: TreeNode = self.converter.convert_array_to_tree([5, 1, 6, -3, 2, 3, 7])
        self.assertFalse(self.solution.isValidBST(root))


class TestSolution3(TestCase):
    def setUp(self):
        self.converter = Converter()
        self.solution = Solution3()

    def test_ValidBST(self):
        # Arrange
        array = [3, 1, 5, None, 2]
        root: TreeNode = self.converter.convert_array_to_tree(array)

        input: TreeNode = root
        expected: bool = True

        # Act
        actual = self.solution.isValidBST(input)

        # Assert
        self.assertEqual(expected, actual)

    def test_ValidBST_1(self):
        root: TreeNode = self.converter.convert_array_to_tree([3, 1, 5, None, 2])
        self.assertTrue(self.solution.isValidBST(root))

        root: TreeNode = self.converter.convert_array_to_tree([5, 1, 8, 0, 2, 6, 9])
        self.assertTrue(self.solution.isValidBST(root))

        root: TreeNode = self.converter.convert_array_to_tree([5, 1, 6, -3, 2, None, 7])
        self.assertTrue(self.solution.isValidBST(root))

    def test_inValidBST(self):
        root: TreeNode = self.converter.convert_array_to_tree([5, 1, 4, 0, 6, 3, 6])
        self.assertFalse(self.solution.isValidBST(root))
