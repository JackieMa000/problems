from typing import List, Optional

from dsa.lib.trees.bt import BinaryTree
from dsa.nodes import BinaryTreeNode


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
    def _is_valid_bst(root: BinaryTreeNode, min_node: Optional[BinaryTreeNode],
                      max_node: Optional[BinaryTreeNode]) -> bool:
        if not root: return True
        # 1. Check the biggest on the left, UpperBound.
        if max_node and root.val >= max_node.val: return False
        # 2. Check the smallest on the right, LowerBound.
        if min_node and root.val <= min_node.val: return False
        return BinarySearchTree._is_valid_bst(root.left, min_node, root) and BinarySearchTree._is_valid_bst(root.right,
                                                                                                            root,
                                                                                                            max_node)

    def lowest_common_ancestor(self, p: BinaryTreeNode, q: BinaryTreeNode) -> BinaryTreeNode:
        """
        BST LCA Rule:
        1. if p < root < q or q < root < p -> root
        2. if p < root and q < root -> goes to left subtree
        3. if root < p and root < q -> goes to right subtree
        """
        return BinarySearchTree._lowest_common_ancestor_dfs(self._root, p, q)

    @staticmethod
    def _lowest_common_ancestor_dfs(root: BinaryTreeNode, p: BinaryTreeNode, q: BinaryTreeNode) -> BinaryTreeNode:
        if p.val < root.val > q.val:
            return BinarySearchTree._lowest_common_ancestor_dfs(root.left, p, q)
        if p.val > root.val < q.val:
            return BinarySearchTree._lowest_common_ancestor_dfs(root.right, p, q)
        return root

    @staticmethod
    def _lowest_common_ancestor_bfs(root: BinaryTreeNode, p: BinaryTreeNode, q: BinaryTreeNode) -> BinaryTreeNode:
        while root:
            if p.val < root.val > q.val:
                root = root.left
            elif p.val > root.val < q.val:
                root = root.right
            else:
                return root
