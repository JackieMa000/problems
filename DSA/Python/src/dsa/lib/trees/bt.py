from typing import List, Optional

from dsa.container.lists.queues import Queue
from dsa.lib.trees.tree import Tree
from dsa.lib.utils import arrays
from dsa.nodes import BinaryTreeNode


class BinaryTree(Tree):

    def __init__(self, root: BinaryTreeNode):
        self._root = root

    def to_array(self) -> Optional[List[int]]:
        if not self._root: return None
        array: List[int] = [0] * (self._get_array_size_for_tree(self._root))
        self._generate_array_from_tree(self._root, 0, array)
        return arrays.rstrip(array)

    def depth(self) -> int:
        if not self._root: return 0
        return 1 + max(BinaryTree(self._root.left).depth(), BinaryTree(self._root.right).depth())

    @classmethod
    def _generate_array_from_tree(cls, root: BinaryTreeNode, i: int, array: List[int]) -> None:
        # Terminator
        if not root or i >= len(array): return

        # Process
        array[i] = root.val

        # Recursive
        cls._generate_array_from_tree(root.left, 2 * i + 1, array)
        cls._generate_array_from_tree(root.right, 2 * i + 2, array)

    @staticmethod
    def _get_array_size_for_tree(root: BinaryTreeNode) -> int:
        # Todo: could use my own pow
        return pow(2, BinaryTree(root).depth()) - 1

    def get_node_by_index(self, idx: int) -> BinaryTreeNode:
        return self.get_tree_node_by_idx_bfs(self._root, idx)

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
        return self.get_node_by_val_dfs(self._root, val)

    @classmethod
    def get_node_by_val_dfs(cls, root: BinaryTreeNode, val: int) -> Optional[BinaryTreeNode]:
        if not root: return None
        if root.val == val: return root

        left = cls.get_node_by_val_dfs(root.left, val)
        right = cls.get_node_by_val_dfs(root.right, val)
        return left if left else right

    @staticmethod
    def get_node_by_val_bfs(root: BinaryTreeNode, val: int) -> Optional[BinaryTreeNode]:
        queue: Queue = Queue()
        if root: queue.add(root)
        while not queue.empty():
            root = queue.pop()
            if root.val == val: return root

            if root.left: queue.add(root.left)
            if root.right: queue.add(root.right)

        return None

    @staticmethod
    def get_node_by_val_bfs1(root: BinaryTreeNode, val: int) -> Optional[BinaryTreeNode]:
        queue: Queue = Queue()
        if root: queue.add(root)
        while not queue.empty():
            root = queue.pop()
            if not root: continue
            if root.val == val: return root

            queue.add(root.left)
            queue.add(root.right)

        return None

    def size(self) -> int:
        return self._size_dfs(self._root)

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

    @classmethod
    def _size_dfs(cls, root: BinaryTreeNode) -> int:
        count: int = 0
        if root:
            count += 1
            count += cls._size_dfs(root.left)
            count += cls._size_dfs(root.right)
        return count

    # LeetCode236
    def lowest_common_ancestor(self, p: BinaryTreeNode, q: BinaryTreeNode) -> Optional[BinaryTreeNode]:
        return self._lowest_common_ancestor_dfs(self._root, p, q)

    @classmethod
    def _lowest_common_ancestor_dfs(cls, root: BinaryTreeNode, p: BinaryTreeNode, q: BinaryTreeNode) -> Optional[
        BinaryTreeNode]:
        """
         Binary Tree LCA Rule:
         1. root is null -> null
         2. root is p or q -> root
         3. p is on the left/right subtree, q is on the right/left subtree, respectively -> root
         4. p and q both are on the left/right subtree, means lca is on the left/right, return left/right respectively.
        """
        if not root or root == p or root == q: return root

        left = cls._lowest_common_ancestor_dfs(root.left, p, q)
        right = cls._lowest_common_ancestor_dfs(root.right, p, q)
        return root if (left and right) else left or right

    @classmethod
    def _preorder_dfs(cls, root: BinaryTreeNode, lst: List[int]) -> None:
        if root:
            lst.append(root.val)
            cls._preorder_dfs(root.left, lst)
            cls._preorder_dfs(root.right, lst)

    # LeetCode144
    def preorderTraversal(self) -> List[int]:
        lst: List[int] = []
        self._preorder_dfs(self._root, lst)
        return lst

    @classmethod
    def _inorder_dfs(cls, root: BinaryTreeNode, lst: List[int]) -> None:
        if root:
            cls._inorder_dfs(root.left, lst)
            lst.append(root.val)
            cls._inorder_dfs(root.right, lst)

    # LeetCode94
    def inorderTraversal(self) -> List[int]:
        lst: List[int] = []
        self._inorder_dfs(self._root, lst)
        return lst

    @classmethod
    def _postorder_dfs(cls, root: BinaryTreeNode, lst: List[int]) -> None:
        if root:
            cls._postorder_dfs(root.left, lst)
            cls._postorder_dfs(root.right, lst)
            lst.append(root.val)

    # LeetCode145
    def postorderTraversal(self) -> List[int]:
        lst: List[int] = []
        self._postorder_dfs(self._root, lst)
        return lst

    # LeetCode102
    def levelOrder(self) -> List[List[int]]:
        # return self._levelOrderBfs(self._root)
        result: List[List[int]] = []
        self._levelOrderDfs(self._root, 0, result)
        return result

    @staticmethod
    def _levelOrderBfs(root: BinaryTreeNode) -> List[List[int]]:
        """
         * Rule: BFS
         * queue -> currentLevelResult -> Result
         * currentLevelResult: saving the node values for the current level, 1D-array
         * Result: saving the final result for all the levels, 2D-array
         * queue: for BFS traversing the tree by level,
         *  consuming the nodes for the current level, producing the children nodes for next level
         *  Loop for the current level, do the logic(saving the node values to the currentLevelResult), produce for the next level
         * Loop on the whole tree:
         *  Loop on the level:
         *      ....
         *
        """
        result: List[List[int]] = []

        if root:
            queue = Queue()
            queue.push(root)
            while queue:
                level_size: int = len(queue)
                current_level: List[int] = []

                for _ in range(level_size):
                    root = queue.pop()
                    current_level.append(root.val)

                    if root.left: queue.push(root.left)
                    if root.right: queue.push(root.right)

                result.append(current_level)

        return result

    @classmethod
    def _levelOrderDfs(cls, root: BinaryTreeNode, level: int, result: List[List[int]]) -> None:
        """
         * Rule: DFS
         * currentLevelResult -> Result
         * saving the current level node values to the currentLevelResult.
         * get the currentLevelResult by the level number parameter from Result
         * generate the currentLevelResult when it does not exist in the result.

        """
        if root:
            if len(result) < level + 1: result.append([])
            result[level].append(root.val)
            cls._levelOrderDfs(root.left, level + 1, result)
            cls._levelOrderDfs(root.right, level + 1, result)
