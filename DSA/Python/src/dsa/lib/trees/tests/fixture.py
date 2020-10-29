from dsa.lib.tests.fixture import LibTestCase
from dsa.lib.trees.bt import BinaryTree
from dsa.nodes import BinaryTreeNode


class TreeTestCase(LibTestCase):
    pass


class BinaryTreeTestCase(TreeTestCase):
    @staticmethod
    def get_tree_node_by_value(root: BinaryTreeNode, val: int) -> BinaryTreeNode:
        return BinaryTree(root).get_node_by_value(val)


class BinarySearchTreeTestCase(BinaryTreeTestCase):
    pass