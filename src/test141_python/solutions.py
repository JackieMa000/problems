from typing import Set

from nodes import ListNode


class Solution1:
    # HashSet
    def hasCycle(self, head: ListNode) -> bool:
        found: Set[ListNode] = set()
        while head:
            if head in found: return True
            found.add(head)
            head = head.next
        return False


class Solution2:
    # Fast and Slow pointers, or Tortoise and hare algorithm.
    def hasCycle(self, head: ListNode) -> bool:
        slow = head; fast = head
        while fast and fast.next:
            slow = slow.next; fast = fast.next.next
            if fast is slow: return True
        return False


class Solution3:
    # Pythonic
    def hasCycle(self, head: ListNode) -> bool:
        fast = slow = head
        while fast and fast.next:
            fast, slow = fast.next.next, slow.next
            if fast is slow: return True
        return False
