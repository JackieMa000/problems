package dsa.lib.algo.sort;

public class InsertionSort {
    public static void sort(int[] ary) {
        for (int i = 1; i < ary.length; ++i) {
            int b = ary[i];
            final int pos = insertPosOf(ary, i);
            ary[pos] = b;
        }
    }

    /**
     * Find the insert position for the element in the sorted range of the array
     *
     * @param ary The whole array
     * @param i   The index of element to be inserted
     * @return The index of insert position
     */
    private static int insertPosOf(int[] ary, int i) {
        int b = ary[i];
        for (--i; i >= 0; --i) {
            final int a = ary[i];
            if (a > b) ary[i + 1] = a;
            else break;
        }
        return i + 1;
    }
}
