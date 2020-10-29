import unittest


class Solution(object):
    def isValid(self, s: str) -> bool:
        length = -1
        while length !=  len(s):
            length = len(s)
            s = s.replace('()', '').replace('[]', '').replace('{}', '')
        return len(s) == 0

    # Stack
    def isValid_1(self, s: str) -> bool:
        stack = []
        paren_map = {')': '(', '}': '{', ']': '['}
        for c in s:
            if c not in paren_map:
                stack.append(c)
            elif not stack or paren_map.get(c) != stack.pop():
                return False
        return not stack


def is_valid(s: str):
    return Solution().isValid(s)


class MyTestCase(unittest.TestCase):
    def test_something(self):
        self.assertTrue(is_valid(''))
        self.assertTrue(is_valid('()'))
        self.assertTrue(is_valid("()[]{}"))
        self.assertFalse(is_valid("(]"))
        self.assertFalse(is_valid("([)]"))
        self.assertTrue(is_valid("{[]}"))
        self.assertFalse(is_valid(']'))
        self.assertFalse(is_valid('['))


if __name__ == '__main__':
    unittest.main()
