from unittest import TestCase

from dsa.container.lists.queues import Deque, MaxPriorityQueue, MinPriorityQueue


class TestDeque(TestCase):
    def setUp(self):
        self.deque = Deque()

    def test_empty_queue(self):
        self.assertTrue(self.deque.empty())

    def test_push_not_empty(self):
        self.deque.push(1)
        self.assertFalse(self.deque.empty())

    def test_push_right(self):
        self.deque.pushright(1)
        self.deque.pushright(2)
        self.assertEqual(2, self.deque.peekright())

    def test_pop_empty(self):
        self.deque.push(1)
        self.deque.pop()
        self.assertEqual(0, self.deque.size())

    def test_popright(self):
        self.deque.push(1)
        self.deque.push(2)
        self.assertEqual(1, self.deque.popright())

    def test_popleft(self):
        self.deque.push(1)
        self.deque.push(2)
        self.assertEqual(2, self.deque.popleft())

    def test_peekright(self):
        self.deque.push(1)
        self.deque.push(2)
        self.assertEqual(1, self.deque.peekright())

    def test_peekleft(self):
        self.deque.push(1)
        self.deque.push(2)
        self.assertEqual(2, self.deque.peekleft())


class TestMinPriorityQueue(TestCase):

    def setUp(self):
        self.queue = MinPriorityQueue()

    def test_empty(self):
        self.assertTrue(self.queue.empty())

    def test_push_not_empty(self):
        self.queue.push(1)
        self.assertFalse(self.queue.empty())

    def test_pop_empty(self):
        self.queue.push(1)
        self.queue.pop()
        self.assertTrue(self.queue.empty())

    def test_push_pop(self):
        self.queue.push(1)
        self.queue.push(3)
        self.queue.push(2)
        self.assertEqual(1, self.queue.pop())

    def test_peek(self):
        self.queue.push(1)
        self.queue.push(3)
        self.queue.push(2)
        self.assertEqual(1, self.queue.peek())
        self.assertEqual(1, self.queue.top())


class TestMaxPriorityQueue(TestCase):

    def setUp(self):
        self.queue = MaxPriorityQueue()

    def test_empty(self):
        self.assertTrue(self.queue.empty())

    def test_push_not_empty(self):
        self.queue.push(1)
        self.assertFalse(self.queue.empty())

    def test_pop_empty(self):
        self.queue.push(1)
        self.queue.pop()
        self.assertTrue(self.queue.empty())

    def test_push_pop(self):
        self.queue.push(1)
        self.queue.push(3)
        self.queue.push(2)
        self.assertEqual(3, self.queue.pop())

    def test_peek(self):
        self.queue.push(1)
        self.queue.push(3)
        self.queue.push(2)
        self.assertEqual(3, self.queue.peek())
        self.assertEqual(3, self.queue.top())
