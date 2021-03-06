from dsa.lib.arrays.array import Array
from dsa.lib.trees.bst import BinarySearchTree
from dsa.lib.trees.tests.fixture import BinarySearchTreeTestCase
from dsa.nodes import BinaryTreeNode


class PreOrderTest(BinarySearchTreeTestCase):

    def test_case1(self):
        self.assertEqual([2, 1], self.preorder(self.array_to_binary_tree([2, 1])))

    def test_case2(self):
        self.assertEqual([2, 1, 3], self.preorder(self.array_to_binary_tree([2, 1, 3])))

    def test_case3(self):
        self.assertEqual([3, 1, 2, 5], self.preorder(self.array_to_binary_tree([3, 1, 5, 0, 2])))

    @staticmethod
    def preorder(root):
        return BinarySearchTree(root).preorderTraversal()


class InOrderTest(BinarySearchTreeTestCase):

    def test_case1(self):
        self.assertEqual([1, 2], self.inorder(self.array_to_binary_tree([2, 1])))

    def test_case2(self):
        self.assertEqual([1, 2, 3], self.inorder(self.array_to_binary_tree([2, 1, 3])))

    def test_case3(self):
        self.assertEqual([1, 2, 3, 5], self.inorder(Array([3, 1, 5, 0, 2]).to_binary_tree()))

    @staticmethod
    def inorder(root):
        return BinarySearchTree(root).inorderTraversal()


class PostOrderTest(BinarySearchTreeTestCase):

    def test_case1(self):
        self.assertEqual([1, 2], self.postorder(self.array_to_binary_tree([2, 1])))

    def test_case2(self):
        self.assertEqual([1, 3, 2], self.postorder(self.array_to_binary_tree([2, 1, 3])))

    def test_case3(self):
        self.assertEqual([2, 1, 5, 3], self.postorder(self.array_to_binary_tree([3, 1, 5, 0, 2])))

    @staticmethod
    def postorder(root):
        return BinarySearchTree(root).postorderTraversal()


class IsValidTest(BinarySearchTreeTestCase):

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

    def is_valid(self, ary):
        return BinarySearchTree(self.array_to_binary_tree(ary)).is_valid()


class LowestCommonAncestorTest(BinarySearchTreeTestCase):

    @staticmethod
    def lca(root: BinaryTreeNode, p: BinaryTreeNode, q: BinaryTreeNode) -> BinaryTreeNode:
        return BinarySearchTree(root).lowest_common_ancestor(p, q)

    def test_case1(self):
        root: BinaryTreeNode = self.array_to_binary_tree([6, 2, 8, 1, 4, 7, 9, 0, 0, 3, 5])
        p: BinaryTreeNode = self.get_tree_node_by_value(root, 2)
        q: BinaryTreeNode = self.get_tree_node_by_value(root, 8)
        self.assertEqual(6, self.lca(root, p, q).val)

    def test_case2(self):
        root: BinaryTreeNode = self.array_to_binary_tree([6, 2, 8, 1, 4, 7, 9, 0, 0, 3, 5])
        p: BinaryTreeNode = self.get_tree_node_by_value(root, 2)
        q: BinaryTreeNode = self.get_tree_node_by_value(root, 4)
        self.assertEqual(2, self.lca(root, p, q).val)

    def test_case3(self):
        root: BinaryTreeNode = self.array_to_binary_tree([1, 2])
        p: BinaryTreeNode = self.get_tree_node_by_value(root, 1)
        q: BinaryTreeNode = self.get_tree_node_by_value(root, 2)
        self.assertEqual(1, self.lca(root, p, q).val)
