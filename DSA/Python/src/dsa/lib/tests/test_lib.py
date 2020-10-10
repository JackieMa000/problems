from typing import List

from dsa.lib.arrays.array import Array
from dsa.nodes import BinaryTreeNode
from dsa.testing import DSATestCase


class LibTestCase(DSATestCase):
    @staticmethod
    def array_to_binary_tree(ary: List[int]) -> BinaryTreeNode:
        return Array(ary).to_binary_tree()
