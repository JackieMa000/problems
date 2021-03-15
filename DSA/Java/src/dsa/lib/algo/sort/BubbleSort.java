package dsa.lib.algo.sort;

import dsa.lib.utils.Arrays;

public class BubbleSort {

    private static boolean swapped;

    public static void sort(int[] ary) {
        int n = ary.length;
        for (int i = 0; i < n; i++) {
            swapped = false;
            compareSwap(ary, 0, n - i);
            if (!swapped) break;
        }
    }

    /**
     * Compare each two adjacent elements, swap them if 1st one is bigger than the 2nd.
     *
     * @param ary The Array.
     * @param st  The start position, inclusive.
     * @param end The end position, exclusive.
     */
    private static void compareSwap(int[] ary, int st, int end) {
        for (int i = st; i < end - 1; ++i) {
            if (ary[i] > ary[i + 1]) {
                Arrays.swap(ary, i, i + 1);
                swapped = true;
            }
        }
    }
}
