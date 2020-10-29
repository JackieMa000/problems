from dsa.container.lists.myqueues import MyQueue, MyStack
from dsa.container.lists.tests.fixture import ListTestCase


class QueueTest(ListTestCase):
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


class StackTest(ListTestCase):
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
