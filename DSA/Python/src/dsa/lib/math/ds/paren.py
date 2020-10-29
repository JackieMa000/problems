from dsa.container.lists.queues import Stack


class Parentheses:
    # LeetCode20
    # Stack and Hash Map
    @staticmethod
    def isValid(s: str) -> bool:
        stack = Stack()
        paren_map = {')': '(', '}': '{', ']': '['}
        for c in s:
            if c not in paren_map:
                stack.add(c)
            elif not stack or paren_map.get(c) != stack.pop():
                return False
        return not stack
