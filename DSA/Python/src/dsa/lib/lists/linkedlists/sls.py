from dsa.lib.lists.linkedlists.ls import LinkedList
from dsa.nodes import ListNode


class SinglyLinkedList(LinkedList):

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
