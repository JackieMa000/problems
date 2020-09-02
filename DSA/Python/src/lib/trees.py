from abc import ABCMeta, abstractmethod
from typing import List, Optional

from lib.queues import Queue
from lib.utils import array_rstrip
from nodes import BinaryTreeNode, TreeNode


class Tree(metaclass=ABCMeta):

    @abstractmethod
    def to_array(self) -> List[int]:
        pass

    @abstractmethod
    def depth(self) -> int:
        pass

    @abstractmethod
    def size(self) -> int:
        pass

    @abstractmethod
    def get_node_by_index(self, idx: int) -> TreeNode:
        pass

    @abstractmethod
    def get_node_by_value(self, val: int) -> TreeNode:
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

    def get_node_by_index(self, idx: int) -> BinaryTreeNode:
        return BinaryTree.get_node_by_idx_bfs(self._root, idx)

    @staticmethod
    def get_node_by_idx_bfs(root: BinaryTreeNode, idx: int) -> Optional[BinaryTreeNode]:
        queue: Queue = Queue()

        queue.append(root)
        count: int = 0
        while not queue.is_empty():
            node = queue.pop()
            count += 1
            if (count - 1) == idx:
                return node

            if not node: continue
            queue.append(node.left)
            queue.append(node.right)

        return None

    def get_node_by_value(self, val: int) -> BinaryTreeNode:
        return BinaryTree.get_node_by_val_bfs(self._root, val)

    @staticmethod
    def get_node_by_val_bfs(root: BinaryTreeNode, val: int) -> Optional[BinaryTreeNode]:
        queue: Queue = Queue()
        queue.add(root)
        while not queue.is_empty():
            node = queue.pop()
            if not node: continue

            if node.val == val: return node

            queue.add(node.left)
            queue.add(node.right)

        return None

    def size(self) -> int:
        return BinaryTree.size_dfs(self._root)

    @staticmethod
    def size_bfs(root: BinaryTreeNode) -> int:
        queue: Queue = Queue()
        queue.add(root)
        count: int = 0
        while not queue.is_empty():
            node = queue.pop()
            if not node: continue
            count += 1

            queue.add(node.left)
            queue.add(node.right)
        return count

    @staticmethod
    def size_dfs(root: BinaryTreeNode) -> int:
        count: int = 0
        if root:
            count += 1
            count += BinaryTree.size_dfs(root.left)
            count += BinaryTree.size_dfs(root.right)
        return count

    def lowestCommonAncestor(self, p: BinaryTreeNode, q: BinaryTreeNode) -> Optional[BinaryTreeNode]:
        return BinaryTree.lowestCommonAncestor_dfs(self._root, p, q)

    @staticmethod
    def lowestCommonAncestor_dfs(root: BinaryTreeNode, p: BinaryTreeNode, q: BinaryTreeNode) -> \
            Optional[BinaryTreeNode]:
        """
         LCA Rule:
         1. root is None
         2. p or q is root -> root
         3. p is on the left/right subtree, q is on the right/left subtree, respectively -> root
         4. p and q both are on the left/right subtree, then go to the left/right for more searching.
        """
        if not root or p == root or q == root: return root

        left = BinaryTree.lowestCommonAncestor_dfs(root.left, p, q)
        right = BinaryTree.lowestCommonAncestor_dfs(root.right, p, q)

        return root if left and right else left or right


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
