from nodes import ListNode


class Solution1:
    def swapPairs(self, head: ListNode) -> ListNode:
        dummy_node = ListNode(); dummy_node.next = head

        prev: ListNode = dummy_node
        while prev.next and prev.next.next:
            p, q = prev.next, prev.next.next
            prev.next, p.next, q.next = q, q.next, p
            prev = prev.next.next

        return dummy_node.next


class Solution2:
    def swapPairs(self, head: ListNode) -> ListNode:
        dummy_node = ListNode()  # Dummy Node or Pseudo Node
        dummy_node.next = head
        return self.recursion(dummy_node)

    def recursion(self, prev: ListNode) -> ListNode:
        if prev.next and prev.next.next:
            p = prev.next; q = p.next
            prev.next, p.next, q.next = q, q.next, p
            self.recursion(prev.next.next)

        return prev.next


class Solution3:
    # Recursion
    def swapPairs(self, head: ListNode) -> ListNode:
        if not head or not head.next: return head
        new_start = head.next.next
        head, head.next = head.next, head # Swap
        head.next.next = self.swapPairs(new_start)
        return head


class Solution4:
    # Recursion
    def swapPairs(self, head: ListNode) -> ListNode:
        if not head or not head.next: return head
        new_start = head.next.next
        p = head; q = p.next
        head = q; p.next = self.swapPairs(new_start); q.next = p
        return head


class Solution5:
    def swapPairs(self, head: ListNode) -> ListNode:
        dummy_node = ListNode(); dummy_node.next = head

        prev: ListNode = dummy_node
        while prev.next and prev.next.next:
            p = prev.next; q = prev.next.next
            prev.next = q; p.next = q.next; q.next = p
            prev = prev.next.next

        return dummy_node.next
