from typing import List
from unittest.case import TestCase

from nodes import ListNode


class DSATestCase(TestCase):
    def assertArrayEqualsLinkedList(self, array: List[int], head: ListNode) -> None:
        i: int = 0; n: int = len(array)
        while i < n and head:
            self.assertEqual(array[i], head.val)
            i += 1; head = head.next
        self.assertEqual(n, i)
        self.assertIsNone(head)