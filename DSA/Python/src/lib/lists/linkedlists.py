from typing import List as tList

from lib.lists.lists import List
from nodes import ListNode


class LinkedList(List):
    def __init__(self, head: ListNode):
        self.head = head

    def size(self) -> int:
        cur: ListNode = self.head
        len: int = 0
        while cur:
            len += 1
            cur = cur.next
        return len

    def to_array(self) -> tList[int]:
        cur = self.head
        res: tList[int] = []

        while cur:
            res.append(cur.val)
            cur = cur.next

        return res

    def get_node_by_index(self, idx: int) -> ListNode:
        cur: ListNode = self.head
        for _ in range(idx):
            cur = cur.next
        return cur


class SinglyLinkedList(LinkedList):

    def __init__(self, head: ListNode):
        super().__init__(head)

    def reverse(self) -> ListNode:
        pre = None
        cur: ListNode = self.head
        next: ListNode
        while cur:
            next = cur.next
            cur.next = pre
            pre, cur = cur, next
        return pre

    def reverse_before(self, node: ListNode) -> ListNode:
        # Reverse the LinkedList nodes before a certain node, doesn't  reverse the certain node
        pre: ListNode = node
        cur: ListNode = self.head
        next: ListNode
        while cur is not node:
            next = cur.next
            cur.next = pre
            pre, cur = cur, next
        return pre

    def reverse_from_to(self, fnode: ListNode, tnode: ListNode) -> ListNode:
        # Reverse a group of nodes from fnode to tnode, doesn't reverse the tnode node.
        dummy: ListNode = ListNode()
        dummy.next = self.head
        group_pre: ListNode = dummy
        pre, cur = tnode, self.head

        # 1. Get the group previous node
        while cur is not fnode:
            group_pre = cur
            cur = cur.next

        # 2. Reverse the linkedlist from the fnode to the tnode
        # 3. Concatenate the reversed group nodes to the main linkedlist
        group_pre.next = SinglyLinkedList(fnode).reverse_before(tnode)

        return dummy.next


class DoublyLinkedList(LinkedList):
    def __init__(self, head: ListNode):
        super().__init__(head)
