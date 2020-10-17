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
    def get_linkedList_node_by_index(head: ListNode, idx: int) -> ListNode:
        return SinglyLinkedList(head).get_node_by_index(idx)
