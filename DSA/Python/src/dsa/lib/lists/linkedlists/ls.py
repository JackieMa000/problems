from typing import Set, Optional

from dsa.lib.lists.linkedlists.base import Base
from dsa.nodes import ListNode


class LinkedList(Base):
    def __init__(self, head: ListNode):
        super().__init__(head)

    # LeetCode206
    def reverse(self) -> ListNode:
        pre = None
        cur: ListNode = self.head
        next_: ListNode
        while cur:
            next_ = cur.next
            cur.next = pre
            pre, cur = cur, next_
        return pre

    def reverse_before(self, node: ListNode) -> ListNode:
        # Reverse the LinkedList nodes before a certain node, doesn't  reverse the certain node
        return self.reverse_before1(self.head, node)

    @staticmethod
    def reverse_before1(head: ListNode, node: ListNode) -> ListNode:
        pre: ListNode = node
        cur: ListNode = head
        next_: ListNode
        while cur is not node:
            next_ = cur.next
            cur.next = pre
            pre, cur = cur, next_
        return pre

    def reverse_from_to(self, fnode: ListNode, tnode: ListNode) -> ListNode:
        # Reverse a group of nodes from fnode to tnode, doesn't reverse the tnode node.
        cur: ListNode = self.head
        dummy: ListNode = ListNode()
        dummy.next = cur
        group_pre: ListNode = dummy

        # 1. Get the group previous node
        while cur is not fnode:
            group_pre = cur
            cur = cur.next

        # 2. Reverse the linkedlist from the fnode to the tnode
        # 3. Concatenate the reversed group nodes to the main linkedlist
        group_pre.next = self.reverse_before1(fnode, tnode)

        return dummy.next

    # LeetCode141
    def hasCycle(self) -> bool:
        return self.hasCycle1(self.head)

    # HashSet
    @staticmethod
    def hasCycle1(head: ListNode) -> bool:
        found: Set[ListNode] = set()
        while head:
            if head in found: return True
            found.add(head)
            head = head.next
        return False

    # Fast and Slow pointers, or Tortoise and hare algorithm.
    @staticmethod
    def hasCycle2(head: ListNode) -> bool:
        slow = head
        fast = head
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
            if fast is slow: return True
        return False

    # Pythonic
    @staticmethod
    def hasCycle3(head: ListNode) -> bool:
        fast = slow = head
        while fast and fast.next:
            fast, slow = fast.next.next, slow.next
            if fast is slow: return True
        return False

    # LeetCode142
    def detectCycle(self) -> ListNode:
        return self.detectCycle2(self.head)

    # Hash Set. Hash Table
    @staticmethod
    def detectCycle1(head: ListNode) -> Optional[ListNode]:
        found: Set[ListNode] = set()
        while head:
            if head in found: return head
            found.add(head)
            head = head.next
        return None

    # 2 pointers. Fast and Slow pointers, Tortoise and Hare algorithm
    # Pythonic
    @staticmethod
    def detectCycle2(head: ListNode) -> Optional[ListNode]:
        slow = fast = start = head
        while fast and fast.next:
            slow, fast = slow.next, fast.next.next
            if slow is fast:
                while slow is not start:
                    slow, start = slow.next, start.next
                return start
        return None

    @staticmethod
    def detectCycle21(head: ListNode) -> Optional[ListNode]:
        slow: ListNode = head
        fast: ListNode = head

        # Determine whether there is a cycle
        while True:
            if not fast or not fast.next: return None
            slow = slow.next
            fast = fast.next.next
            if slow is fast: break

        # get the entry location node of the cycle
        # Here fast == slow
        start: ListNode = head
        while start is not slow:
            slow = slow.next
            start = start.next
        return start

    @staticmethod
    def detectCycle22(head: ListNode) -> Optional[ListNode]:
        # 1. Determine whether there is a cycle
        slow: ListNode = head
        fast: ListNode = head
        start: ListNode = head
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
            if slow is fast:  # There is a cycle
                # 2. Get the cycle entry node
                while slow is not start:
                    slow = slow.next
                    start = start.next
                return start
        return None  # There is no cycle
