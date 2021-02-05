package dsa.lib.algo.sort;

import dsa.lib.Utils;

public class MergeSort {
    public void sort(int[] ary, int n) {
        split(ary, 0, n - 1);
    }

    /**
     * Split the array into 2 sub-arrays, then merge the 2 sub-arrays into a sorted array.
     *
     * @param ary The array to be split.
     * @param st  The start position of the array to be split, inclusive.
     * @param end The end position of the array to be split, inclusive.
     */
    private void split(int[] ary, int st, int end) {
        if (st >= end) return;

        int mid = st + (end - st) / 2;
        split(ary, st, mid);
        split(ary, mid + 1, end);
        merge(ary, st, mid, end);

    }

    /**
     * Merge 2 sub-arrays into a sorted array.
     *
     * @param ary The given array contains 2 sub-arrays.
     * @param st  The start position of the 1st sub-array, inclusive.
     * @param m   The end position of the 1st sub-array, inclusive.
     *            Also it is the divided position of the 2 sub-arrays, the next position should be the start of the 2nd sub-array.
     * @param end The end position of the 2nd sub-array, inclusive.
     */
    private void merge(int[] ary, int st, int m, int end) {
        final int n = end - st + 1;
        int[] result = new int[n];

        for (int i = st, j = m + 1, k = 0; k < n; ++k) {
            if (i <= m && j <= end) {
                if (ary[i] <= ary[j]) result[k] = ary[i++];
                else result[k] = ary[j++];
            } else if (i <= m) {
                result[k] = ary[i++];
            } else result[k] = ary[j++];
        }

        Utils.arraycopy(result, 0, ary, st, end - st + 1);
    }
}
