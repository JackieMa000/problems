from unittest import TestCase

from dsa.lib.strings.edit_distance import EditDistance


class EditDistanceTest(TestCase):
    def test_emptyString(self):
        self.assertEqual(0, self.getDistance("", ""))
        self.assertEqual(1, self.getDistance("", "a"))
        self.assertEqual(1, self.getDistance("a", ""))

    def test_equalString(self):
        self.assertEqual(0, self.getDistance("abc", "abc"))

    def test_case1(self):
        self.assertEqual(3, self.getDistance('horse', 'ros'))
        self.assertEqual(5, self.getDistance('intention', 'execution'))

    @staticmethod
    def getDistance(w1, w2):
        return EditDistance().minDistance(w1, w2)
