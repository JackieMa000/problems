import collections
import unittest


class MyStack_1:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.queue = []


    def push(self, x: int) -> None:
        """
        Push element x onto stack.
        """
        self.queue.append(x)


    def pop(self) -> int:
        """
        Removes the element on top of the stack and returns that element.
        """
        return self.queue.pop()


    def top(self) -> int:
        """
        Get the top element.
        """
        return self.queue[-1]

    def empty(self) -> bool:
        """
        Returns whether the stack is empty.
        """
        return not self.queue


class MyStack:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.queue = collections.deque()


    def push(self, x: int) -> None:
        """
        Push element x onto stack.
        """
        self.queue.append(x)


    def pop(self) -> int:
        """
        Removes the element on top of the stack and returns that element.
        """
        return self.queue.pop()


    def top(self) -> int:
        """
        Get the top element.
        """
        return self.queue[-1]

    def empty(self) -> bool:
        """
        Returns whether the stack is empty.
        """
        return not self.queue


# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()

class StackTestCase(unittest.TestCase):
    def setUp(self):
        self.stack = MyStack()

    def test_empty(self):
        self.assertTrue(self.stack.empty())

    def test_push_1_pop_1(self):
        self.stack.push(1)
        self.assertEqual(1, self.stack.pop())

    def test_push_1_stack_not_empty(self):
        self.stack.push(1)
        self.assertFalse(self.stack.empty())

    def test_push_0_1_pop_1_0(self):
        self.stack.push(0)
        self.stack.push(1)
        self.assertEqual(1, self.stack.pop())
        self.assertEqual(0, self.stack.pop())

    def test_push_0_1_top_1(self):
        self.stack.push(0)
        self.stack.push(1)
        self.assertEqual(1, self.stack.top())

    def test_all_together(self):
        self.stack.push(1)
        self.stack.push(2)
        self.assertEqual(2, self.stack.top())
        self.assertEqual(2, self.stack.pop())
        self.assertFalse(self.stack.empty())


if __name__ == '__main__':
    unittest.main()
