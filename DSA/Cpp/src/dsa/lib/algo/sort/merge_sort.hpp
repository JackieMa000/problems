#ifndef DSA_SRC_DSA_LIB_ALGO_SORT_MERGE_SORT_HPP_
#define DSA_SRC_DSA_LIB_ALGO_SORT_MERGE_SORT_HPP_
#include <dsa/lib/utils.hpp>
namespace dsa::lib::algo::sort {

class MergeSort {
 public:
    void sort(int *ary, int n) {
        split(ary, 0, n - 1);
    }
 private:
    /**
     * Split the array into 2 sub-arrays, then merge the 2 sub-arrays into a sorted array.
     *
     * @param ary
     * @param st The start position of the array to be split, inclusive.
     * @param end The end position of the array to be split, inclusive.
     */
    void split(int *ary, int st, int end) {
        if (st >= end) { return; }

        int mid = st + (end - st) / 2;
        split(ary, 0, mid);
        split(ary, mid + 1, end);
        merge(ary, st, mid, end);
    }

    /**
     * Merge 2 sub-arrays into a sorted array.
     *
     * @param ary
     * @param st The start position of the 1st sub-array, inclusive.
     * @param m The end position of the 1st sub-array, inclusive.
     * Also it is the divided position of the 2 sub-arrays, the next position should be the start of the 2nd sub-array.
     * @param end The end position of the 2nd sub-array, inclusive.
     */
    static void merge(int *ary, int st, int m, int end) {
        int n = end - st + 1;
        int result[n];

        for (int i = st, j = m + 1, k = 0; k < n; ++k) {
            if (i <= m && j <= end) {
                if (ary[i] <= ary[j]) {
                    result[k] = ary[i++];
                } else { result[k] = ary[j++]; }
            } else if (i <= m) {
                result[k] = ary[i++];
            } else {
                result[k] = ary[j++];
            }
        }

        utils::arraycopy(result, 0, ary, st, n);
    }
};

}

#endif //DSA_SRC_DSA_LIB_ALGO_SORT_MERGE_SORT_HPP_
