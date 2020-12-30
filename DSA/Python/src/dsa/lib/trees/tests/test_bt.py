from typing import List

from dsa.lib.arrays.array import Array
from dsa.lib.trees.bt import BinaryTree
from dsa.lib.trees.tests.fixture import BinaryTreeTestCase
from dsa.nodes import BinaryTreeNode


class DepthTest(BinaryTreeTestCase):
    def test_case1(self):
        self.assertEqual(3, BinaryTree(Array([3, 1, 5, 0, 2]).to_binary_tree()).depth())


class ToArrayTest(BinaryTreeTestCase):

    def test_null_tree(self):
        self.assertIsNone(self.to_array(None))

    def test_case1(self):
        ary: List[int] = [3, 1, 5, 0, 2]
        self.assertEqual(ary, self.to_array(self.array_to_binary_tree(ary)))

    def test_case2(self):
        ary: List[int] = [5, 1, 4, 0, 6, 3, 6]
        self.assertEqual(ary, self.to_array(Array(ary).to_binary_tree()))

    def test_case3(self):
        ary = [5, 1, 4, 0, 0, 3, 6]
        self.assertEqual(ary, self.to_array(Array(ary).to_binary_tree()))

    @staticmethod
    def to_array(root):
        return BinaryTree(root).to_array()


class GetArraySizeForTreeTest(BinaryTreeTestCase):

    def test_case1(self):
        root: BinaryTreeNode = Array([3, 1, 5, 0, 2]).to_binary_tree()
        self.assertEqual(7, BinaryTree._get_array_size_for_tree(root))


class GetNodeByIndexTest(BinaryTreeTestCase):

    def test_case1(self):
        self.assertIsNone(self.get_tree_node_by_index(BinaryTreeNode(), 2))
        self.assertIsNone(self.get_tree_node_by_index(self.array_to_binary_tree([1]), 1))
        self.assertIsNone(self.get_tree_node_by_index(self.array_to_binary_tree([1, 0, 3]), 1))

    def test_case2(self):
        self.assertEqual(1, self.get_tree_node_by_index(self.array_to_binary_tree([1]), 0).val)
        self.assertEqual(3, self.get_tree_node_by_index(self.array_to_binary_tree([1, 2, 3]), 2).val)

    def test_case3(self):
        self.assertEqual(2, self.get_tree_node_by_index(self.array_to_binary_tree([3, 1, 5, 0, 2]), 4).val)


class GetNodeByValueTest(BinaryTreeTestCase):

    def test_case1(self):
        self.assertIsNone(self.get_tree_node_by_value(BinaryTreeNode(), 2))
        self.assertIsNone(self.get_tree_node_by_value(self.array_to_binary_tree([1]), 2))

    def test_case2(self):
        self.assertEqual(1, self.get_tree_node_by_value(self.array_to_binary_tree([1, 2, 3]), 1).val)
        self.assertEqual(2, self.get_tree_node_by_value(self.array_to_binary_tree([1, 2, 3]), 2).val)

    def test_case3(self):
        self.assertEqual(2, self.get_tree_node_by_value(self.array_to_binary_tree([3, 1, 5, 0, 2]), 2).val)


class SizeTest(BinaryTreeTestCase):

    def test_case1(self):
        self.assertEqual(0, self.get_tree_size(None))

    def test_case2(self):
        self.assertEqual(1, self.get_tree_size(self.array_to_binary_tree([1])))
        self.assertEqual(3, self.get_tree_size(self.array_to_binary_tree([1, 2, 3])))

    def test_case3(self):
        self.assertEqual(4, self.get_tree_size(self.array_to_binary_tree([3, 1, 5, 0, 2])))

    @staticmethod
    def get_tree_size(root):
        return BinaryTree(root).size()


class LowestCommonAncestorTest(BinaryTreeTestCase):

    def test_case1(self):
        root: BinaryTreeNode = self.array_to_binary_tree([3, 5, 1, 6, 2, 0, 8, 0, 0, 7, 4])
        p: BinaryTreeNode = self.get_tree_node_by_value(root, 5)
        q: BinaryTreeNode = self.get_tree_node_by_value(root, 1)
        self.assertEqual(3, self.lca(root, p, q).val)

    def test_case2(self):
        root: BinaryTreeNode = self.array_to_binary_tree([3, 5, 1, 6, 2, 0, 8, 0, 0, 7, 4])
        p: BinaryTreeNode = self.get_tree_node_by_value(root, 5)
        q: BinaryTreeNode = self.get_tree_node_by_value(root, 4)
        self.assertEqual(5, self.lca(root, p, q).val)

    def test_case3(self):
        root: BinaryTreeNode = self.array_to_binary_tree([1, 2])
        p: BinaryTreeNode = self.get_tree_node_by_value(root, 1)
        q: BinaryTreeNode = self.get_tree_node_by_value(root, 2)
        self.assertEqual(1, self.lca(root, p, q).val)

    @staticmethod
    def lca(root, p, q):
        return BinaryTree(root).lowest_common_ancestor(p, q)


class PreOrderTest(BinaryTreeTestCase):

    def test_empty_tree(self):
        self.assertEqual([], self.preorder(None))

    def test_one_node(self):
        self.assertEqual([1], self.preorder(self.array_to_binary_tree([1])))

    def test_case1(self):
        self.assertEqual([1, 2], self.preorder(self.array_to_binary_tree([1, 0, 2])))

    def test_case2(self):
        self.assertEqual([1, 2], self.preorder(self.array_to_binary_tree([1, 2])))

    def test_case3(self):
        self.assertEqual([1, 2, 3], self.preorder(self.array_to_binary_tree([1, 0, 2, 0, 0, 3])))

    @staticmethod
    def preorder(root):
        return BinaryTree(root).preorderTraversal()


class InOrderTest(BinaryTreeTestCase):

    def test_empty_tree(self):
        self.assertEqual([], self.inorder(None))

    def test_one_node(self):
        self.assertEqual([1], self.inorder(self.array_to_binary_tree([1])))

    def test_case1(self):
        self.assertEqual([1, 2], self.inorder(self.array_to_binary_tree([1, 0, 2])))

    def test_case2(self):
        self.assertEqual([2, 1], self.inorder(self.array_to_binary_tree([1, 2])))

    def test_case3(self):
        self.assertEqual([1, 3, 2], self.inorder(self.array_to_binary_tree([1, 0, 2, 0, 0, 3])))

    @staticmethod
    def inorder(root):
        return BinaryTree(root).inorderTraversal()


class PostOrderTest(BinaryTreeTestCase):

    def test_empty_tree(self):
        self.assertEqual([], self.postorder(None))

    def test_one_node(self):
        self.assertEqual([1], self.postorder(self.array_to_binary_tree([1])))

    def test_case1(self):
        self.assertEqual([2, 1], self.postorder(self.array_to_binary_tree([1, 0, 2])))

    def test_case2(self):
        self.assertEqual([2, 1], self.postorder(self.array_to_binary_tree([1, 2])))

    def test_case3(self):
        self.assertEqual([3, 2, 1], self.postorder(self.array_to_binary_tree([1, 0, 2, 0, 0, 3])))

    @staticmethod
    def postorder(root):
        return BinaryTree(root).postorderTraversal()
