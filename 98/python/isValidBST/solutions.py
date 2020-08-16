from lib.trees import BinarySearchTree
from nodes import BinaryTreeNode


class Solution1:
    def isValidBST(self, root: BinaryTreeNode) -> bool:
        return BinarySearchTree(root).is_valid()


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
