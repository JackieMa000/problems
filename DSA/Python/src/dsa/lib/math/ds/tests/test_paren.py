from dsa.lib.math.ds.paren import Parentheses
from dsa.lib.math.ds.tests.fixture import ParenthesesTestCase


class IsValidTest(ParenthesesTestCase):
    def test_empty_string(self):
        self.assertTrue(self.is_valid(''))

    def test_case1(self):
        self.assertTrue(self.is_valid('()'))
        self.assertTrue(self.is_valid("()[]{}"))
        self.assertTrue(self.is_valid("{[]}"))

    def test_case2(self):
        self.assertFalse(self.is_valid("(]"))
        self.assertFalse(self.is_valid("([)]"))
        self.assertFalse(self.is_valid(']'))
        self.assertFalse(self.is_valid('['))

    @staticmethod
    def is_valid(s: str) -> bool:
        return Parentheses().isValid(s)
