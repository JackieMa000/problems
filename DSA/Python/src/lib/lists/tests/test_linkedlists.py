from typing import List

from lib.lists.arrays import Array
from lib.lists.linkedlists import SinglyLinkedList, LinkedList
from nodes import ListNode
from testing import DSATestCase


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

    @staticmethod
    def get_node_by_index(head: ListNode, idx: int) -> ListNode:
        ls: LinkedList = LinkedList(head)
        return ls.get_node_by_index(idx)


class SinglyLinkedListTestCase(LinkedListTestCase):
    pass


class ToArrayTestCase(SinglyLinkedListTestCase):
    def test_case1(self):
        head: ListNode = Array([1, 2, 3, 4]).to_singly_linkedList()
        self.assertEqual([1, 2, 3, 4], SinglyLinkedList(head).to_array())


class ReverseTestCase(SinglyLinkedListTestCase):
    def test_case1(self):
        head: ListNode = Array([1]).to_singly_linkedList()
        self.assertArrayEqualsLinkedList([1], SinglyLinkedList(head).reverse())

    def test_case2(self):
        head: ListNode = Array([1, 2, 3]).to_singly_linkedList()
        self.assertArrayEqualsLinkedList([3, 2, 1], SinglyLinkedList(head).reverse())


class ReverseBeforeTestCase(SinglyLinkedListTestCase):
    def test_case1(self):
        head: ListNode = Array([1, 2, 3, 4, 5]).to_singly_linkedList()
        ls: SinglyLinkedList = SinglyLinkedList(head)
        node: ListNode = ls.get_node_by_index(2)
        self.assertArrayEqualsLinkedList([2, 1, 3, 4, 5], ls.reverse_before(node))

    def test_case2(self):
        head: ListNode = Array([1, 2, 3, 4, 5]).to_singly_linkedList()
        ls: SinglyLinkedList = SinglyLinkedList(head)
        node: ListNode = ls.get_node_by_index(4)
        self.assertArrayEqualsLinkedList([4, 3, 2, 1, 5], ls.reverse_before(node))


class ReverseFromToTestCase(SinglyLinkedListTestCase):
    def test_case1(self):
        head: ListNode = Array([1, 2, 3, 4, 5]).to_singly_linkedList()
        ls: SinglyLinkedList = SinglyLinkedList(head)
        fnode: ListNode = ls.get_node_by_index(2)
        tnode: ListNode = ls.get_node_by_index(4)
        self.assertArrayEqualsLinkedList([1, 2, 4, 3, 5], ls.reverse_from_to(fnode, tnode))

    def test_case2(self):
        head: ListNode = Array([1, 2, 3, 4, 5, 6]).to_singly_linkedList()
        ls: SinglyLinkedList = SinglyLinkedList(head)
        fnode: ListNode = ls.get_node_by_index(2)
        tnode: ListNode = ls.get_node_by_index(4)
        self.assertArrayEqualsLinkedList([1, 2, 4, 3, 5, 6], ls.reverse_from_to(fnode, tnode))

    def test_case3(self):
        head: ListNode = Array([1, 2, 3]).to_singly_linkedList()
        ls: SinglyLinkedList = SinglyLinkedList(head)
        fnode: ListNode = ls.get_node_by_index(0)
        tnode: ListNode = ls.get_node_by_index(1)
        self.assertArrayEqualsLinkedList([1, 2, 3], ls.reverse_from_to(fnode, tnode))

    def test_case4(self):
        head: ListNode = Array([1, 2, 3]).to_singly_linkedList()
        ls: SinglyLinkedList = SinglyLinkedList(head)
        fnode: ListNode = ls.get_node_by_index(0)
        tnode: ListNode = ls.get_node_by_index(2)
        self.assertArrayEqualsLinkedList([2, 1, 3], ls.reverse_from_to(fnode, tnode))
