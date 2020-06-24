from typing import List


class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Converter:
    def convert_array_to_tree(self, array: List[int]) -> TreeNode:
        root: TreeNode = TreeNode(array[0])
        self._generate_tree_from_array(array, root, 0)
        return root

    def _generate_tree_from_array(self, array: List[int], root: TreeNode, i: int) -> None:
        n = len(array)
        lpos, rpos = 2 * i + 1, 2 * i + 2
        if lpos < n and array[lpos] is not None:
            root.left = TreeNode(array[lpos])
            self._generate_tree_from_array(array, root.left, lpos)
        if rpos < n and array[rpos] is not None:
            root.right = TreeNode(array[rpos])
            self._generate_tree_from_array(array, root.right, rpos)

    # ToDo: make a short impl version
    def convert_tree_to_array(self, root: TreeNode) -> List[int]:
        # ToDo: Better to change default None to 0
        array: List[int] = [None] * (self._get_array_size_for_tree(root))
        self._generate_array_from_tree(root, 0, array)
        return self.array_rstrip(array)

    def _generate_array_from_tree(self, root: TreeNode, i: int, array: List[int]) -> None:
        n: int = len(array)

        # Terminator
        if not root or i >= n: return

        # Process
        array[i] = root.val

        # Recursive
        self._generate_array_from_tree(root.left, 2 * i + 1, array)
        self._generate_array_from_tree(root.right, 2 * i + 2, array)

    def _get_array_size_for_tree(self, root: TreeNode) -> int:
        # Todo: could use my pow
        return pow(2, self._get_tree_depth_dfs(root))

    def _get_tree_depth_dfs(self, root: TreeNode) -> int:
        if not root: return 0
        return 1 + max(self._get_tree_depth_dfs(root.left), self._get_tree_depth_dfs(root.right))

    def array_rstrip(self, array: List[int]) -> List[int]:
        while not array[(-1)]:
            array.pop(-1)
        return array
