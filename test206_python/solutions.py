from nodes import ListNode


class Solution1:
    def reverseList(self, head: ListNode) -> ListNode:
        prev = None
        while head:
            tmp, head.next = head.next, prev
            prev, head = head, tmp
        return prev


class Solution2:
    # Recursion
    def reverseList(self, head: ListNode) -> ListNode:
        return self._helper(head)

    def _helper(self, head: ListNode, prev: ListNode = None) -> ListNode:
        if not head: return prev
        next = head.next; head.next = prev
        return self._helper(next, head)
