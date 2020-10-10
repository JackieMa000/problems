from typing import List as tList, Optional

from dsa.lib.lists.linkedlists.sls import SinglyLinkedList
from dsa.nodes import ListNode, BinaryTreeNode


class Array:

    def __init__(self, ary: tList[int]):
        self._ary = ary

    def to_singly_linkedList(self) -> ListNode:
        dummy_node: ListNode = ListNode(0)
        head: ListNode = ListNode(self._ary[0])
        dummy_node.next = head

        for i in range(1, self.length):
            head.next = ListNode(self._ary[i])
            head = head.next

        return dummy_node.next

    def to_cyclic_singly_linkedList(self, pos: int) -> ListNode:
        """
        To represent a cycle in the given linked list, we use an integer pos which represents
        the position (0-indexed) in the linked list where tail connects to. If pos is -1, then
        there is no cycle in the linked list.
        """
        head: ListNode = self.to_singly_linkedList()

        if pos != -1:
            ls: SinglyLinkedList = SinglyLinkedList(head)
            tail: ListNode = ls.get_node_by_index(ls.size() - 1)
            tail.next = ls.get_node_by_index(pos)

        return head

    def to_binary_tree(self) -> Optional[BinaryTreeNode]:
        if not self.length or not self._ary[0]: return None
        root: BinaryTreeNode = BinaryTreeNode(self._ary[0])
        Array._generate_tree_from_array(self._ary, self.length, root, 0)
        return root

    @staticmethod
    def _generate_tree_from_array(array: tList[int], n: int, root: BinaryTreeNode, i: int) -> None:
        lpos, rpos = 2 * i + 1, 2 * i + 2
        if lpos < n and array[lpos]:
            root.left = BinaryTreeNode(array[lpos])
            Array._generate_tree_from_array(array, n, root.left, lpos)
        if rpos < n and array[rpos]:
            root.right = BinaryTreeNode(array[rpos])
            Array._generate_tree_from_array(array, n, root.right, rpos)

    @property
    def length(self) -> int:
        return len(self._ary)
