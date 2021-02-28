#ifndef DSA_SRC_DSA_LIB_ALGO_SORT_INSERTION_SORT_HPP_
#define DSA_SRC_DSA_LIB_ALGO_SORT_INSERTION_SORT_HPP_

#include "dsa/dsadef.h"

namespace dsa::lib::algo::sort {

class InsertionSort {
 public:
    static void sort(int *ary, size_t n) {
        for (int i = 0; i < n; ++i) {
            int b = ary[i];
            int pos = insertPosOf(ary, 0, i);
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
    static int insertPosOf(int *ary, int st, int idx) {
        int b = ary[idx];
        for (--idx; idx >= st; --idx) {
            int a = ary[idx];
            if (a > b) { ary[idx + 1] = a; }
            else { break; }
        }
        return idx + 1;
    }
};

}
#endif //DSA_SRC_DSA_LIB_ALGO_SORT_INSERTION_SORT_HPP_
