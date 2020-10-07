from typing import List

from dsa.lib.arrays.array import Array
from dsa.lib.lists.linkedlists.ls import LinkedList
from dsa.nodes import ListNode
from dsa.testing import DSATestCase


class LinkedListTestCase(DSATestCase):
    @staticmethod
    def generateSinglyLinkedListFromArray(ary: List[int]):
        return Array(ary).to_singly_linkedList()


class SizeTestCase(LinkedListTestCase):
    @staticmethod
    def get_size(head: ListNode):
        return LinkedList(head).size()

    def test_case1(self):
        self.assertEqual(1, self.get_size(self.generateSinglyLinkedListFromArray([1])))

    def test_case2(self):
        self.assertEqual(3, self.get_size(self.generateSinglyLinkedListFromArray([1, 2, 3])))

    def test_case3(self):
        self.assertEqual(4, self.get_size(self.generateSinglyLinkedListFromArray([1, 2, 3, 4])))


class GetNodeByIndexTestCase(LinkedListTestCase):
    def test_case1(self):
        self.assertEqual(3, self.get_node_by_index(self.generateSinglyLinkedListFromArray([1, 2, 3, 4, 5]), 2).val)

    def test_case2(self):
        self.assertEqual(1, self.get_node_by_index(self.generateSinglyLinkedListFromArray([1, 2, 3, 4, 5]), 0).val)

    def test_case3(self):
        self.assertEqual(5, self.get_node_by_index(self.generateSinglyLinkedListFromArray([1, 2, 3, 4, 5]), 4).val)

    def test_index_not_exist(self):
        self.assertIsNone(self.get_node_by_index(self.generateSinglyLinkedListFromArray([1]), 2))

    @staticmethod
    def get_node_by_index(head: ListNode, idx: int) -> ListNode:
        return LinkedList(head).get_node_by_index(idx)


class GetNodeByValueTest(LinkedListTestCase):
    def test_case1(self):
        self.assertEqual(1, self.get_node(self.generateSinglyLinkedListFromArray([1]), 1).val)

    def test_case2(self):
        self.assertEqual(3, self.get_node(self.generateSinglyLinkedListFromArray([1, 2, 3]), 3).val)

    def test_value_not_exist(self):
        self.assertIsNone(self.get_node(self.generateSinglyLinkedListFromArray([1]), 2))

    @staticmethod
    def get_node(head: ListNode, val: int) -> ListNode:
        actual: ListNode = LinkedList(head).get_node_by_value(val)
        return actual