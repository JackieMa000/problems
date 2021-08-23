package dsa.lib.algo.sort;

import dsa.lib.algo.sort.countingSort.CountingSort;
import dsa.lib.utils.Arrays;

class RadixSortString {
    static void sort(String[] ss) {
        if (ss.length < 2) return;
        String max = Arrays.maxSizeElement(ss);
        for (int i = max.length() - 1; i >= 0; --i) CountingSort.sort(ss, i);
    }
}
