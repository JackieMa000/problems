from unittest import TestCase

from dsa.container.lists.queues import Deque


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
