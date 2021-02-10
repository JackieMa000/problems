package dsa.lib.algo.sort;

import dsa.lib.Utils;

public class QuickSort {
    public void sort(int[] ary, int length) {
        quickSort(ary, 0, length - 1);
    }

    /**
     * QuickSort the array recursively, until the array has only one element.
     *
     * @param ary  The array.
     * @param low  The low endpoint of the array, inclusive.
     * @param high The high endpoint of the array, inclusive.
     */
    private void quickSort(int[] ary, int low, int high) {
        if (low >= high) return;

        int m = partition(ary, low, high);
        quickSort(ary, low, m - 1);
        quickSort(ary, m + 1, high);
    }

    /**
     * Partition the array into 2 sub-parts, return the pivot position.
     * All the elements on the left part are smaller than the pivot element,
     * all the elements on the right part are bigger than the pivot element.
     *
     * @param ary  The array.
     * @param low  The low endpoint of the array to be partitioned, inclusive.
     * @param high The high endpoint of the array to be partitioned, inclusive.
     * @return The pivot position.
     */
    private int partition(int[] ary, int low, int high) {
        int i = low;
        for (int j = low; j < high; ++j) {
            if (ary[j] < ary[high]) Utils.arrayswap(ary, i++, j);
        }
        Utils.arrayswap(ary, i, high);

        return i;
    }

}
