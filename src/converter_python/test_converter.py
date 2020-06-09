from typing import List
from unittest import TestCase

from .converter import TreeNode, Converter


class TestConverter(TestCase):
    def setUp(self):
        self.converter: Converter = Converter()

    def test_convert_array_to_tree(self):
        # Arrange
        input: List[int] = [3, 1, 5, None, 2]
        expected: List[int] = input

        # Act
        output: TreeNode = self.converter.convert_array_to_tree(input)

        # Assert
        self.assertTreeEqualsArray(output, 0, expected)

    def test_convert_array_to_tree_1(self):
        nums: List[int] = [5, 1, 4, 0, 6, 3, 6]
        self.assertTreeEqualsArray(self.converter.convert_array_to_tree(nums), 0, nums)

    def assertTreeEqualsArray(self, root: TreeNode, i: int, array: List[int]) -> None:
        n: int = len(array)
        # Terminator
        if i >= n: return

        # Process
        if root is None:
            self.assertEqual(root, array[i])
            return

        self.assertEqual(root.val, array[i])

        # Recursive
        lpos, rpos = 2 * i + 1, 2 * i + 2
        if lpos < n:
            self.assertTreeEqualsArray(root.left, lpos, array)
        if rpos < n:
            self.assertTreeEqualsArray(root.right, rpos, array)

    def test_convert_tree_to_array(self):
        # Arrange
        array: List[int] = [3, 1, 5, None, 2]
        input: TreeNode = self.converter.convert_array_to_tree(array)
        expected: List[int] = array

        # Act
        output = self.converter.convert_tree_to_array(input)

        # Assert
        self.assertEqual(expected, output)

    def test_convert_tree_to_array_1(self):
        root: TreeNode = self.converter.convert_array_to_tree([3, 1, 5, None, 2])
        self.assertEqual([3, 1, 5, None, 2], self.converter.convert_tree_to_array(root))

    def test_convert_tree_to_array_2(self):
        root: TreeNode = self.converter.convert_array_to_tree([5, 1, 4, 0, 6, 3, 6])
        self.assertEqual([5, 1, 4, 0, 6, 3, 6], self.converter.convert_tree_to_array(root))

    def test_convert_tree_to_array_3(self):
        root: TreeNode = self.converter.convert_array_to_tree([5, 1, 4, None, None, 3, 6])
        self.assertEqual([5, 1, 4, None, None, 3, 6], self.converter.convert_tree_to_array(root))

    def test_get_tree_depth_dfs(self):
        # Arrange
        array: List[int] = [3, 1, 5, None, 2]
        input: TreeNode = self.converter.convert_array_to_tree(array)
        expected: int = 3

        # Act
        output = self.converter._get_tree_depth_dfs(input)

        # Assert
        self.assertEqual(expected, output)

    def test_get_tree_depth_dfs_1(self):
        root: TreeNode = self.converter.convert_array_to_tree([3, 1, 5, None, 2])
        self.assertEqual(3, self.converter._get_tree_depth_dfs(root))

    def test_get_array_size_for_tree(self):
        # Arrange
        array: List[int] = [3, 1, 5, None, 2]
        input: TreeNode = self.converter.convert_array_to_tree(array)
        expected: int = 8

        # Act
        output = self.converter._get_array_size_for_tree(input)

        # Assert
        self.assertEqual(expected, output)

    def test_get_array_size_for_tree_1(self):
        root: TreeNode = self.converter.convert_array_to_tree([3, 1, 5, None, 2])
        self.assertEqual(8, self.converter._get_array_size_for_tree(root))

    def test_remove_last_none_from_array(self):
        # Arrange
        array: List[int] = [3, 1, 5, None, 2, None, None]
        expected: List[int] = [3, 1, 5, None, 2]

        # Act
        res: List[int] = self.converter.array_rstrip(array)

        # Assert
        self.assertEqual(expected, res)

    def test_remove_last_none_from_array_1(self):
        array: List[int] = [3, 1, 5, None, 2, None, None]
        self.assertEqual([3, 1, 5, None, 2], self.converter.array_rstrip(array))
