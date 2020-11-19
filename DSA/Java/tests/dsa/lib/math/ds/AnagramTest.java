package dsa.lib.math.ds;

import org.junit.Test;

import static org.junit.Assert.*;

public class AnagramTest {

    @Test
    public void case1() {
        assertTrue(isAnagram("anagram", "nagaram"));
        assertFalse(isAnagram("rat", "car"));
    }

    private boolean isAnagram(String s, String t) {
        return new Anagram().isAnagram(s, t);
    }

}