from abc import ABCMeta, abstractmethod
from typing import List

from lib.utils import array_rstrip
from nodes import BinaryTreeNode


class Tree(metaclass=ABCMeta):

    @abstractmethod
    def to_array(self) -> List[int]:
        pass

    @abstractmethod
    def depth(self) -> int:
        pass


class BinaryTree(Tree):

    def __init__(self, root: BinaryTreeNode):
        self._root = root

    def to_array(self) -> List[int]:
        array: List[int] = [0] * (BinaryTree._get_array_size_for_tree(self._root))
        BinaryTree._generate_array_from_tree(self._root, 0, array)
        return array_rstrip(array)

    def depth(self) -> int:
        if not self._root: return 0
        return 1 + max(BinaryTree(self._root.left).depth(), BinaryTree(self._root.right).depth())

    @staticmethod
    def _generate_array_from_tree(root: BinaryTreeNode, i: int, array: List[int]) -> None:
        # Terminator
        if not root or i >= len(array): return

        # Process
        array[i] = root.val

        # Recursive
        BinaryTree._generate_array_from_tree(root.left, 2 * i + 1, array)
        BinaryTree._generate_array_from_tree(root.right, 2 * i + 2, array)

    @staticmethod
    def _get_array_size_for_tree(root: BinaryTreeNode) -> int:
        # Todo: could use my own pow
        return pow(2, BinaryTree(root).depth()) - 1
