from typing import List

from dsa.lib.arrays.array import Array
from dsa.lib.lists.linkedlists.sls import SinglyLinkedList
from dsa.nodes import BinaryTreeNode, ListNode
from dsa.testing import DSATestCase


class LibTestCase(DSATestCase):
    @staticmethod
    def array_to_binary_tree(ary: List[int]) -> BinaryTreeNode:
        return Array(ary).to_binary_tree()

    @staticmethod
    def array_to_singly_linkedlist(ary: List[int]) -> ListNode:
        return Array(ary).to_singly_linkedList()

    @staticmethod
    def array_to_cyclic_linkedlist(ary: List[int], pos: int) -> ListNode:
        return Array(ary).to_cyclic_singly_linkedList(pos)

    @staticmethod
    def get_linkedlist_node_by_index(head: ListNode, idx: int) -> ListNode:
        return SinglyLinkedList(head).get_node_by_index(idx)
