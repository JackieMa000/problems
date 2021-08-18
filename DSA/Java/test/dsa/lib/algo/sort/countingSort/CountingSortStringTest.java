package dsa.lib.algo.sort.countingSort;

import org.junit.Test;

import static org.junit.Assert.assertArrayEquals;

public class CountingSortStringTest {
    private void assertCountingSort(String[] expected, String[] ss, int index) {
        countingSort(ss, index);
        assertArrayEquals(expected, ss);
    }

    private static void countingSort(String[] ary, int index) {
        new CountingSortString(ary, index).sort();
    }

    @Test
    public void emptyArray() {
        assertCountingSort(new String[]{}, new String[]{}, 0);
    }

    @Test
    public void oneElement() {
        assertCountingSort(new String[]{"abc"}, new String[]{"abc"}, 0);
        assertCountingSort(new String[]{"abc"}, new String[]{"abc"}, 1);
        assertCountingSort(new String[]{"abc"}, new String[]{"abc"}, 2);
    }

    @Test
    public void sortOnIndex0() {
        assertCountingSort(new String[]{"ad", "bc"}, new String[]{"ad", "bc"}, 0);
        assertCountingSort(new String[]{"ad", "bc"}, new String[]{"bc", "ad"}, 0);
        assertCountingSort(new String[]{"ab", "a"}, new String[]{"ab", "a"}, 0);
        assertCountingSort(new String[]{"a", "ab"}, new String[]{"a", "ab"}, 0);
        assertCountingSort(new String[]{"ab", "b"}, new String[]{"ab", "b"}, 0);
        assertCountingSort(new String[]{"ab", "b"}, new String[]{"b", "ab"}, 0);
        assertCountingSort(new String[]{"ae", "cd"}, new String[]{"cd", "ae"}, 0);
        assertCountingSort(new String[]{"a", "abc", "bce", "bc"}, new String[]{"bce", "bc", "a", "abc"}, 0);
        assertCountingSort(new String[]{"hke", "hzg", "hac", "iba", "ikf"}, new String[]{"hke", "iba", "hzg", "ikf", "hac"}, 0
        );
    }

    @Test
    public void sortOnIndex1() {
        assertCountingSort(new String[]{"hac", "iba", "hke", "ikf", "hzg"}, new String[]{"hke", "iba", "hzg", "ikf", "hac"}, 1
        );
        assertCountingSort(new String[]{"bc", "ae"}, new String[]{"ae", "bc"}, 1);
        assertCountingSort(new String[]{"ab", "cd"}, new String[]{"ab", "cd"}, 1);
        assertCountingSort(new String[]{"a", "ab"}, new String[]{"ab", "a"}, 1);
        assertCountingSort(new String[]{"ab", "b"}, new String[]{"ab", "b"}, 1);
    }

    @Test
    public void sortOnIndex2() {
        assertCountingSort(new String[]{"a", "bc", "abc", "bce"}, new String[]{"bce", "bc", "a", "abc"}, 2);
        assertCountingSort(new String[]{"iba", "hac", "hke", "ikf", "hzg"}, new String[]{"hke", "iba", "hzg", "ikf", "hac"}, 2
        );
    }
}