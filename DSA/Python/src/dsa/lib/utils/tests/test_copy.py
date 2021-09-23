from dsa.lib.utils import lists
from dsa.lib.utils.tests.fixture import ListTestCase


class CopyTestCase(ListTestCase):
    @staticmethod
    def copy(src, src_pos, des, des_pos, n):
        lists.copy(src, src_pos, des, des_pos, n)

    def test_illegalArgument(self):
        x = [1]
        y = [0] * len(x)
        self.assertRaises(IndexError, self.copy, x, 1, y, 0, len(x))

    def test_copy0Elements_nothingChanged(self):
        x = [1]
        y = [0] * len(x)
        self.copy(x, 0, y, 0, 0)

        self.assertEqual([0], y)

    def test_empty_nothingChanged(self):
        x = []
        y = []
        self.copy(x, 0, y, 0, 0)

        self.assertEqual([], y)

    def test_oneElement(self):
        x = [1]
        y = [0] * len(x)
        self.copy(x, 0, y, 0, 1)

        self.assertEqual([1], y)

    def assertCopy(self, expected, src, src_pos, des, des_pos, n):
        self.copy(src, src_pos, des, des_pos, n)
        self.assertEqual(expected, des)

    def test_copy_all(self):
        x = [0, 1]
        y = [0] * len(x)
        self.copy(x, 0, y, 0, len(x))

        self.assertEqual(x, y)
        self.assertIsNot(x, y)

    def test_copy_sublist(self):
        x = [1, 2]
        y = [0]
        self.copy(x, 0, y, 0, 1)

        self.assertEqual(x[:1], y)
        self.assertIsNot(x[:1], y)

    def test_recursive_copy(self):
        x = [[1], [2]]
        y = [[0], [0]]
        self.copy(x, 0, y, 0, 2)

        self.assertEqual(x, y)
        self.assertIsNot(x, y)

        self.assertEqual(x[0], y[0])
        self.assertIsNot(x[0], y[0])

    def test_object_list(self):
        x = [self.C(1), self.C(2)]
        y = [0] * len(x)
        self.copy(x, 0, y, 0, 2)

        self.assertEqual(x, y)
        self.assertAllIsNot(x, y)


class CopyOfTestCase(ListTestCase):
    def test_illegalArgument(self):
        x = [1]
        self.assertRaises(IndexError, lists.copyOf, x, 2)

    def test_copy0Elements_returnEmptyList(self):
        x = [1]
        y = lists.copyOf(x, 0)
        self.assertEqual([], y)

    def test_empty(self):
        x = []
        y = lists.copyOf(x, len(x))

        self.assertEqual(x, y)
        self.assertIsNot(x, y)

    def test_oneElement(self):
        x = [1]
        y = lists.copyOf(x, len(x))

        self.assertEqual(x, y)
        self.assertIsNot(x, y)

    def test_copy_all(self):
        x = [1, 2]
        y = lists.copyOf(x, len(x))

        self.assertEqual(x, y)
        self.assertIsNot(x, y)

    def test_copy_sublist(self):
        x = [1, 2]
        y = lists.copyOf(x, 1)

        self.assertEqual(x[:1], y)
        self.assertIsNot(x[:1], y)

    def test_recursive_copy(self):
        x = [[1], [2]]
        y = lists.copyOf(x, 2)

        self.assertEqual(x, y)
        self.assertIsNot(x, y)

        self.assertEqual(x[0], y[0])
        self.assertIsNot(x[0], y[0])

    def test_object_list(self):
        x = [self.C(1), self.C(2)]
        y = lists.copyOf(x, 2)

        self.assertEqual(x, y)
        self.assertAllIsNot(x, y)


class CopyOfRangeTestCase(ListTestCase):
    def test_illegalArgument(self):
        x = [1, 2, 3]
        self.assertRaises(IndexError, lists.copyOfRange, x, 2, 1)

    def test_copy0Elements_returnEmptyList(self):
        x = [1]
        y = lists.copyOfRange(x, 0, 0)
        self.assertEqual([], y)

    def test_oneElement(self):
        x = [1]
        y = lists.copyOfRange(x, 0, 1)

        self.assertEqual(x, y)
        self.assertIsNot(x, y)

    def test_copy_all(self):
        x = [1, 2]
        y = lists.copyOfRange(x, 0, len(x))

        self.assertEqual(x, y)
        self.assertIsNot(x, y)

    def test_copy_sublist(self):
        x = [1, 2]
        y = lists.copyOfRange(x, 0, 1)

        self.assertEqual(x[:1], y)
        self.assertIsNot(x[:1], y)

    def test_recursive_copy(self):
        x = [[1], [2]]
        y = lists.copyOfRange(x, 0, len(x))

        self.assertEqual(x, y)
        self.assertIsNot(x, y)

    def test_object_list(self):
        x = [self.C(1), self.C(2)]
        y = lists.copyOfRange(x, 0, 2)

        self.assertEqual(x, y)
        self.assertAllIsNot(x, y)
