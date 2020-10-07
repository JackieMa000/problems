from typing import List
from unittest.case import TestCase

from dsa.nodes import ListNode, BinaryTreeNode


class DSATestCase(TestCase):
    def assertArrayEqualsLinkedList(self, array: List[int], head: ListNode) -> None:
        i: int = 0; n: int = len(array)
        while i < n and head:
            self.assertEqual(array[i], head.val)
            i += 1; head = head.next
        self.assertEqual(n, i)
        self.assertIsNone(head)

    def assertArrayEqualsTree(self, array: List[int], root: BinaryTreeNode) -> None:
        self._assertArrayEqualsTreeDfs(array, root, 0)

    def _assertArrayEqualsTreeDfs(self, array: List[int], root: BinaryTreeNode, i: int):
        if i >= len(array): return

        if root is None:
            self.assertEqual(0, array[i])
            return

        self.assertEqual(root.val, array[i])
        self._assertArrayEqualsTreeDfs(array, root.left, 2 * i + 1)
        self._assertArrayEqualsTreeDfs(array, root.right, 2 * i + 2)