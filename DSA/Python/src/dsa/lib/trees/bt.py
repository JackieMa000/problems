from typing import List, Optional

from dsa.container.lists.queues import Queue
from dsa.lib.trees.tree import Tree
from dsa.lib.utils import array_rstrip
from dsa.nodes import BinaryTreeNode


class BinaryTree(Tree):

    def __init__(self, root: BinaryTreeNode):
        self._root = root

    def to_array(self) -> Optional[List[int]]:
        if not self._root: return None
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
        return BinaryTree.get_tree_node_by_idx_bfs(self._root, idx)

    @staticmethod
    def get_tree_node_by_idx_bfs(root: BinaryTreeNode, idx: int) -> Optional[BinaryTreeNode]:
        queue: Queue = Queue()
        if root: queue.push(root)

        count: int = 0
        while not queue.empty():
            root = queue.pop()
            count += 1
            if (count - 1) == idx: return root

            if not root: continue
            queue.push(root.left)
            queue.push(root.right)

        return None

    def get_node_by_value(self, val: int) -> BinaryTreeNode:
        return BinaryTree.get_node_by_val_bfs(self._root, val)

    @staticmethod
    def get_node_by_val_bfs(root: BinaryTreeNode, val: int) -> Optional[BinaryTreeNode]:
        queue: Queue = Queue()
        queue.add(root)
        while not queue.empty():
            node = queue.pop()
            if not node: continue

            if node.val == val: return node

            queue.add(node.left)
            queue.add(node.right)

        return None

    def size(self) -> int:
        return BinaryTree._size_dfs(self._root)

    @staticmethod
    def size_bfs(root: BinaryTreeNode) -> int:
        queue: Queue = Queue()
        queue.add(root)
        count: int = 0
        while not queue.empty():
            node = queue.pop()
            if not node: continue
            count += 1

            queue.add(node.left)
            queue.add(node.right)
        return count

    @staticmethod
    def _size_dfs(root: BinaryTreeNode) -> int:
        count: int = 0
        if root:
            count += 1
            count += BinaryTree._size_dfs(root.left)
            count += BinaryTree._size_dfs(root.right)
        return count

    def lowest_common_ancestor(self, p: BinaryTreeNode, q: BinaryTreeNode) -> Optional[BinaryTreeNode]:
        return BinaryTree._lowest_common_ancestor_dfs(self._root, p, q)

    @staticmethod
    def _lowest_common_ancestor_dfs(root: BinaryTreeNode, p: BinaryTreeNode, q: BinaryTreeNode) -> \
            Optional[BinaryTreeNode]:
        """
         Binary Tree LCA Rule:
         1. root is None
         2. p or q is root -> root
         3. p is on the left/right subtree, q is on the right/left subtree, respectively -> root
         4. p and q both are on the left/right subtree, then go to the left/right for more searching.
        """
        if not root or p == root or q == root: return root

        left = BinaryTree._lowest_common_ancestor_dfs(root.left, p, q)
        right = BinaryTree._lowest_common_ancestor_dfs(root.right, p, q)

        return root if left and right else left or right
