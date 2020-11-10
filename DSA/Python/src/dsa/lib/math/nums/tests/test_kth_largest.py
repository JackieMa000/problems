from dsa.lib.math.nums.kth_largest import KthLargest
from dsa.lib.math.nums.tests.fixture import KthLargestTestCase


class AddTest(KthLargestTestCase):
    def test_add(self):
        largest = KthLargest(3, [4, 5, 8, 2])
        self.assertEqual(4, largest.add(3))
        self.assertEqual(5, largest.add(5))
        self.assertEqual(5, largest.add(10))
        self.assertEqual(8, largest.add(9))
        self.assertEqual(8, largest.add(4))
