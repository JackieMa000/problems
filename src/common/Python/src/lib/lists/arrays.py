from typing import List as tList

from lib.lists.lists import List
from nodes import ListNode, BinaryTreeNode


class Array:

    def __init__(self, array: tList[int]):
        self._array = array

    def to_singlylinkedlist(self) -> ListNode:
        '''
        ToDo: support creating cyclic LinkedList

        Use it something like this:
        head: ListNode = Converter().convert_array_to_linkedlist(array, pos)

        To represent a cycle in the given linked list, we use an integer pos which represents
        the position (0-indexed) in the linked list where tail connects to. If pos is -1, then
        there is no cycle in the linked list.

        For more, refers to test141_python.test_solutions.py
        https://leetcode.com/articles/linked-list-cycle/
        '''
        dummy_node: ListNode = ListNode(0)
        head: ListNode = ListNode(self._array[0])
        dummy_node.next = head

        for i in range(1, self.length):
            head.next = ListNode(self._array[i])
            head = head.next

        return dummy_node.next

    def to_binary_tree(self) -> BinaryTreeNode:
        root: BinaryTreeNode = BinaryTreeNode(self._array[0])
        Array._generate_tree_from_array(self._array, self.length, root, 0)
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
    def length(self):
        return len(self._array)


class ArrayList(List):

    def __init__(self, array: tList[int] = None):
        if array is None:
            array = []
        self._lst = array

    def size(self) -> int:
        pass
