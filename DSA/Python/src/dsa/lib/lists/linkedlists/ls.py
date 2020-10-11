from typing import List as tList, Optional

from dsa.lib.lists.lists import List
from dsa.nodes import ListNode


class LinkedList(List):
    def __init__(self, head: ListNode):
        self.head = head

    def size(self) -> int:
        cur: ListNode = self.head
        n: int = 0
        while cur:
            n += 1
            cur = cur.next
        return n

    def to_array(self) -> Optional[tList[int]]:
        if not self.head: return None
        cur = self.head
        res: tList[int] = []

        while cur:
            res.append(cur.val)
            cur = cur.next

        return res

    def get_node_by_index(self, idx: int) -> ListNode:
        cur: ListNode = self.head
        for _ in range(idx):
            if not cur: break
            cur = cur.next
        return cur

    def get_node_by_value(self, val: int) -> ListNode:
        cur: ListNode = self.head
        while cur and cur.val != val: cur = cur.next
        return cur
