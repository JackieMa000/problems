import unittest
from typing import List

from converters import Converter
from nodes import ListNode
from solutions import Solution1, Solution2, Solution3, Solution4, Solution5


class SolutionsTestCase(unittest.TestCase):
    def setUp(self):
        self.converter = Converter()

    def test_solution1(self):
        self.assert_array_equals_linkedlist([2, 1, 4, 3], Solution1().swapPairs(
            self.converter.array_to_linkedlist([1, 2, 3, 4])))
        self.assert_array_equals_linkedlist([2, 1, 4, 3, 5], Solution1().swapPairs(
            self.converter.array_to_linkedlist([1, 2, 3, 4, 5])))

    def test_solution2(self):
        self.assert_array_equals_linkedlist([2, 1, 4, 3], Solution2().swapPairs(
            self.converter.array_to_linkedlist([1, 2, 3, 4])))
        self.assert_array_equals_linkedlist([2, 1, 4, 3, 5], Solution2().swapPairs(
            self.converter.array_to_linkedlist([1, 2, 3, 4, 5])))

    def test_solution3(self):
        self.assert_array_equals_linkedlist([2, 1, 4, 3], Solution3().swapPairs(
            self.converter.array_to_linkedlist([1, 2, 3, 4])))
        self.assert_array_equals_linkedlist([2, 1, 4, 3, 5], Solution3().swapPairs(
            self.converter.array_to_linkedlist([1, 2, 3, 4, 5])))

    def test_solution4(self):
        self.assert_array_equals_linkedlist([2, 1, 4, 3], Solution4().swapPairs(
            self.converter.array_to_linkedlist([1, 2, 3, 4])))
        self.assert_array_equals_linkedlist([2, 1, 4, 3, 5], Solution4().swapPairs(
            self.converter.array_to_linkedlist([1, 2, 3, 4, 5])))

    def test_solution5(self):
        self.assert_array_equals_linkedlist([2, 1, 4, 3], Solution5().swapPairs(
            self.converter.array_to_linkedlist([1, 2, 3, 4])))
        self.assert_array_equals_linkedlist([2, 1, 4, 3, 5], Solution5().swapPairs(
            self.converter.array_to_linkedlist([1, 2, 3, 4, 5])))

    def assert_array_equals_linkedlist(self, array: List[int], head: ListNode) -> None:
        for x in array:
            self.assertEqual(x, head.val)
            head = head.next
        self.assertIsNone(head)
