from typing import List
from unittest import TestCase

from converters import Converter
from nodes import ListNode
from solutions import Solution1


class TestSolution1(TestCase):
    def test_has_cycle(self):
        # Arrange
        array: List[int] = [3, 2, 0, -4]
        pos: int = 1
        head: ListNode = Converter().array_to_linkedlist(array, pos)

        # Act
        actual: bool = Solution1().hasCycle(head)

        # Assert
        self.assertFalse(actual)
