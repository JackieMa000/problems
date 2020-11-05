class Queue(list):

    def pop(self, index=0):
        """
        remove and return the front item from the queue
        """
        return super().pop(index)

    def is_empty(self) -> bool:
        return not len(self)

    def size(self) -> int:
        return len(self)

    def push(self, x) -> None:
        self.append(x)

    def peek(self) -> int:
        return self[0]

    def add(self, x) -> None:
        self.push(x)

    def front(self) -> int:
        return self.peek()

    def back(self) -> int:
        return self[-1]


class Stack(list):

    def is_empty(self) -> bool:
        return not len(self)

    def size(self) -> int:
        return len(self)

    def push(self, item) -> None:
        super().append(item)

    def peek(self) -> int:
        return self[-1]

    def add(self, item) -> None:
        self.push(item)

    def top(self) -> int:
        return self.peek()

    def bottom(self) -> int:
        return self[0]


class PriorityQueue(list):
    pass
