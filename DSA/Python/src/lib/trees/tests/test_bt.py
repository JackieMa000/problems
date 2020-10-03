from typing import List
from unittest.case import skip

from lib.lists.arrays import Array
from lib.trees.bt import BinaryTree
from lib.trees.tests.test_tree import TreeTestFX
from nodes import BinaryTreeNode


class BinaryTreeTestFX(TreeTestFX):

    @staticmethod
    def array_to_tree(ary: List[int]) -> BinaryTreeNode:
        return Array(ary).to_binary_tree()

    @staticmethod
    def get_tree_node_by_value(root: BinaryTreeNode, val: int) -> BinaryTreeNode:
        return BinaryTree(root).get_node_by_value(val)


class DepthTestCase(BinaryTreeTestFX):
    def test_case1(self):
        self.assertEqual(3, BinaryTree(Array([3, 1, 5, 0, 2]).to_binary_tree()).depth())


class ToArrayTestCase(BinaryTreeTestFX):

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


class GetArraySizeForTreeTestCase(BinaryTreeTestFX):

    def test_case1(self):
        root: BinaryTreeNode = Array([3, 1, 5, 0, 2]).to_binary_tree()
        self.assertEqual(7, BinaryTree._get_array_size_for_tree(root))


class GetNodeByIndexTestCase(BinaryTreeTestFX):

    def test_case1(self):
        self.assertIsNone(self.get_tree_node_by_idx(BinaryTreeNode(), 2))
        self.assertIsNone(self.get_tree_node_by_idx(self.array_to_tree([1]), 1))
        # ToDo
        # self.assertIsNone(self.get_tree_node_by_idx(self.array_to_tree([1, 0, 3]), 1))

    def test_case2(self):
        self.assertEqual(1, self.get_tree_node_by_idx(self.array_to_tree([1]), 0).val)
        self.assertEqual(3, self.get_tree_node_by_idx(self.array_to_tree([1, 2, 3]), 2).val)

    def test_case3(self):
        self.assertEqual(2, self.get_tree_node_by_idx(self.array_to_tree([3, 1, 5, 0, 2]), 4).val)

    @staticmethod
    def get_tree_node_by_idx(root: BinaryTreeNode, i: int) -> BinaryTreeNode:
        return BinaryTree(root).get_node_by_index(i)


class GetNodeByValueTestCase(BinaryTreeTestFX):

    def test_case1(self):
        self.assertIsNone(self.get_tree_node_by_val(BinaryTreeNode(), 2))
        self.assertIsNone(self.get_tree_node_by_val(self.array_to_tree([1]), 2))

    def test_case2(self):
        self.assertEqual(1, self.get_tree_node_by_val(self.array_to_tree([1, 2, 3]), 1).val)
        self.assertEqual(2, self.get_tree_node_by_val(self.array_to_tree([1, 2, 3]), 2).val)

    def test_case3(self):
        self.assertEqual(2, self.get_tree_node_by_val(self.array_to_tree([3, 1, 5, 0, 2]), 2).val)

    @staticmethod
    def get_tree_node_by_val(root: BinaryTreeNode, val: int):
        return BinaryTree(root).get_node_by_value(val)


class SizeTestCase(BinaryTreeTestFX):

    def test_case1(self):
        self.assertEqual(0, self.get_tree_size(None))

    def test_case2(self):
        self.assertEqual(1, self.get_tree_size(self.array_to_tree([1])))
        self.assertEqual(3, self.get_tree_size(self.array_to_tree([1, 2, 3])))

    def test_case3(self):
        self.assertEqual(4, self.get_tree_size(self.array_to_tree([3, 1, 5, 0, 2])))

    @skip("FixMe: Could not handle this case")
    def test_case5(self):
        # FixMe: Couldn't handle this case
        root: BinaryTreeNode = BinaryTreeNode()
        actual: int = self.get_tree_size(root)
        self.assertEqual(0, actual)

    @staticmethod
    def get_tree_size(root):
        return BinaryTree(root).size()


class LowestCommonAncestorTestCase(BinaryTreeTestFX):

    def test_case1(self):
        root: BinaryTreeNode = self.array_to_tree([3, 5, 1, 6, 2, 0, 8, 0, 0, 7, 4])
        p: BinaryTreeNode = self.get_tree_node_by_value(root, 5)
        q: BinaryTreeNode = self.get_tree_node_by_value(root, 1)
        self.assertEqual(3, self.get_lowestCommonAncestor(root, p, q).val)

    def test_case2(self):
        root: BinaryTreeNode = self.array_to_tree([3, 5, 1, 6, 2, 0, 8, 0, 0, 7, 4])
        p: BinaryTreeNode = self.get_tree_node_by_value(root, 5)
        q: BinaryTreeNode = self.get_tree_node_by_value(root, 4)
        self.assertEqual(5, self.get_lowestCommonAncestor(root, p, q).val)

    @staticmethod
    def get_lowestCommonAncestor(root, p, q):
        return BinaryTree(root).lowest_common_ancestor(p, q)
