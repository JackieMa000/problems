from abc import ABCMeta, abstractmethod
from typing import List, Optional

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


class BinarySearchTree(BinaryTree):

    def __init__(self, root: BinaryTreeNode):
        super().__init__(root)

    def preorder(self) -> List[int]:
        return BinarySearchTree._preorder_dfs(self._root, [])

    @staticmethod
    def _preorder_dfs(root: BinaryTreeNode, lst: List[int]) -> List[int]:
        if root:
            lst.append(root.val)
            BinarySearchTree._preorder_dfs(root.left, lst)
            BinarySearchTree._preorder_dfs(root.right, lst)
        return lst

    def inorder(self) -> List[int]:
        return BinarySearchTree._inorder_dfs(self._root, [])

    @staticmethod
    def _inorder_dfs(root: BinaryTreeNode, lst: List[int]) -> List[int]:
        if root:
            BinarySearchTree._inorder_dfs(root.left, lst)
            lst.append(root.val)
            BinarySearchTree._inorder_dfs(root.right, lst)
        return lst

    def postorder(self) -> List[int]:
        return BinarySearchTree._postorder_dfs(self._root, [])

    @staticmethod
    def _postorder_dfs(root: BinaryTreeNode, lst: List[int]) -> List[int]:
        if root:
            BinarySearchTree._postorder_dfs(root.left, lst)
            BinarySearchTree._postorder_dfs(root.right, lst)
            lst.append(root.val)
        return lst

    def is_valid(self) -> bool:
        """
        LowerBound and UpperBound
        BST Rule:
            all the nodes on the left < root < all the nodes on the right.
            biggest on the left < root < smallest on the right.
        """
        return BinarySearchTree._is_valid_bst(self._root, None, None)

    @staticmethod
    def _is_valid_bst(root: BinaryTreeNode, minNode: Optional[BinaryTreeNode],
                      maxNode: Optional[BinaryTreeNode]) -> bool:
        if not root: return True
        # 1. Check the biggest on the left, UpperBound.
        if maxNode and root.val >= maxNode.val: return False
        # 2. Check the smallest on the right, LowerBound.
        if minNode and root.val <= minNode.val: return False
        return BinarySearchTree._is_valid_bst(root.left, minNode, root) and \
               BinarySearchTree._is_valid_bst(root.right, root, maxNode)

