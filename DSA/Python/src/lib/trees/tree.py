from abc import ABCMeta, abstractmethod
from typing import List

from nodes import TreeNode


class Tree(metaclass=ABCMeta):

    @abstractmethod
    def to_array(self) -> List[int]:
        pass

    @abstractmethod
    def depth(self) -> int:
        pass

    @abstractmethod
    def size(self) -> int:
        pass

    @abstractmethod
    def get_node_by_index(self, idx: int) -> TreeNode:
        pass

    @abstractmethod
    def get_node_by_value(self, val: int) -> TreeNode:
        pass
