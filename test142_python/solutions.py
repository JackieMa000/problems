from typing import Set

from nodes import ListNode


class Solution1:
    # Hash Set. Hash Table
    def detectCycle(self, head: ListNode) -> ListNode:
        found: Set[ListNode] = set()
        while head:
            if head in found: return head
            found.add(head)
            head = head.next
        return None


class Solution2:
    # 2 pointers. Fast and Slow pointers, Tortoise and Hare algorithm
    def detectCycle(self, head: ListNode) -> ListNode:
        slow: ListNode = head; fast: ListNode = head

        # Determine whether there is a cycle
        while True:
            if not fast or not fast.next: return None
            slow = slow.next; fast = fast.next.next
            if slow is fast: break

        # get the entry location node of the cycle
        # Here fast == slow
        start: ListNode = head
        while start is not slow:
            slow = slow.next; start = start.next
        return start


class Solution3:
    def detectCycle(self, head: ListNode) -> ListNode:
        # 1. Determine whether there is a cycle
        slow: ListNode = head; fast: ListNode = head; start: ListNode = head
        while fast and fast.next:
            slow = slow.next; fast = fast.next.next
            if slow is fast: # There is a cycle
                # 2. Get the entry location node of the cycle
                while slow is not start:
                    slow = slow.next; start = start.next
                return start
        return None # There is no cycle


class Solution4:
    # Pythonic
    def detectCycle(self, head: ListNode) -> ListNode:
        slow = fast = start = head
        while fast and fast.next:
            slow, fast = slow.next, fast.next.next
            if slow is fast:
                while slow is not start:
                    slow, start = slow.next, start.next
                return start
        return None
