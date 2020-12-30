from typing import Optional

from dsa.lib.trees.bt import BinaryTree
from dsa.nodes import BinaryTreeNode


class BinarySearchTree(BinaryTree):

    def __init__(self, root: BinaryTreeNode):
        super().__init__(root)

    # LeetCode98
    def is_valid(self) -> bool:
        """
        BST definition:
            Empty Tree(null)
            Only a root node without children
            all the nodes on the left < root < all the nodes on the right.
        """
        return self._is_valid_bst(self._root, None, None)

    @classmethod
    def _is_valid_bst(cls, root: BinaryTreeNode, min_node: Optional[BinaryTreeNode],
                      max_node: Optional[BinaryTreeNode]) -> bool:
        """
        Rule:
        LowerBound and UpperBound
        biggest on the left < root < smallest on the right.
        """
        if not root: return True

        # 1. Check the biggest on the left, UpperBound.
        if max_node and root.val >= max_node.val: return False

        # 2. Check the smallest on the right, LowerBound.
        if min_node and root.val <= min_node.val: return False

        return cls._is_valid_bst(root.left, min_node, root) and cls._is_valid_bst(root.right, root, max_node)

    # LeetCode235
    def lowest_common_ancestor(self, p: BinaryTreeNode, q: BinaryTreeNode) -> BinaryTreeNode:
        """
        BST LCA Rule:
        1. if p < root < q or q < root < p -> root
        2. if p < root and q < root -> lca is on the left
        3. if root < p and root < q -> lca is on the right
        """
        return self._lowest_common_ancestor_dfs(self._root, p, q)

    @classmethod
    def _lowest_common_ancestor_dfs(cls, root: BinaryTreeNode, p: BinaryTreeNode, q: BinaryTreeNode) -> BinaryTreeNode:
        if p.val < root.val > q.val:
            return cls._lowest_common_ancestor_dfs(root.left, p, q)
        if p.val > root.val < q.val:
            return cls._lowest_common_ancestor_dfs(root.right, p, q)
        return root

    @staticmethod
    def _lowest_common_ancestor_bfs(root: BinaryTreeNode, p: BinaryTreeNode, q: BinaryTreeNode) -> BinaryTreeNode:
        while root:
            if p.val < root.val > q.val:
                root = root.left
            elif p.val > root.val < q.val:
                root = root.right
            else:
                break
        return root
