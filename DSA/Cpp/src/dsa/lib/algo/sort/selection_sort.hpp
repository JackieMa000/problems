#ifndef DSA_SRC_DSA_LIB_ALGO_SORT_SELECTION_SORT_HPP_
#define DSA_SRC_DSA_LIB_ALGO_SORT_SELECTION_SORT_HPP_
#include <dsa/lib/utils/algorithm.hpp>

namespace dsa::lib::algo::sort {

class SelectionSort {
 public:
    static void sort(int *ary, int n) {
        for (int i = 0; i < n - 1; ++i) {
            int minPos = arrayMinPos(ary, i, n);
            dsa::swap(ary, i, minPos);
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
    static int arrayMinPos(const int *ary, int st, size_t end) {
        int m = st;
        for (int i = st + 1; i < end; ++i) {
            if (ary[i] < ary[m]) { m = i; }
        }
        return m;
    }
};

}

#endif //DSA_SRC_DSA_LIB_ALGO_SORT_SELECTION_SORT_HPP_
