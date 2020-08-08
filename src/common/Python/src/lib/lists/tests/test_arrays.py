from typing import List

from lib.lists.arrays import Array
from nodes import BinaryTreeNode
from testing import DSATestCase


class ArrayTestCase(DSATestCase):
    pass


class ToSinglyLinkedListTestCase(ArrayTestCase):
    def test_case1(self):
        array: List[int] = [1, 2, 3, 4]
        self.assertArrayEqualsLinkedList(array, Array(array).to_singlylinkedlist())


class ToBinaryTreeTestCase(ArrayTestCase):
    def test_case1(self):
        array: List[int] = [3, 1, 5, 0, 2]
        actual: BinaryTreeNode = Array(array).to_binary_tree()
        self.assertTreeEqualsArray(actual, 0, array)

    def test_case2(self):
        nums: List[int] = [5, 1, 4, 0, 6, 3, 6]
        self.assertTreeEqualsArray(Array(nums).to_binary_tree(), 0, nums)