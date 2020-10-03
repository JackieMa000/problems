from lib.lists.arrays import Array
from lib.trees.bst import BinarySearchTree
from lib.trees.tests.test_bt import BinaryTreeTestFX
from nodes import BinaryTreeNode


class BinarySearchTreeTestFX(BinaryTreeTestFX):
    pass


class PreorderTestCase(BinarySearchTreeTestFX):

    def test_case1(self):
        root: BinaryTreeNode = Array([2, 1]).to_binary_tree()
        self.assertEqual([2, 1], BinarySearchTree(root).preorder())

    def test_case2(self):
        root: BinaryTreeNode = Array([2, 1, 3]).to_binary_tree()
        self.assertEqual([2, 1, 3], BinarySearchTree(root).preorder())

    def test_case3(self):
        root: BinaryTreeNode = Array([3, 1, 5, 0, 2]).to_binary_tree()
        self.assertEqual([3, 1, 2, 5], BinarySearchTree(root).preorder())


class InorderTestCase(BinarySearchTreeTestFX):

    def test_case1(self):
        root: BinaryTreeNode = Array([2, 1]).to_binary_tree()
        self.assertEqual([1, 2], BinarySearchTree(root).inorder())

    def test_case2(self):
        root: BinaryTreeNode = Array([2, 1, 3]).to_binary_tree()
        self.assertEqual([1, 2, 3], BinarySearchTree(root).inorder())

    def test_case3(self):
        root: BinaryTreeNode = Array([3, 1, 5, 0, 2]).to_binary_tree()
        self.assertEqual([1, 2, 3, 5], BinarySearchTree(root).inorder())


class PostorderTestCase(BinarySearchTreeTestFX):

    def test_case1(self):
        root: BinaryTreeNode = Array([2, 1]).to_binary_tree()
        self.assertEqual([1, 2], BinarySearchTree(root).postorder())

    def test_case2(self):
        root: BinaryTreeNode = Array([2, 1, 3]).to_binary_tree()
        self.assertEqual([1, 3, 2], BinarySearchTree(root).postorder())

    def test_case3(self):
        root: BinaryTreeNode = Array([3, 1, 5, 0, 2]).to_binary_tree()
        self.assertEqual([2, 1, 5, 3], BinarySearchTree(root).postorder())


class IsValidTestCase(BinarySearchTreeTestFX):

    def test_case1(self):
        self.assertTrue(BinarySearchTree(Array([3, 1, 5, None, 2]).to_binary_tree()).is_valid())
        self.assertTrue(BinarySearchTree(Array([5, 1, 8, 0, 2, 6, 9]).to_binary_tree()).is_valid())
        self.assertTrue(BinarySearchTree(Array([5, 1, 6, -3, 2, None, 7]).to_binary_tree()).is_valid())

    def test_case2(self):
        self.assertFalse(BinarySearchTree(Array([5, 1, 4, 0, 6, 3, 6]).to_binary_tree()).is_valid())
        self.assertFalse(BinarySearchTree(Array([0, None, -1]).to_binary_tree()).is_valid())
        self.assertFalse(BinarySearchTree(Array([1, 1]).to_binary_tree()).is_valid())


class LowestCommonAncestorBST(BinarySearchTreeTestFX):

    @staticmethod
    def get_lowestCommonAncestor(root: BinaryTreeNode, p: BinaryTreeNode, q: BinaryTreeNode) -> BinaryTreeNode:
        return BinarySearchTree(root).lowest_common_ancestor(p, q)

    def test_case1(self):
        root: BinaryTreeNode = self.array_to_tree([6, 2, 8, 1, 4, 7, 9, 0, 0, 3, 5])
        p: BinaryTreeNode = self.get_tree_node_by_value(root, 2)
        q: BinaryTreeNode = self.get_tree_node_by_value(root, 8)
        self.assertEqual(6, self.get_lowestCommonAncestor(root, p, q).val)

    def test_case2(self):
        root: BinaryTreeNode = self.array_to_tree([6, 2, 8, 1, 4, 7, 9, 0, 0, 3, 5])
        p: BinaryTreeNode = self.get_tree_node_by_value(root, 2)
        q: BinaryTreeNode = self.get_tree_node_by_value(root, 4)
        self.assertEqual(2, self.get_lowestCommonAncestor(root, p, q).val)
