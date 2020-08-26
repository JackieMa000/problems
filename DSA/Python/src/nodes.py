class Node:
    def __init__(self, val: int = 0):
        self.val = val


class ListNode(Node):
    def __init__(self, val: int = 0, next=None):
        super().__init__(val)
        self.next = next


class TreeNode(Node):
    def __init__(self, val: int = 0):
        super().__init__(val)


class BinaryTreeNode(TreeNode):
    def __init__(self, val: int = 0, left=None, right=None):
        super().__init__(val)
        self.left = left
        self.right = right
