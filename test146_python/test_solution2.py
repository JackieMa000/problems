import unittest


class DLinkedNode:
    def __init__(self, key: int, value: int):
        self.key = key
        self.value = value
        self.prev = None
        self.next = None


class LRUCache:
    def __init__(self, capcacity: int):
        self.remain = capcacity
        self.dict = {}
        self.head, self.tail = DLinkedNode(0, 0), DLinkedNode(0, 0)
        self.head.next, self.tail.prev = self.tail, self.head

    def get(self, key: int) -> int:
        if key not in self.dict: return -1

        node = self.dict[key]
        self.remove_node_from_linkedlist(node)
        self.add_node_to_linkedlist(node)

        return node.value

    def put(self, key: int, value: int) -> None:
        if key in self.dict:
            self.remove_node_from_linkedlist(self.dict[key])
        else:
            if self.remain:
                self.remain -= 1
            else:
                p = self.head.next
                self.dict.pop(p.key)
                self.remove_node_from_linkedlist(p)

        node = DLinkedNode(key, value)
        self.dict[key] = node
        self.add_node_to_linkedlist(node)

    def add_node_to_linkedlist(self, node: DLinkedNode) -> None:
        p = self.tail.prev
        node.prev, node.next = p, self.tail
        p.next, self.tail.prev = node, node

    def remove_node_from_linkedlist(self, node: DLinkedNode) -> None:
        p, q = node.prev, node.next
        p.next, q.prev = q, p


class MyTestCase(unittest.TestCase):
    def test_something(self):
        cache = LRUCache(2)
        cache.put(1, 1)
        cache.put(2, 2)
        self.assertEqual(1, cache.get(1))
        cache.put(3, 3)
        self.assertEqual(-1, cache.get(2))
        cache.put(4, 4)
        self.assertEqual(-1, cache.get(1))
        self.assertEqual(3, cache.get(3))
        self.assertEqual(4, cache.get(4))

    def test_put_when_key_already_exists(self):
        cache = LRUCache(2)
        cache.put(1, 1)
        cache.put(2, 2)
        cache.put(2, 2)
        self.assertEqual(1, cache.get(1))
