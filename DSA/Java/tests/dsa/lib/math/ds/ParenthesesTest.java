package dsa.lib.math.ds;

import org.junit.Test;

import static org.junit.Assert.*;

public class ParenthesesTest extends DsTestFX {
    public static class IsValidTest {
        @Test
        public void emptyString() {
            assertTrue(isValid(""));
        }

        @Test
        public void case1() {
            assertTrue(isValid("()"));
            assertTrue(isValid("()[]{}"));
            assertTrue(isValid("{[]}"));
        }

        @Test
        public void case2() {
            assertFalse(isValid("(]"));
            assertFalse(isValid("([)]"));
            assertFalse(isValid("]"));
            assertFalse(isValid("["));
        }

        private boolean isValid(String s) {
            return new Parentheses().isValid(s);
        }
    }
}
