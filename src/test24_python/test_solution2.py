# Definition for singly-linked list.
import unittest
from typing import List


class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        prev, prev.next = self, head
        while prev.next and prev.next.next:
            p = prev.next
            q = p.next
            prev.next, p.next, q.next = q, q.next, p
            prev = p
        return self.next


class SolutionTestCase(unittest.TestCase):
    def test_swapPairs(self):
        before = self.convert_array_to_node([1, 2, 3, 4])
        after = Solution().swapPairs(before)
        array_after = self.convert_node_to_array(after)
        self.assertEqual([2, 1, 4, 3], array_after)

    def convert_array_to_node(self, array: List[int]) -> ListNode:
        if not array: return ListNode(None)

        dummy_node = ListNode(0)
        prev = dummy_node

        n = len(array)
        for i in range(n):
            cur = ListNode(array[i])
            prev.next = cur
            prev = cur

        return dummy_node.next

    def convert_node_to_array(self, head: ListNode) -> List[int]:
        res = []
        while head:
            res.append(head.val)
            head = head.next
        return res
