from typing import List as tList, Optional

from dsa.nodes import ListNode, BinaryTreeNode


class Array:
    def __init__(self, ary: tList[int]):
        self.ary = ary

    def to_singly_linkedList(self) -> Optional[ListNode]:
        return self.to_cyclic_singly_linkedList(-1)

    def to_cyclic_singly_linkedList(self, pos: int) -> Optional[ListNode]:
        """
        To represent a cycle in the given linked list, we use an integer pos which represents
        the position (0-indexed) in the linked list where tail connects to. If pos is -1, then
        there is no cycle in the linked list.
        """
        if not self.length or not self.ary[0]: return None

        dummy: ListNode = ListNode()
        head: ListNode = ListNode(self.ary[0])
        dummy.next = head
        cycle_entry_node: ListNode = head

        for i in range(1, self.length):
            node = ListNode(self.ary[i])
            head.next = node
            if i == pos: cycle_entry_node = node
            head = head.next

        if pos >= 0: head.next = cycle_entry_node

        return dummy.next

    def to_binary_tree(self) -> Optional[BinaryTreeNode]:
        if not self.length or not self.ary[0]: return None
        root: BinaryTreeNode = BinaryTreeNode(self.ary[0])
        Array._generate_tree_from_array(self.ary, self.length, root, 0)
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
        return len(self.ary)
