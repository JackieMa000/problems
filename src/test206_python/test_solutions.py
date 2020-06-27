import unittest

from converter import Converter
from nodes import ListNode
from solutions import Solution1, Solution2


class SolutionsTestCase(unittest.TestCase):
    def setUp(self):
        self.converter = Converter()

    def test_solution1(self):
        head: ListNode = self.converter.convert_array_to_linkedlist([1, 2, 3, 4, 5])
        actual: ListNode = Solution1().reverseList(head)
        self.assertEqual([5, 4, 3, 2, 1], self.converter.convert_linkedlist_to_array(actual))

    def test_solution2(self):
        head: ListNode = self.converter.convert_array_to_linkedlist([1, 2, 3, 4, 5])
        actual: ListNode = Solution2().reverseList(head)
        self.assertEqual([5, 4, 3, 2, 1], self.converter.convert_linkedlist_to_array(actual))


if __name__ == '__main__':
    unittest.main()
