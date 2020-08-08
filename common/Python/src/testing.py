from typing import List
from unittest.case import TestCase

from nodes import ListNode, BinaryTreeNode


class DSATestCase(TestCase):
    def assertArrayEqualsLinkedList(self, array: List[int], head: ListNode) -> None:
        i: int = 0; n: int = len(array)
        while i < n and head:
            self.assertEqual(array[i], head.val)
            i += 1; head = head.next
        self.assertEqual(n, i)
        self.assertIsNone(head)

    def assertTreeEqualsArray(self, root: BinaryTreeNode, i: int, array: List[int]) -> None:
        # ToDo: Refactor
        # Terminator
        if i >= len(array): return

        # Process
        if root is None:
            # self.assertEqual(root, array[i])
            self.assertEqual(0, array[i])
            return
        self.assertEqual(root.val, array[i])

        # Recursive
        self.assertTreeEqualsArray(root.left, 2 * i + 1, array)
        self.assertTreeEqualsArray(root.right, 2 * i + 2, array)