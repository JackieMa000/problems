class Queue(list):

    def pop(self, index=0):
        return super().pop(index)

    def is_empty(self) -> bool:
        return len(self) == 0

    def size(self) -> int:
        return len(self)

    def add(self, item) -> None:
        super().append(item)


class Stack(list):

    def is_empty(self) -> bool:
        return len(self) == 0

    def size(self) -> int:
        return len(self)

    def add(self, item) -> None:
        super().append(item)


class PriorityQueue(list):
    pass
