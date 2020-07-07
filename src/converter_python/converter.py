from typing import List

from nodes import TreeNode, ListNode


class Converter:
    def convert_array_to_tree(self, array: List[int]) -> TreeNode:
        root: TreeNode = TreeNode(array[0])
        self._generate_tree_from_array(array, root, 0)
        return root

    def _generate_tree_from_array(self, array: List[int], root: TreeNode, i: int) -> None:
        n = len(array)
        lpos, rpos = 2 * i + 1, 2 * i + 2
        if lpos < n and array[lpos]:
            root.left = TreeNode(array[lpos])
            self._generate_tree_from_array(array, root.left, lpos)
        if rpos < n and array[rpos]:
            root.right = TreeNode(array[rpos])
            self._generate_tree_from_array(array, root.right, rpos)

    def convert_tree_to_array(self, root: TreeNode) -> List[int]:
        array: List[int] = [0] * (self._get_array_size_for_tree(root))
        self._generate_array_from_tree(root, 0, array)
        return self.array_rstrip(array)

    def _generate_array_from_tree(self, root: TreeNode, i: int, array: List[int]) -> None:
        # Terminator
        if not root or i >= len(array): return

        # Process
        array[i] = root.val

        # Recursive
        self._generate_array_from_tree(root.left, 2 * i + 1, array)
        self._generate_array_from_tree(root.right, 2 * i + 2, array)

    def _get_array_size_for_tree(self, root: TreeNode) -> int:
        # Todo: could use my own pow
        return pow(2, self._get_tree_depth_dfs(root)) - 1

    def _get_tree_depth_dfs(self, root: TreeNode) -> int:
        if not root: return 0
        return 1 + max(self._get_tree_depth_dfs(root.left), self._get_tree_depth_dfs(root.right))

    def array_rstrip(self, array: List[int]) -> List[int]:
        while not array[(-1)]:
            array.pop(-1)
        return array

    def convert_array_to_linkedlist(self, array: List[int]) -> ListNode:
        '''
        ToDo: support creating cyclic LinkedList

        Use it something like this:
        head: ListNode = Converter().convert_array_to_linkedlist(array, pos)

        To represent a cycle in the given linked list, we use an integer pos which represents
        the position (0-indexed) in the linked list where tail connects to. If pos is -1, then
        there is no cycle in the linked list.

        For more, refers to test141_python.test_solutions.py
        https://leetcode.com/articles/linked-list-cycle/
        '''
        dummy_node: ListNode = ListNode(0)
        head: ListNode = ListNode(array[0])
        dummy_node.next = head

        for i in range(1, len(array)):
            head.next = ListNode(array[i])
            head = head.next

        return dummy_node.next

    def convert_linkedlist_to_array(self, head: ListNode) -> List[int]:
        res: List[int] = []

        while head:
            res.append(head.val)
            head = head.next

        return res
