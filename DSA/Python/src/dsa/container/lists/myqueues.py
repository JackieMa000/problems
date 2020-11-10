from dsa.container.lists.queues import Queue, Stack


# LeetCode232
class MyQueue:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self._input = Stack()
        self._output = Stack()

    def push(self, x: int) -> None:
        """
        Push element x to the back of queue.
        """
        self._input.push(x)

    def pop(self) -> int:
        """
        Removes the element from in front of queue and returns that element.
        """
        if self._output.is_empty(): self._migrate()
        return self._output.pop()

    def peek(self) -> int:
        """
        Get the front element.
        """
        if self._output.is_empty(): self._migrate()
        return self._output.top()

    def empty(self) -> bool:
        """
        Returns whether the queue is empty.
        """
        return self._input.is_empty() and self._output.is_empty()

    def front(self) -> int:
        return self.peek()

    def size(self) -> int:
        return self._input.size() + self._output.size()

    # Migrate the input stack to the output stack. The order gets reversed.
    def _migrate(self) -> None:
        while not self._input.is_empty(): self._output.push(self._input.pop())


# LeetCode225
class MyStack:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self._queue = Queue()

    def push(self, x: int) -> None:
        """
        Push element x onto stack.
        """
        self._queue.push(x)
        self.invert_queue(self._queue)

    def pop(self) -> int:
        """
        Removes the element on front of the stack and returns that element.
        """
        return self._queue.pop()

    def top(self) -> int:
        """
        Get the front element.
        """
        return self._queue.peek()

    def empty(self) -> bool:
        """
        Returns whether the stack is empty.
        """
        return self._queue.is_empty()

    def size(self) -> int:
        return self._queue.size()

    @staticmethod
    def invert_queue(queue: Queue) -> None:
        for _ in range(queue.size() - 1): queue.push(queue.pop())