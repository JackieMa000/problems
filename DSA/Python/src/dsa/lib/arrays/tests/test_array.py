from typing import List

from dsa.lib.arrays.array import Array
from dsa.lib.tests.test_lib import LibTestCase
from dsa.nodes import ListNode


class ArrayTestCase(LibTestCase):
    pass


class ToSinglyLinkedListTest(ArrayTestCase):
    def test_empty_array(self):
        self.assertIsNone(self.toList([]))

    def test_first_element0(self):
        self.assertIsNone(self.toList([0]))
        self.assertIsNone(self.toList([0, 1]))

    def test_case1(self):
        ary: List[int] = [1, 2, 3, 4]
        self.assertArrayEqualsLinkedList(ary, self.toList(ary))

    @staticmethod
    def toList(ary):
        return Array(ary).to_singly_linkedList()


class ToCyclicSinglyLinkedListTest(ArrayTestCase):

    def test_pos_minus(self):
        self.assertArrayEqualsLinkedList([1, 2, 3], self._get_cyclic_singly_linkedList([1, 2, 3], -1))
        self.assertArrayEqualsLinkedList([1, 2, 3], self._get_cyclic_singly_linkedList([1, 2, 3], -5))

    def test_case1(self):
        head: ListNode = self._get_cyclic_singly_linkedList([1, 2, 3], 0)
        self.assertEqual(1, self.get_linkedList_node_by_index(head, 3).val)

    def test_case2(self):
        head: ListNode = self._get_cyclic_singly_linkedList([1, 2, 3, -1], 1)
        self.assertEqual(2, self.get_linkedList_node_by_index(head, 4).val)

    def test_case3(self):
        head: ListNode = self._get_cyclic_singly_linkedList([1, 2, 3], 2)
        self.assertEqual(3, self.get_linkedList_node_by_index(head, 4).val)

    @staticmethod
    def _get_cyclic_singly_linkedList(ary: List[int], pos: int) -> ListNode:
        return Array(ary).to_cyclic_singly_linkedList(pos)


class ToBinaryTreeTest(ArrayTestCase):
    def test_empty_array(self):
        self.assertIsNone(self.to_binary_tree([]))

    def test_first_element0(self):
        self.assertIsNone(self.to_binary_tree([0]))
        self.assertIsNone(self.to_binary_tree([0, 1]))

    def test_case1(self):
        ary = [3, 1, 5, 0, 2]
        self.assertArrayEqualsTree(ary, self.to_binary_tree(ary))

    def test_case2(self):
        ary = [5, 1, 4, 0, 6, 3, 6]
        self.assertArrayEqualsTree(ary, self.to_binary_tree(ary))

    def test_case3(self):
        ary = [5, 1, 0, 6, 0, 0]
        self.assertArrayEqualsTree(ary, self.to_binary_tree(ary))

    def test_case5(self):
        ary = [1, 0]
        self.assertArrayEqualsTree(ary, self.to_binary_tree(ary))

    @staticmethod
    def to_binary_tree(ary):
        return Array(ary).to_binary_tree()
