from typing import List, Any, Type
from unittest import TestCase


class ListTestCase(TestCase):
    class C:
        def __init__(self, foo: Any):
            self.foo = foo

        def __eq__(self, other_c) -> bool:
            return other_c.foo == self.foo

    def assertAllIsNot(self, expected: List[Any], actual: List[Any]) -> None:
        """
        Assert two objects are not the same.
        And all the respective elements of them are not the same also, recursively.

        Note: primitive type element should be identical.
        """
        self.assertEqual(len(expected), len(actual))
        self.assertIsNot(expected, actual)

        for i in range(len(actual)):
            self.assertIsNot(expected[i], actual[i])
            if isinstance(expected[i], list) and isinstance(actual[i], list):
                self.assertAllIsNot(expected[i], actual[i])
