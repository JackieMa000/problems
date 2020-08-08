from lib.lists.linkedlists import SinglyLinkedList
from nodes import ListNode


class Solution1:
    # Iterative
    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:
        # Initialize
        dummy: ListNode = ListNode();
        dummy.next = head
        # Type inferred
        pre, cur = dummy, head

        while True:
            for _ in range(k):
                if not cur: return dummy.next
                cur = cur.next

            pre.next = SinglyLinkedList(head).reverse_before(cur)
            pre, head = head, cur


class Solution2:
    # Recursion
    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:
        cur: ListNode = head
        for _ in range(k):
            if not cur: return head
            cur = cur.next

        new_head: ListNode = SinglyLinkedList(head).reverse_before(cur)

        head.next = self.reverseKGroup(cur, k)
        return new_head
