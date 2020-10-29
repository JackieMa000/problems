import collections
import unittest


# stack using list
class MyQueue_1:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.stack = []

    def push(self, x: int) -> None:
        """
        Push element x to the back of queue.
        """
        self.stack.append(x)

    def pop(self) -> int:
        """
        Removes the element from in front of queue and returns that element.
        """
        return self.stack.pop(0)

    def peek(self) -> int:
        """
        Get the front element.
        """
        return self.stack[0]

    def empty(self) -> bool:
        """
        Returns whether the queue is empty.
        """
        return not self.stack


# stack using dequeue
class MyQueue:

    def __init__(self):
        """
        Initialize your data str
        """
        self.stack = collections.deque()

    def push(self, x: int) -> None:
        """
        Push element x to the ba
        """
        self.stack.append(x)

    def pop(self) -> int:
        """
        Removes the element from
        """
        return self.stack.popleft()

    def peek(self) -> int:
        """
        Get the front element.
        """
        return self.stack[0]

    def empty(self) -> bool:
        """
        Returns whether the queu
        """
        return not self.stack


# Your MyQueue object will be instantiated and called as such:
# obj = MyQueue()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.peek()
# param_4 = obj.empty()

class QueueTestCase(unittest.TestCase):
    def setUp(self):
        self.queue = MyQueue()

    def test_empty(self):
        self.assertTrue(self.queue.empty())

    def test_push_1_pop_1(self):
        self.queue.push(1)
        self.assertEqual(1, self.queue.pop())

    def test_push_1_queue_not_empty(self):
        self.queue.push(1)
        self.assertFalse(self.queue.empty())

    def test_push_0_1_pop_1_0(self):
        self.queue.push(0)
        self.queue.push(1)
        self.assertEqual(0, self.queue.pop())
        self.assertEqual(1, self.queue.pop())

    def test_push_1_peek_1(self):
        self.queue.push(1)
        self.assertEqual(1, self.queue.peek())

    def test_push_0_1_peek_0(self):
        self.queue.push(0)
        self.queue.push(1)
        self.assertEqual(0, self.queue.peek())

    def test_all_together(self):
        self.queue.push(1)
        self.queue.push(2)
        self.assertEqual(1, self.queue.peek())
        self.assertEqual(1, self.queue.pop())
        self.assertFalse(self.queue.empty())


if __name__ == '__main__':
    unittest.main()
