
from lib.lists.arrays import Array
from nodes import ListNode
from reverseKGroup.solutions import Solution1, Solution2
from testing import DSATestCase


class Solution1TestCase(DSATestCase):
    def setUp(self):
        self.solution = Solution1()
        self.head: ListNode = Array([1, 2, 3, 4, 5]).to_singly_linkedList()

    def test_reverse_1group(self):
        self.assertArrayEqualsLinkedList([1, 2, 3, 4, 5], self.solution.reverseKGroup(self.head, 1))

    def test_reverse_2group(self):
        self.assertArrayEqualsLinkedList([2, 1, 4, 3, 5], self.solution.reverseKGroup(self.head, 2))

    def test_reverse_3group(self):
        self.assertArrayEqualsLinkedList([3, 2, 1, 4, 5], self.solution.reverseKGroup(self.head, 3))


class Solution2TestCase(DSATestCase):
    def setUp(self):
        self.solution = Solution2()
        self.head = Array([1, 2, 3, 4, 5]).to_singly_linkedList()

    def test_reverse_1group(self):
        self.assertArrayEqualsLinkedList([1, 2, 3, 4, 5], self.solution.reverseKGroup(self.head, 1))

    def test_reverse_2group(self):
        self.assertArrayEqualsLinkedList([2, 1, 4, 3, 5], self.solution.reverseKGroup(self.head, 2))

    def test_reverse_3group(self):
        self.assertArrayEqualsLinkedList([3, 2, 1, 4, 5], self.solution.reverseKGroup(self.head, 3))
