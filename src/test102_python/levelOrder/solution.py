import collections
from typing import List


class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution1:
    # BFS for binary tree
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        if not root: return []

        queue = collections.deque()
        queue.append(root)
        result = []

        while queue:
            level_size = len(queue)
            current_level = []
            for _ in range(level_size):
                node = queue.popleft()
                current_level.append(node.val)
                if node.left: queue.append(node.left)
                if node.right: queue.append(node.right)
            result.append(current_level)
        return result


class Solution2:
    # BFS for Graph with memorization
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        if not root: return []

        queue = collections.deque()
        queue.append(root)
        result = []
        visited = set()
        visited.add(root)

        while queue:
            level_size = len(queue)
            current_level = []
            for _ in range(level_size):
                node = queue.popleft()
                current_level.append(node.val)
                visited.add(node)
                if node.left and node.left not in visited: queue.append(node.left)
                if node.right and node.right not in visited: queue.append(node.right)
            result.append(current_level)
        return result


class Solution3:
    # DFS
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        if not root: return []
        self.result = []
        self._dfs(0, root)
        return self.result

    def _dfs(self, level, root: TreeNode):
        # Terminator case
        if not root: return

        # Process Logic
        if len(self.result) < level + 1:
            self.result.append([])
        self.result[level].append(root.val)

        # Recursive case
        self._dfs(level + 1, root.left)
        self._dfs(level + 1, root.right)
