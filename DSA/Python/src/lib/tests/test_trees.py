from typing import List

from lib.lists.arrays import Array
from lib.trees import BinaryTree
from nodes import BinaryTreeNode
from testing import DSATestCase


class TreeTestCase(DSATestCase):
    pass


class BinaryTreeTestCase(TreeTestCase):
    pass


class DepthTestCase(BinaryTreeTestCase):
    def test_case1(self):
        self.assertEqual(3, BinaryTree(Array([3, 1, 5, 0, 2]).to_binary_tree()).depth())


class ToArrayTestCase(BinaryTreeTestCase):

    def test_case1(self):
        array: List[int] = [3, 1, 5, 0, 2]
        root: BinaryTreeNode = Array(array).to_binary_tree()
        self.assertEqual(array, BinaryTree(root).to_array())

    def test_case2(self):
        root: BinaryTreeNode = Array([5, 1, 4, 0, 6, 3, 6]).to_binary_tree()
        self.assertEqual([5, 1, 4, 0, 6, 3, 6], BinaryTree(root).to_array())

    def test_case3(self):
        root: BinaryTreeNode = Array([5, 1, 4, 0, 0, 3, 6]).to_binary_tree()
        self.assertEqual([5, 1, 4, 0, 0, 3, 6], BinaryTree(root).to_array())


class GetArraySizeForTreeTestCase(BinaryTreeTestCase):

    def test_case1(self):
        root: BinaryTreeNode = Array([3, 1, 5, 0, 2]).to_binary_tree()
        self.assertEqual(7, BinaryTree._get_array_size_for_tree(root))
