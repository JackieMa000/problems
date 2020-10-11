from typing import List
from unittest import skip

from dsa.lib.arrays.array import Array
from dsa.lib.lists.linkedlists.sls import SinglyLinkedList
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
    """
            public void case1() {
            ListNode head = getCyclicSinglyLinkedList(new int[]{3, 2, 1, -1}, 1);
            assertEquals(2, getLinkedListNodeByIndex(head, 4).val);
        }

        @Test
        public void case2() {
            ListNode head = getCyclicSinglyLinkedList(new int[]{1, 2}, 0);
            assertEquals(2, getLinkedListNodeByIndex(head, 3).val);
        }

        @Test
        public void case3() {
            ListNode head = getCyclicSinglyLinkedList(new int[]{1}, -1);
            assertEquals(1, new SinglyLinkedList(head).size());
        }

    """

    @skip('todo')
    def test_case1(self):
        head: ListNode = self._get_cyclic_singly_linkedList([3, 2, 1, -1], 1)
        self.assertEqual(2, self.get_linkedList_node_by_index(head, 4).val)

    @staticmethod
    def get_linkedList_node_by_index(head: ListNode, idx: int) -> ListNode:
        return SinglyLinkedList(head).get_node_by_index(idx)

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
