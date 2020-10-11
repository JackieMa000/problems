from abc import ABCMeta, abstractmethod


class List(metaclass=ABCMeta):
    @abstractmethod
    def size(self) -> int:
        pass
