from typing import List
from unittest import skip

from dsa.lib.arrays.array import Array
from dsa.lib.lists.linkedlists.sls import SinglyLinkedList
from dsa.nodes import ListNode
from dsa.testing import DSATestCase


class ArrayTestCase(DSATestCase):
    pass


class ToSinglyLinkedListTestCase(ArrayTestCase):
    def test_case1(self):
        ary: List[int] = [1, 2, 3, 4]
        self.assertArrayEqualsLinkedList(ary, Array(ary).to_singly_linkedList())


class ToCyclicSinglyLinkedListTestCase(ArrayTestCase):
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

    def _get_cyclic_singly_linkedList(self, ary: List[int], pos: int) -> ListNode:
        return Array(ary).to_cyclic_singly_linkedList(pos)


class ToBinaryTreeTestCase(ArrayTestCase):
    def test_case1(self):
        self.assert_array([3, 1, 5, 0, 2])

    def test_case2(self):
        self.assert_array([5, 1, 4, 0, 6, 3, 6])

    def test_case3(self):
        self.assert_array([5, 1, 0, 6, 0, 0])

    def test_case5(self):
        self.assert_array([1, 0])

    def test_null_node(self):
        self.assertIsNone(Array([0]).to_binary_tree())

    def assert_array(self, nums: List[int]) -> None:
        root = Array(nums).to_binary_tree()
        self.assertArrayEqualsTree(nums, root)
