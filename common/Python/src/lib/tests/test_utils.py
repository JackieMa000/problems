from typing import List
from unittest import skip

import lib.utils
from testing import DSATestCase


class ArrayRstripTestCase(DSATestCase):
    # // FixMe: Edge cases
    def test_case1(self):
        array: List[int] = [3, 1, 5, 0, 2, 0, 0]
        self.assertEqual(array, lib.utils.array_rstrip(array))


class ArrayRstripDfsTestCase(DSATestCase):
    # ToDo
    @skip('')
    def case1(self):
        self.fail()