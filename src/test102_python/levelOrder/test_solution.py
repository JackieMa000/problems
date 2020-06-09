from unittest import TestCase

from levelOrder.solution import TreeNode, Solution1, Solution3, Solution2

from converter import Converter


class TestSolution1(TestCase):
    def test_levelOrder(self):
        root: TreeNode = Converter().convert_array_to_tree([3, 9, 20, None, None, 15, 7])
        self.assertEqual([[3], [9, 20], [15, 7]], Solution1().levelOrder(root))


class TestSolution2(TestCase):
    def test_levelOrder(self):
        root: TreeNode = Converter().convert_array_to_tree([3, 9, 20, None, None, 15, 7])
        self.assertEqual([[3], [9, 20], [15, 7]], Solution2().levelOrder(root))


class TestSolution3(TestCase):
    def test_levelOrder(self):
        root: TreeNode = Converter().convert_array_to_tree([3, 9, 20, None, None, 15, 7])
        self.assertEqual([[3], [9, 20], [15, 7]], Solution3().levelOrder(root))
