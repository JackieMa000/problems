from nodes import ListNode


# ToDo: Add Unit Tests

def reverse_before(head: ListNode, node: ListNode) -> ListNode:
    pre: ListNode = node;cur: ListNode = head;next: ListNode
    while cur is not node:
        next = cur.next
        cur.next = pre
        pre, cur = cur, next
    return pre


def reverse_from_to(head: ListNode, from_node: ListNode, to_node: ListNode) -> ListNode:
    # ToDo
    new_head: ListNode
    return new_head
