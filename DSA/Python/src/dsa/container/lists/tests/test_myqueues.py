from dsa.container.lists.myqueues import MyQueue, MyStack
from dsa.container.lists.tests.fixture import ListTestCase


class MyQueueTest(ListTestCase):
    def setUp(self):
        self.queue = MyQueue()

    def test_empty_queue(self):
        self.assertTrue(self.queue.empty())

    def test_push_not_empty(self):
        self.queue.push(1)
        self.assertFalse(self.queue.empty())

    def test_pop_empty(self):
        self.queue.push(1)
        self.queue.pop()
        self.assertTrue(self.queue.empty())

    def test_size_empty(self):
        self.assertEqual(0, self.queue.size())

    def test_size_push(self):
        self.queue.push(1)
        self.queue.push(2)
        self.assertEqual(2, self.queue.size())

    def test_size_pop(self):
        self.queue.push(1)
        self.queue.push(2)

        self.queue.pop()
        self.assertEqual(1, self.queue.size())

    def test_push_peek(self):
        self.queue.push(1)
        self.queue.push(2)
        self.assertEqual(1, self.queue.peek())

    def test_push_pop(self):
        self.queue.push(1)
        self.queue.push(2)

        self.assertEqual(1, self.queue.pop())
        self.assertEqual(2, self.queue.pop())


class MyStackTest(ListTestCase):
    def setUp(self):
        self.stack = MyStack()

    def test_empty_stack(self):
        self.assertTrue(self.stack.empty())

    def test_push_not_empty(self):
        self.stack.push(1)
        self.assertFalse(self.stack.empty())

    def test_pop_empty(self):
        self.stack.push(1)
        self.stack.pop()
        self.assertTrue(self.stack.empty())

    def test_size_empty(self):
        self.assertEqual(0, self.stack.size())

    def test_size_push(self):
        self.stack.push(1)
        self.stack.push(2)
        self.assertEqual(2, self.stack.size())

    def test_size_pop(self):
        self.stack.push(1)
        self.stack.push(2)

        self.stack.pop()
        self.assertEqual(1, self.stack.size())

    def test_push_top(self):
        self.stack.push(1)
        self.stack.push(2)
        self.assertEqual(2, self.stack.top())

    def test_push_pop(self):
        self.stack.push(1)
        self.stack.push(2)

        self.assertEqual(2, self.stack.pop())
        self.assertEqual(1, self.stack.pop())
