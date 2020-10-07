from dsa.lib.arrays.array import Array
from dsa.lib.lists.linkedlists.sls import SinglyLinkedList
from dsa.lib.lists.linkedlists.tests.test_ls import LinkedListTestCase
from dsa.nodes import ListNode


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