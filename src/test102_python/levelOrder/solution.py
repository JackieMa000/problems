import collections
from typing import List, Deque


class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution1:
    # BFS for binary tree
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        if not root: return []

        queue: Deque[TreeNode] = collections.deque()
        queue.append(root)
        result: List[List[int]] = []

        while queue:
            level_size: int = len(queue)
            current_level: List[int] = []
            for _ in range(level_size):
                node: TreeNode = queue.popleft()
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
        result: List[List[int]] = []
        self._dfs(0, root, result)
        return result

    def _dfs(self, level: int, root: TreeNode, result: List[List[int]]) -> None:
        if not root: return
        if len(result) - 1 < level: result.append([])
        result[level].append(root.val)
        self._dfs(level + 1, root.left, result)
        self._dfs(level + 1, root.right, result)
