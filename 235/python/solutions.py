from nodes import BinaryTreeNode


class Solution1:
    # Recursion
    def lowestCommonAncestor_1(self, root: BinaryTreeNode, p: BinaryTreeNode, q: BinaryTreeNode) -> BinaryTreeNode:
        if p.val < root.val > q.val:
            return self.lowestCommonAncestor(root.left, p, q)
        if p.val > root.val < q.val:
            return self.lowestCommonAncestor(root.right, p, q)
        return root

    # while loop
    def lowestCommonAncestor(self, root: BinaryTreeNode, p: BinaryTreeNode, q: BinaryTreeNode) -> BinaryTreeNode:
        while root:
            if p.val < root.val > q.val:
                root = root.left
            elif p.val > root.val < q.val:
                root = root.right
            else:
                return root
