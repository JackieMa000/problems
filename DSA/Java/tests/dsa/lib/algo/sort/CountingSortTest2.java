package dsa.lib.algo.sort;

import org.junit.Test;

import static org.junit.Assert.assertArrayEquals;

public class CountingSortTest2 {
    private static void countingSort(String[] ary, int place) {
        new CountingSort2().sort(ary, place);
    }

    @Test
    public void case1() {
        String[] ary = {"abc"};
        countingSort(ary, 1);
        final String[] expected = {"abc"};
        assertArrayEquals(expected, ary);
    }

    @Test
    public void sortBy1st1() {
        String[] ary = {"ad", "bc"};
        final String[] expected = {"ad", "bc"};
        countingSort(ary, 0);
        assertArrayEquals(expected, ary);
    }

    @Test
    public void sortBy1st2() {
        String[] ary = {"bc", "ad"};
        final String[] expected = {"ad", "bc"};
        countingSort(ary, 0);
        assertArrayEquals(expected, ary);
    }

    @Test
    public void sortBy1st3() {
        String[] ary = {"ab", "a"};
        final String[] expected = {"ab", "a"};
        countingSort(ary, 0);
        assertArrayEquals(expected, ary);
    }

    @Test
    public void sortBy1st4() {
        String[] ary = {"a", "ab"};
        final String[] expected = {"a", "ab"};
        countingSort(ary, 0);
        assertArrayEquals(expected, ary);
    }

    @Test
    public void sortBy1st5() {
        String[] ary = {"ab", "b"};
        final String[] expected = {"ab", "b"};
        countingSort(ary, 0);
        assertArrayEquals(expected, ary);
    }

    @Test
    public void sortBy1st6() {
        String[] ary = {"b", "ab"};
        final String[] expected = {"ab", "b"};
        countingSort(ary, 0);
        assertArrayEquals(expected, ary);
    }

    @Test
    public void sortBy1st7() {
        String[] ary = {"cd", "ae"};
        final String[] expected = {"ae", "cd"};
        countingSort(ary, 0);
        assertArrayEquals(expected, ary);
    }

    @Test
    public void sortBy1st8() {
        String[] ary = {"bce", "bc", "a", "abc"};
        final String[] expected = {"a", "abc", "bce", "bc"};
        countingSort(ary, 0);
        assertArrayEquals(expected, ary);
    }

    @Test
    public void sortBy1st9() {
        String[] ary = {"hke", "iba", "hzg", "ikf", "hac"};
        countingSort(ary, 0);
        final String[] expected = {"hke", "hzg", "hac", "iba", "ikf"};
        assertArrayEquals(expected, ary);
    }

    @Test
    public void sortByMiddle() {
        String[] ary = {"hke", "iba", "hzg", "ikf", "hac"};
        countingSort(ary, 1);
        final String[] expected = {"hac", "iba", "hke", "ikf", "hzg"};
        assertArrayEquals(expected, ary);
    }

    @Test
    public void sortByLast1() {
        String[] ary = {"ae", "bc"};
        final String[] expected = {"bc", "ae"};
        countingSort(ary, 1);
        assertArrayEquals(expected, ary);
    }

    @Test
    public void sortByLast2() {
        String[] ary = {"ab", "cd"};
        final String[] expected = {"ab", "cd"};
        countingSort(ary, 1);
        assertArrayEquals(expected, ary);
    }

    @Test
    public void sortByLast3() {
        String[] ary = {"ab", "a"};
        final String[] expected = {"a", "ab"};
        countingSort(ary, 1);
        assertArrayEquals(expected, ary);
    }

    @Test
    public void sortByLast4() {
        String[] ary = {"ab", "b"};
        final String[] expected = {"ab", "b"};
        countingSort(ary, 1);
        assertArrayEquals(expected, ary);
    }

    @Test
    public void sortByLast5() {
        String[] ary = {"bce", "bc", "a", "abc"};
        final String[] expected = {"a", "bc", "abc", "bce"};
        countingSort(ary, 2);
        assertArrayEquals(expected, ary);
    }

    @Test
    public void sortByLast6() {
        String[] ary = {"hke", "iba", "hzg", "ikf", "hac"};
        final String[] expected = {"iba", "hac", "hke", "ikf", "hzg"};
        countingSort(ary, 2);
        assertArrayEquals(expected, ary);
    }

}