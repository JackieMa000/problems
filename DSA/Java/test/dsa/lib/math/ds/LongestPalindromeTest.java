package dsa.lib.math.ds;

import org.junit.Test;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertNull;

public class LongestPalindromeTest {
    private static String getLongestPalindrome(String s) {
        String r1 = new Palindrome().longestPalindrome(s);
        String r2 = new Palindrome().longestPalindrome1(s);
        assert r1 == null || r1.equals(r2) : "Results from 2 same functions are different.";

        return r1;
    }

    @Test
    public void nullCase() {
        assertNull(getLongestPalindrome(null));
    }

    @Test
    public void emptyString() {
        assertEquals("", getLongestPalindrome(""));
    }

    @Test
    public void oneChar() {
        assertEquals("a", getLongestPalindrome("a"));
    }

    @Test
    public void case1() {
        assertEquals("aa", getLongestPalindrome("aa"));
        assertEquals("bab", getLongestPalindrome("babd"));
        assertEquals("bb", getLongestPalindrome("cbbd"));
        assertEquals("aaaa", getLongestPalindrome("aaaa"));
    }
}
