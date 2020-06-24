from typing import List
from unittest import TestCase

from converter import TreeNode, Converter


class TestConverter(TestCase):
    def setUp(self):
        self.converter: Converter = Converter()

    def test_convert_array_to_tree(self):
        array: List[int] = [3, 1, 5, 0, 2]
        actual: TreeNode = self.converter.convert_array_to_tree(array)
        self.assertTreeEqualsArray(actual, 0, array)

    def test_convert_array_to_tree_1(self):
        nums: List[int] = [5, 1, 4, 0, 6, 3, 6]
        self.assertTreeEqualsArray(self.converter.convert_array_to_tree(nums), 0, nums)

    def assertTreeEqualsArray(self, root: TreeNode, i: int, array: List[int]) -> None:
        # Terminator
        if i >= len(array): return

        # Process
        if root is None:
            # self.assertEqual(root, array[i])
            self.assertEqual(0, array[i])
            return
        self.assertEqual(root.val, array[i])

        # Recursive
        self.assertTreeEqualsArray(root.left, 2 * i + 1, array)
        self.assertTreeEqualsArray(root.right, 2 * i + 2, array)

    def test_convert_tree_to_array(self):
        array: List[int] = [3, 1, 5, 0, 2]
        root: TreeNode = self.converter.convert_array_to_tree(array)
        self.assertEqual(array, self.converter.convert_tree_to_array(root))

    def test_convert_tree_to_array_2(self):
        root: TreeNode = self.converter.convert_array_to_tree([5, 1, 4, 0, 6, 3, 6])
        self.assertEqual([5, 1, 4, 0, 6, 3, 6], self.converter.convert_tree_to_array(root))

    def test_convert_tree_to_array_3(self):
        root: TreeNode = self.converter.convert_array_to_tree([5, 1, 4, 0, 0, 3, 6])
        self.assertEqual([5, 1, 4, 0, 0, 3, 6], self.converter.convert_tree_to_array(root))

    def test_get_tree_depth_dfs(self):
        array: List[int] = [3, 1, 5, 0, 2]
        input: TreeNode = self.converter.convert_array_to_tree(array)
        self.assertEqual(3, self.converter._get_tree_depth_dfs(input))

    def test_get_array_size_for_tree(self):
        root: TreeNode = self.converter.convert_array_to_tree([3, 1, 5, 0, 2])
        self.assertEqual(7, self.converter._get_array_size_for_tree(root))

    def test_remove_last_null_from_array(self):
        array: List[int] = [3, 1, 5, 0, 2, 0, 0]
        self.assertEqual(array, self.converter.array_rstrip(array))
