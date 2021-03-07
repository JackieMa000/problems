package dsa.lib.algo.sort;

public class InsertionSort {
    public static void sort(int[] ary) {
        for (int i = 1; i < ary.length; ++i) {
            int b = ary[i];
            final int pos = insertPosOf(ary, 0, i);
            ary[pos] = b;
        }
    }

    /**
     * Find the insert position for an element in the sorted array
     *
     * @param ary
     * @param st  The start of the sorted array, inclusive.
     * @param idx The index of element to be inserted. The element should be next to the end of the sorted array.
     * @return The index of insert position
     */
    private static int insertPosOf(int[] ary, int st, int idx) {
        int b = ary[idx];
        for (--idx; idx >= st; --idx) {
            final int a = ary[idx];
            if (a > b) ary[idx + 1] = a;
            else break;
        }
        return idx + 1;
    }
}
