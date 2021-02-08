#ifndef DSA_SRC_DSA_LIB_ALGO_SORT_QUICK_SORT_HPP_
#define DSA_SRC_DSA_LIB_ALGO_SORT_QUICK_SORT_HPP_
#include <dsa/lib/utils.hpp>
namespace dsa::lib::algo::sort {

class QuickSort {
 public:
    void sort(int *ary, int n) { quickSort(ary, 0, n - 1); }

    /**
     * QuickSort the array recursively, until the array has only one element.
     *
     * @param ary
     * @param low The low endpoint of the array, inclusive.
     * @param high The high endpoint of the array, inclusive.
     */
    void quickSort(int *ary, int low, int high) {
        if (low >= high) { return; }

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
    int partition(int *ary, int low, int high) {
        int i = low;
        int p = getPivotPos(ary, low, high);
        for (int j = low; j < high; ++j) {
            if (ary[j] < ary[p]) { utils::arraySwap(ary, i++, j); }
        }

        utils::arraySwap(ary, i, p);
        return i;
    }

    static int getPivotPos(int *ary, int low, int high) {
        return high;
    }
};

}
#endif //DSA_SRC_DSA_LIB_ALGO_SORT_QUICK_SORT_HPP_
