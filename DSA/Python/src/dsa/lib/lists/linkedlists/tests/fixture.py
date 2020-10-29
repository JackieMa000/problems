from typing import List

from dsa.lib.arrays.array import Array
from dsa.lib.lists.tests.fixture import ListTestCase
from dsa.nodes import ListNode


class LinkedListTestCase(ListTestCase):
    @staticmethod
    def array_to_singly_linkedlist(ary: List[int]) -> ListNode:
        return Array(ary).to_singly_linkedList()

    @staticmethod
    def array_to_cyclic_linkedlist(ary: List[int], pos: int) -> ListNode:
        return Array(ary).to_cyclic_singly_linkedList(pos)
