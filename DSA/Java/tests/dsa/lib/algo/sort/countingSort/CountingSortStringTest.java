package dsa.lib.algo.sort.countingSort;

import org.junit.Test;

import static org.junit.Assert.assertArrayEquals;

public class CountingSortStringTest {
    @Test
    public void emptyArray() {
        assertCountingSort(new String[]{}, 0, new String[]{});
    }

    @Test
    public void oneElement() {
        assertCountingSort(new String[]{"abc"}, 0, new String[]{"abc"});
        assertCountingSort(new String[]{"abc"}, 1, new String[]{"abc"});
        assertCountingSort(new String[]{"abc"}, 2, new String[]{"abc"});
    }

    @Test
    public void sortOnIndex0() {
        assertCountingSort(new String[]{"ad", "bc"}, 0, new String[]{"ad", "bc"});
        assertCountingSort(new String[]{"bc", "ad"}, 0, new String[]{"ad", "bc"});
        assertCountingSort(new String[]{"ab", "a"}, 0, new String[]{"ab", "a"});
        assertCountingSort(new String[]{"a", "ab"}, 0, new String[]{"a", "ab"});
        assertCountingSort(new String[]{"ab", "b"}, 0, new String[]{"ab", "b"});
        assertCountingSort(new String[]{"b", "ab"}, 0, new String[]{"ab", "b"});
        assertCountingSort(new String[]{"cd", "ae"}, 0, new String[]{"ae", "cd"});
        assertCountingSort(new String[]{"bce", "bc", "a", "abc"}, 0, new String[]{"a", "abc", "bce", "bc"});
        assertCountingSort(new String[]{"hke", "iba", "hzg", "ikf", "hac"}, 0,
                new String[]{"hke", "hzg", "hac", "iba", "ikf"});
    }

    @Test
    public void sortOnIndex1() {
        assertCountingSort(new String[]{"hke", "iba", "hzg", "ikf", "hac"}, 1,
                new String[]{"hac", "iba", "hke", "ikf", "hzg"});
        assertCountingSort(new String[]{"ae", "bc"}, 1, new String[]{"bc", "ae"});
        assertCountingSort(new String[]{"ab", "cd"}, 1, new String[]{"ab", "cd"});
        assertCountingSort(new String[]{"ab", "a"}, 1, new String[]{"a", "ab"});
        assertCountingSort(new String[]{"ab", "b"}, 1, new String[]{"ab", "b"});
    }

    @Test
    public void sortOnIndex2() {
        assertCountingSort(new String[]{"bce", "bc", "a", "abc"}, 2, new String[]{"a", "bc", "abc", "bce"});
        assertCountingSort(new String[]{"hke", "iba", "hzg", "ikf", "hac"}, 2,
                new String[]{"iba", "hac", "hke", "ikf", "hzg"});
    }

    private void assertCountingSort(String[] ary, int index, String[] expected) {
        countingSort(ary, index);
        assertArrayEquals(expected, ary);
    }

    private static void countingSort(String[] ary, int index) {
        new CountingSortString(ary, index).sort();
    }
}