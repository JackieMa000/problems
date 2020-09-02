from typing import Optional

from lib.trees import BinaryTree
from nodes import BinaryTreeNode


class Solution1:
    def lowestCommonAncestor(self, root: BinaryTreeNode, p: BinaryTreeNode, q: BinaryTreeNode) -> \
            Optional[BinaryTreeNode]:
        return BinaryTree(root).lowestCommonAncestor(p, q)
