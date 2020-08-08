import collections
import unittest


class LRUCache:

    def __init__(self, capacity: int):
        self.remain = capacity
        self.cache = collections.OrderedDict()

    def get(self, key: int) -> int:
        if key not in self.cache: return -1

        value = self.cache.pop(key)
        self.cache[key] = value  # set key as the newest one
        return value

    def put(self, key: int, value: int) -> None:
        if key in self.cache:
            self.cache.pop(key)
        else:
            if self.remain:
                self.remain -= 1
            else:
                self.cache.popitem(last=False)
        self.cache[key] = value

    def print(self):
        print(self.cache)


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
