from dsa.lib.lists.linkedlists.sls import SinglyLinkedList
from dsa.lib.lists.linkedlists.tests.test_ls import LinkedListTestCase
from dsa.nodes import ListNode


class SinglyLinkedListTestCase(LinkedListTestCase):
    pass


class ToArrayTest(SinglyLinkedListTestCase):
    def test_null_list(self):
        self.assertIsNone(self.to_array(None))

    def test_case1(self):
        ary = [1, 2, 3, 4]
        self.assertEqual(ary, self.to_array(self.array_to_singly_linkedlist(ary)))

    @staticmethod
    def to_array(head):
        return SinglyLinkedList(head).to_array()


class ReverseTest(SinglyLinkedListTestCase):
    def test_case1(self):
        self.assertArrayEqualsLinkedList([1], self.reverse(self.array_to_singly_linkedlist([1])))

    def test_case2(self):
        self.assertArrayEqualsLinkedList([3, 2, 1], self.reverse(self.array_to_singly_linkedlist([1, 2, 3])))

    @staticmethod
    def reverse(head):
        return SinglyLinkedList(head).reverse()


class ReverseBeforeTest(SinglyLinkedListTestCase):
    def test_case1(self):
        head = self.array_to_singly_linkedlist([1, 2, 3, 4, 5])
        self.assertArrayEqualsLinkedList([2, 1, 3, 4, 5], self.reverseBeforeIndex(head, 2))

    def test_case2(self):
        head: ListNode = self.array_to_singly_linkedlist([1, 2, 3, 4, 5])
        self.assertArrayEqualsLinkedList([4, 3, 2, 1, 5], self.reverseBeforeIndex(head, 4))

    @staticmethod
    def reverseBeforeIndex(head: ListNode, i: int):
        ls: SinglyLinkedList = SinglyLinkedList(head)
        return ls.reverse_before(ls.get_node_by_index(i))


class ReverseFromToTest(SinglyLinkedListTestCase):
    def test_case1(self):
        head: ListNode = self.array_to_singly_linkedlist([1, 2, 3, 4, 5])
        self.assertArrayEqualsLinkedList([1, 2, 4, 3, 5], self.reverse_from_to(head, 2, 4))

    def test_case2(self):
        head: ListNode = self.array_to_singly_linkedlist([1, 2, 3, 4, 5, 6])
        self.assertArrayEqualsLinkedList([1, 2, 4, 3, 5, 6], self.reverse_from_to(head, 2, 4))

    def test_case3(self):
        head: ListNode = self.array_to_singly_linkedlist([1, 2, 3])
        self.assertArrayEqualsLinkedList([1, 2, 3], self.reverse_from_to(head, 0, 1))

    def test_case4(self):
        head: ListNode = self.array_to_singly_linkedlist([1, 2, 3])
        self.assertArrayEqualsLinkedList([2, 1, 3], self.reverse_from_to(head, 0, 2))

    @staticmethod
    def reverse_from_to(head: ListNode, from_idx: int, to_idx: int):
        ls: SinglyLinkedList = SinglyLinkedList(head)
        return ls.reverse_from_to(ls.get_node_by_index(from_idx), ls.get_node_by_index(to_idx))
