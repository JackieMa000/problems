from typing import Optional

from nodes import BinaryTreeNode


# LowerBound and UpperBound
# BST Rule:
# biggest on the left < root < smallest on the right
# all the nodes on the left < root < all the nodes on the right
class Solution1:
    def isValidBST(self, root: BinaryTreeNode) -> bool:
        return self._is_valid(root, None, None)

    def _is_valid(self, root: BinaryTreeNode, minNode: Optional[BinaryTreeNode],
                  maxNode: Optional[BinaryTreeNode]) -> bool:
        # Terminator
        if not root: return True

        # Lower Bound
        if minNode and root.val <= minNode.val: return False

        # Upper Bound
        if maxNode and root.val >= maxNode.val: return False

        # Recursive case
        return self._is_valid(root.left, minNode, root) and self._is_valid(root.right, root, maxNode)


# inorder traversal
# inorder Rule: left(all nodes) < root < right(all nodes), or prev < cur.
class Scratch1:
    def isValidBST(self, root: BinaryTreeNode) -> bool:
        self.prev = None
        return self._is_valid(root)

    def _is_valid(self, root: BinaryTreeNode) -> bool:
        # Terminator
        if not root: return True

        # Left Tree
        if not self._is_valid(root.left):
            return False

        # Process or Logic
        if self.prev and self.prev.val >= root.val:
            return False

        # Right Tree, Recursive case
        self.prev = root
        return self._is_valid(root.right)
