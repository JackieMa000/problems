package dsa.lib.algo.sort;

import dsa.lib.algo.sort.countingSort.CountingSort;
import dsa.lib.utils.Arrays;

class RadixSortString {
    void sort(String[] ary) {
        if (ary.length < 2) return;

        String max = Arrays.longest(ary);
        for (int i = max.length() - 1; i >= 0; --i) new CountingSort(ary, i);
    }
}
