from lib.lists.linkedlists import SinglyLinkedList
from nodes import ListNode


class Solution1:
    def reverseList(self, head: ListNode) -> ListNode:
        return SinglyLinkedList(head).reverse()


class Solution2:
    # Recursion
    def reverseList(self, head: ListNode) -> ListNode:
        return self._helper(head)

    def _helper(self, head: ListNode, prev: ListNode = None) -> ListNode:
        if not head: return prev
        next = head.next;
        head.next = prev
        return self._helper(next, head)
