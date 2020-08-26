from typing import List
from unittest import skip

from lib.lists.arrays import Array
from lib.trees import BinaryTree, BinarySearchTree
from nodes import BinaryTreeNode
from testing import DSATestCase


class TreeTestCase(DSATestCase):
    pass


class BinaryTreeTestCase(TreeTestCase):

    @staticmethod
    def array_to_tree(ary: List[int]) -> BinaryTreeNode:
        return Array(ary).to_binary_tree()


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


class GetNodeByIndexTestCase(BinaryTreeTestCase):

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

    def get_tree_node_by_idx(self, root: BinaryTreeNode, i: int) -> BinaryTreeNode:
        return BinaryTree(root).get_node_by_index(i)


class GetNodeByValueTestCase(BinaryTreeTestCase):

    def test_case1(self):
        self.assertIsNone(self.get_tree_node_by_val(BinaryTreeNode(), 2))
        self.assertIsNone(self.get_tree_node_by_val(self.array_to_tree([1]), 2))

    def test_case2(self):
        self.assertEqual(1, self.get_tree_node_by_val(self.array_to_tree([1, 2, 3]), 1).val)
        self.assertEqual(2, self.get_tree_node_by_val(self.array_to_tree([1, 2, 3]), 2).val)

    def test_case3(self):
        self.assertEqual(2, self.get_tree_node_by_val(self.array_to_tree([3, 1, 5, 0, 2]), 2).val)

    def get_tree_node_by_val(self, root: BinaryTreeNode, val: int):
        return BinaryTree(root).get_node_by_value(val)


class SizeTestCase(BinaryTreeTestCase):

    def test_case1(self):
        self.assertEqual(0, self.get_tree_size(None))

    def test_case2(self):
        self.assertEqual(1, self.get_tree_size(self.array_to_tree([1])))
        self.assertEqual(3, self.get_tree_size(self.array_to_tree([1, 2, 3])))

    def test_case3(self):
        self.assertEqual(4, self.get_tree_size(self.array_to_tree([3, 1, 5, 0, 2])))

    @skip("FixMe: Couldn not handle this case")
    def test_case5(self):
        # FixMe: Couldn't handle this case
        root: BinaryTreeNode = BinaryTreeNode()
        actual : int = self.get_tree_size(root)
        self.assertEqual(0, actual)

    def get_tree_size(self, root):
        return BinaryTree(root).size()


class BinarySearchTreeTestCase(BinaryTreeTestCase):
    pass


class PreorderTestCase(BinarySearchTreeTestCase):

    def test_case1(self):
        root: BinaryTreeNode = Array([2, 1]).to_binary_tree()
        self.assertEqual([2, 1], BinarySearchTree(root).preorder())

    def test_case2(self):
        root: BinaryTreeNode = Array([2, 1, 3]).to_binary_tree()
        self.assertEqual([2, 1, 3], BinarySearchTree(root).preorder())

    def test_case3(self):
        root: BinaryTreeNode = Array([3, 1, 5, 0, 2]).to_binary_tree()
        self.assertEqual([3, 1, 2, 5], BinarySearchTree(root).preorder())


class InorderTestCase(BinarySearchTreeTestCase):

    def test_case1(self):
        root: BinaryTreeNode = Array([2, 1]).to_binary_tree()
        self.assertEqual([1, 2], BinarySearchTree(root).inorder())

    def test_case2(self):
        root: BinaryTreeNode = Array([2, 1, 3]).to_binary_tree()
        self.assertEqual([1, 2, 3], BinarySearchTree(root).inorder())

    def test_case3(self):
        root: BinaryTreeNode = Array([3, 1, 5, 0, 2]).to_binary_tree()
        self.assertEqual([1, 2, 3, 5], BinarySearchTree(root).inorder())


class PostorderTestCase(BinarySearchTreeTestCase):

    def test_case1(self):
        root: BinaryTreeNode = Array([2, 1]).to_binary_tree()
        self.assertEqual([1, 2], BinarySearchTree(root).postorder())

    def test_case2(self):
        root: BinaryTreeNode = Array([2, 1, 3]).to_binary_tree()
        self.assertEqual([1, 3, 2], BinarySearchTree(root).postorder())

    def test_case3(self):
        root: BinaryTreeNode = Array([3, 1, 5, 0, 2]).to_binary_tree()
        self.assertEqual([2, 1, 5, 3], BinarySearchTree(root).postorder())


class IsValidTestCase(BinarySearchTreeTestCase):

    def test_case1(self):
        self.assertTrue(BinarySearchTree(Array([3, 1, 5, None, 2]).to_binary_tree()).is_valid())
        self.assertTrue(BinarySearchTree(Array([5, 1, 8, 0, 2, 6, 9]).to_binary_tree()).is_valid())
        self.assertTrue(BinarySearchTree(Array([5, 1, 6, -3, 2, None, 7]).to_binary_tree()).is_valid())

    def test_case2(self):
        self.assertFalse(BinarySearchTree(Array([5, 1, 4, 0, 6, 3, 6]).to_binary_tree()).is_valid())
        self.assertFalse(BinarySearchTree(Array([0, None, -1]).to_binary_tree()).is_valid())
        self.assertFalse(BinarySearchTree(Array([1, 1]).to_binary_tree()).is_valid())


