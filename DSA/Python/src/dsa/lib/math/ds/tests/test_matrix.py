from unittest import TestCase

from dsa.lib.math.ds.matrix import Matrix


class SearchMatrixTest(TestCase):
    def test_empty(self):
        self.assertFalse(self.searchMatrix([], 1))
        self.assertFalse(self.searchMatrix([[]], 1))

    def test_oneElement(self):
        self.assertFalse(self.searchMatrix([[1]], 3))
        self.assertTrue(self.searchMatrix([[1]], 1))

    def test_case1(self):
        self.assertTrue(self.searchMatrix([[1, 2, 3, 4],
                                           [5, 6, 7, 8],
                                           [9, 10, 11, 12]], 7))
        self.assertTrue(self.searchMatrix([[1, 3, 5, 7],
                                           [10, 11, 16, 20],
                                           [23, 30, 34, 50]
                                           ], 5))
        self.assertTrue(self.searchMatrix([[1, 3, 5, 7],
                                           [10, 11, 16, 20],
                                           [23, 30, 34, 50]], 3))
        self.assertFalse(self.searchMatrix([[1, 3, 5, 7],
                                            [10, 11, 16, 20],
                                            [23, 30, 34, 50]
                                            ], 13))

    @staticmethod
    def searchMatrix(matrix, target):
        r1 = Matrix().searchMatrix(matrix, target)
        r2 = Matrix().searchMatrix1(matrix, target)
        assert r1 == r2, "Results from 2 same functions are different.";

        return r1
