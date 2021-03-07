package dsa.lib.algo.sort;

public class SelectionSort {
    public static void sort(int[] ary) {
        int n = ary.length;
        for (int i = 0; i < n - 1; i++) {
            int minPos = arrayMinPos(ary, i, n);
            arraySwap(ary, i, minPos);
        }
    }

    /**
     * Find the index of the minimum element from the range of array
     *
     * @param ary The whole array
     * @param st  The start position of the range, inclusive.
     * @param end The end position of the range, exclusive.
     * @return The index of the minimum element
     */
    private static int arrayMinPos(int[] ary, int st, int end) {
        int m = st;
        for (int i = st + 1; i < end; ++i) {
            if (ary[i] < ary[m]) m = i;
        }
        return m;
    }

    private static void arraySwap(int[] ary, int i, int j) {
        int tmp = ary[i];
        ary[i] = ary[j];
        ary[j] = tmp;
    }
}
