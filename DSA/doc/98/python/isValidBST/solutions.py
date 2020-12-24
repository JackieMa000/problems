from typing import Optional

from dsa.container.lists.queues import Stack
from dsa.nodes import BinaryTreeNode


# inorder traversal
# recursion
# inorder Rule: left(all nodes) < root < right(all nodes), or prev < cur.
# using field prev as global scope for all recursion subroutines
class Solution1:

    def isValidBST(self, root: BinaryTreeNode) -> bool:
        self.prev = None
        return self._is_valid(root)

    def _is_valid(self, root: BinaryTreeNode) -> bool:
        # Terminator
        if not root: return True

        # Left subTree
        if not self._is_valid(root.left): return False

        # Process or Logic
        if self.prev and self.prev.val >= root.val:
            return False

        # Right subTree, Recursive case
        self.prev = root
        return self._is_valid(root.right)


class Solution2:
    """
    prev < cur, using stack, simulating the recursive function call
    """

    def isValidBST(self, root: BinaryTreeNode) -> bool:
        """
        prev = null, initial value for the left subTree
        prev = root, value for the right subTree
        """
        stack = Stack()
        prev: Optional[BinaryTreeNode] = None

        while root or not stack.empty():
            while root:
                stack.push(root)
                root = root.left

            root = stack.pop()
            if prev and prev.val >= root.val: return False

            prev = root
            root = root.right

        return True
