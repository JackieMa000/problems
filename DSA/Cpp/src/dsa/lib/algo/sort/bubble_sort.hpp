#ifndef DSA_SRC_DSA_LIB_ALGO_SORT_BUBBLE_SORT_HPP_
#define DSA_SRC_DSA_LIB_ALGO_SORT_BUBBLE_SORT_HPP_

namespace dsa::lib::algo::sort {

class BubbleSort {
 public:
    static void sort(int *ary, size_t n) {
        for (int i = 0; i < n; ++i) {
            bool swapped = false;
            for (int j = 0; j < n - 1 - i; ++j) {
                if (ary[j] > ary[j + 1]) {
                    arraySwap(ary, j, j + 1);
                    swapped = true;
                }
            }
            if (!swapped) { break; }
        }
    }
    static void arraySwap(int *ary, int i, int j) {
        int tmp = ary[i];
        ary[i] = ary[j];
        ary[j] = tmp;
    }
};

}

#endif //DSA_SRC_DSA_LIB_ALGO_SORT_BUBBLE_SORT_HPP_
