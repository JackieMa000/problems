from typing import Set

from dsa.lib.lists.linkedlists.base import Base
from dsa.nodes import ListNode


class LinkedList(Base):
    def __init__(self, head: ListNode):
        super().__init__(head)

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
        pre: ListNode = node
        cur: ListNode = self.head
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
        group_pre.next = LinkedList(fnode).reverse_before(tnode)

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
