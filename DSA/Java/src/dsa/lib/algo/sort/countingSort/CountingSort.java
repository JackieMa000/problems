package dsa.lib.algo.sort.countingSort;

import dsa.lib.utils.Arrays;

public class CountingSort {
    public CountingSort(int[] ary) {
        Integer[] newAry = Arrays.integerValueOf(ary);
        new CountingSortInteger(newAry).sort();
        Arrays.copy(newAry, 0, ary, 0, ary.length);
    }

    public CountingSort(Integer[] ary) {
        new CountingSortInteger(ary).sort();
    }

    public CountingSort(int[] ary, int place) {
        Integer[] newAry = Arrays.integerValueOf(ary);
        new CountingSortIntegerPlace(newAry, place).sort();
        Arrays.copy(newAry, 0, ary, 0, ary.length);
    }

    public CountingSort(Integer[] ary, int place) {
        new CountingSortIntegerPlace(ary, place).sort();
    }

    public CountingSort(String[] ary, int index) {
        new CountingSortString(ary, index).sort();
    }
}
