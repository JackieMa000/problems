package dsa.lib.math.ds;

import java.util.HashMap;
import java.util.Map;
import java.util.Stack;

public class Parentheses {
    //    LeetCode20
    public boolean isValid(String s) {
        return isValid21(s);
    }

    //    Stack and Hash Map
    public static boolean isValid1(String s) {
//        Initialize the parentheses map
        Map<Character, Character> parenMap = new HashMap<>();
        parenMap.put(')', '(');
        parenMap.put('}', '{');
        parenMap.put(']', '[');

        Stack<Character> stack = new Stack<>();
        for (char c : s.toCharArray()) {
            // It is an opening bracket, push to the stack.
            if (!parenMap.containsKey(c)) stack.push(c);
            else if (stack.isEmpty() || stack.pop() != parenMap.get(c)) return false;
        }
        // If the stack is empty, it is valid.
        return stack.isEmpty();
    }

    //    Stack
    private static boolean isValid2(String s) {
        Stack<Character> stack = new Stack<>();
        for (char c : s.toCharArray()) {
//            Opening bracket
            if (c == '(') stack.push(')');
            else if (c == '{') stack.push('}');
            else if (c == '[') stack.push(']');
//            Closing bracket
            else if (stack.isEmpty() || stack.pop() != c) return false;
        }
        return stack.isEmpty();
    }

    private static boolean isValid21(String s) {
        Stack<Character> stack = new Stack<>();
        for (char c : s.toCharArray()) {
            switch (c) {
                case '(':
                    stack.push(')');
                    break;
                case '[':
                    stack.push(']');
                    break;
                case '{':
                    stack.push('}');
                    break;
                default:
                    if (stack.isEmpty() || stack.pop() != c) return false;
            }
        }
        return stack.isEmpty();
    }
}
