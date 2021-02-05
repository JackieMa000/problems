package dsa.lib.algo.sort;

import dsa.lib.Utils;

public class QuickSort {
    public void sort(int[] ary, int length) {
        quickSort(ary, 0, length - 1);
    }

    private void quickSort(int[] ary, int low, int high) {
        if (low >= high) return;

        int m = partition(ary, low, high);
        quickSort(ary, low, m - 1);
        quickSort(ary, m + 1, high);
    }

    /**
     * Partition the array into 2 sub-parts, return the pivot position.
     * Left parts is smaller than the pivot element, Right parts is greater than the pivot element.
     *
     * @param ary  The array.
     * @param low  The low endpoint of the array to be partitioned, inclusive.
     * @param high The high endpoint of the array to be partitioned, inclusive.
     * @return The pivot position.
     */
    private int partition(int[] ary, int low, int high) {
        int i = low;

        int pivotPos = getPivotPos(ary, low, high);
        for (int j = low; j < high; ++j) {
            if (ary[j] < ary[pivotPos]) Utils.arrayswap(ary, i++, j);
        }
        Utils.arrayswap(ary, i, pivotPos);

        return i;
    }

    private int getPivotPos(int[] ary, int st, int end) {
        // ToDo: Can improve the algorithm here, make it more efficient.
        return end;
    }
}
