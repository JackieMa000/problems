from dsa.lib.lists.linkedlists.ls import LinkedList
from dsa.lib.lists.linkedlists.tests.fixture import LinkedListTestCase
from dsa.nodes import ListNode


class ReverseTest(LinkedListTestCase):
    def test_case1(self):
        self.assertArrayEqualsLinkedList([1], self.reverse(self.array_to_singly_linkedlist([1])))

    def test_case2(self):
        self.assertArrayEqualsLinkedList([3, 2, 1], self.reverse(self.array_to_singly_linkedlist([1, 2, 3])))

    @staticmethod
    def reverse(head):
        return LinkedList(head).reverse()


class ReverseBeforeTest(LinkedListTestCase):
    def test_case1(self):
        head = self.array_to_singly_linkedlist([1, 2, 3, 4, 5])
        self.assertArrayEqualsLinkedList([2, 1, 3, 4, 5], self.reverseBeforeIndex(head, 2))

    def test_case2(self):
        head: ListNode = self.array_to_singly_linkedlist([1, 2, 3, 4, 5])
        self.assertArrayEqualsLinkedList([4, 3, 2, 1, 5], self.reverseBeforeIndex(head, 4))

    @staticmethod
    def reverseBeforeIndex(head: ListNode, i: int):
        ls: LinkedList = LinkedList(head)
        return ls.reverse_before(ls.get_node_by_index(i))


class ReverseFromToTest(LinkedListTestCase):
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
        ls: LinkedList = LinkedList(head)
        return ls.reverse_from_to(ls.get_node_by_index(from_idx), ls.get_node_by_index(to_idx))


class HasCycleTest(LinkedListTestCase):
    def test_case1(self):
        self.assertFalse(self.hasCycle(self.array_to_singly_linkedlist([1])))

    def test_case2(self):
        self.assertTrue(self.hasCycle(self.array_to_cyclic_linkedlist([1, 2], 0)))

    def test_case3(self):
        self.assertTrue(self.hasCycle(self.array_to_cyclic_linkedlist([3, 2, 0, 4], 1)))

    @staticmethod
    def hasCycle(head):
        return LinkedList(head).hasCycle()


class DetectCycleTest(LinkedListTestCase):
    def test_case1(self):
        self.assertIsNone(self.detectCycle(self.array_to_singly_linkedlist([1])))

    def test_case2(self):
        head = self.array_to_cyclic_linkedlist([1, 2], 0)
        self.assertEqual(self.get_linkedlist_node_by_index(head, 0), self.detectCycle(head))

    def test_case3(self):
        head = self.array_to_cyclic_linkedlist([3, 2, 0, -4], 1)
        self.assertEqual(self.get_linkedlist_node_by_index(head, 1), self.detectCycle(head))

    @staticmethod
    def detectCycle(head):
        return LinkedList(head).detectCycle()


class SwapPairsTest(LinkedListTestCase):
    def test_emptyList(self):
        self.assertArrayEqualsLinkedList([], self.swapPairs(self.array_to_singly_linkedlist([])))

    def test_oneNode(self):
        self.assertArrayEqualsLinkedList([1], self.swapPairs(self.array_to_singly_linkedlist([1])))

    def test_case1(self):
        self.assertArrayEqualsLinkedList([2, 1, 4, 3], self.swapPairs(self.array_to_singly_linkedlist([1, 2, 3, 4])))

    @staticmethod
    def swapPairs(head):
        return LinkedList(head).swapPairs()
