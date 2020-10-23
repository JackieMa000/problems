from dsa.lib.lists.linkedlists.base import Base
from dsa.lib.lists.linkedlists.tests.fixture import LinkedListTestCase
from dsa.nodes import ListNode


class ToArrayTest(LinkedListTestCase):
    def test_null_list(self):
        self.assertIsNone(self.to_array(None))

    def test_case1(self):
        ary = [1, 2, 3, 4]
        self.assertEqual(ary, self.to_array(self.array_to_singly_linkedlist(ary)))

    @staticmethod
    def to_array(head):
        return Base(head).to_array()


class SizeTestCase(LinkedListTestCase):
    @staticmethod
    def get_size(head: ListNode):
        return Base(head).size()

    def test_case1(self):
        self.assertEqual(1, self.get_size(self.array_to_singly_linkedlist([1])))

    def test_case2(self):
        self.assertEqual(3, self.get_size(self.array_to_singly_linkedlist([1, 2, 3])))

    def test_case3(self):
        self.assertEqual(4, self.get_size(self.array_to_singly_linkedlist([1, 2, 3, 4])))


class GetNodeByIndexTestCase(LinkedListTestCase):
    def test_case1(self):
        self.assertEqual(3, self.get_linkedlist_node_by_index(self.array_to_singly_linkedlist([1, 2, 3, 4, 5]), 2).val)

    def test_case2(self):
        self.assertEqual(1, self.get_linkedlist_node_by_index(self.array_to_singly_linkedlist([1, 2, 3, 4, 5]), 0).val)

    def test_case3(self):
        self.assertEqual(5, self.get_linkedlist_node_by_index(self.array_to_singly_linkedlist([1, 2, 3, 4, 5]), 4).val)

    def test_index_not_exist(self):
        self.assertIsNone(self.get_linkedlist_node_by_index(self.array_to_singly_linkedlist([1]), 2))


class GetNodeByValueTest(LinkedListTestCase):
    def test_case1(self):
        self.assertEqual(1, self.get_node(self.array_to_singly_linkedlist([1]), 1).val)

    def test_case2(self):
        self.assertEqual(3, self.get_node(self.array_to_singly_linkedlist([1, 2, 3]), 3).val)

    def test_value_not_exist(self):
        self.assertIsNone(self.get_node(self.array_to_singly_linkedlist([1]), 2))

    @staticmethod
    def get_node(head: ListNode, val: int) -> ListNode:
        actual: ListNode = Base(head).get_node_by_value(val)
        return actual
