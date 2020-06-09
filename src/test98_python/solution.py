class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


# Inorder traverse sort
class Solution1:
    def isValidBST(self, root: TreeNode) -> bool:
        inorder = self.inorder(root)
        return list(sorted(set(inorder))) == inorder

    def inorder(self, root: TreeNode) -> list:
        if not root: return []
        return self.inorder(root.left) + [root.val] + self.inorder(root.right)


# inorderBST.
# Don't save array
class Solution2:
    def isValidBST(self, root: TreeNode) -> bool:
        self.prev = None
        return self.helper(root)

    # Validate current node less than the prev node
    def helper(self, root: TreeNode):
        if root is None: return True
        if not self.helper(root.left):
            return False
        if self.prev and self.prev.val >= root.val:
            return False
        self.prev = root
        return self.helper(root.right)


# Recursion
class Solution3:
    def isValidBST(self, root: TreeNode) -> bool:
        return self.is_valid(root, float('-inf'), float('inf'))

    def is_valid(self, root: TreeNode, lower_limit: float, upper_limit: float) -> bool:
        if root is None: return True
        if root and root.val <= lower_limit: return False
        if root and root.val >= upper_limit: return False
        return self.is_valid(root.left, lower_limit, root.val) and self.is_valid(root.right, root.val, upper_limit)
