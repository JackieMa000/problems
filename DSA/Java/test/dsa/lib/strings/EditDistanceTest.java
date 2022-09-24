package dsa.lib.strings;

import org.junit.Test;

import static org.junit.Assert.*;

public class EditDistanceTest {
    @Test
    public void emptyString() {
        assertEquals(0, getMinDistance("", ""));
        assertEquals(1, getMinDistance("a", ""));
        assertEquals(1, getMinDistance("", "a"));
    }

    private static int getMinDistance(String w1, String w2) {
        int r1 = new EditDistance().minDistance(w1, w2);
        int r2 = new EditDistance().minDistance1(w1, w2);
        assert r1 == r2 : "Results from 2 same functions are different.";

        return r1;
    }

    @Test
    public void equalString() {
        assertEquals(0, getMinDistance("abc", "abc"));
    }

    @Test
    public void case1() {
        assertEquals(3, getMinDistance("horse", "ros"));
        assertEquals(5, getMinDistance("intention", "execution"));
    }
}
