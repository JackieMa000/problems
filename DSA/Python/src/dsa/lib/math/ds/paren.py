from dsa.container.lists.queues import Stack


class Parentheses:
    # LeetCode20
    def isValid(self, s: str) -> bool:
        return self.isValid2(s)

    # Stack and Hash Map
    @staticmethod
    def isValid1(s: str) -> bool:
        paren_map = {')': '(', '}': '{', ']': '['}
        stack = Stack()
        for c in s:
            # Current character is an opening bracket.
            if c not in paren_map:
                stack.push(c)
            # Current character is a closing bracket
            elif not stack or stack.pop() != paren_map.get(c):
                return False
        # If the final stack is empty, the string is valid
        return not stack

    # Stack
    @staticmethod
    def isValid2(s: str) -> bool:
        stack: Stack = Stack()
        for c in s:
            # Opening bracket
            if c == '(':
                stack.push(')')
            elif c == '[':
                stack.push(']')
            elif c == '{':
                stack.push('}')
            # Closing bracket
            elif stack.empty() or stack.pop() != c:
                return False
        return stack.empty()
