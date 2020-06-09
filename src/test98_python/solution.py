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


class Solution2:
    # inorder dfs traversal, prev < cur. if prev >= cur: return False
    # Don't save array
    def isValidBST(self, root: TreeNode) -> bool:
        self.prev = None
        return self.isValid_inorderDfs(root)

    def isValid_inorderDfs(self, root: TreeNode):
        if root is None: return True
        if not self.isValid_inorderDfs(root.left):
            return False
        if self.prev and self.prev.val >= root.val:
            return False
        self.prev = root
        return self.isValid_inorderDfs(root.right)


# Recursion
class Solution3:
    def isValidBST(self, root: TreeNode) -> bool:
        return self.is_valid(root, float('-inf'), float('inf'))

    def is_valid(self, root: TreeNode, lower_limit: float, upper_limit: float) -> bool:
        if root is None: return True
        if lower_limit != float('-inf') and root.val <= lower_limit: return False
        if upper_limit != float('inf') and root.val >= upper_limit: return False
        return self.is_valid(root.left, lower_limit, root.val) and self.is_valid(root.right, root.val, upper_limit)
