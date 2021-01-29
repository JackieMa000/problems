#ifndef DSA_SRC_DSA_LIB_ALGO_SORT_BUBBLE_SORT_HPP_
#define DSA_SRC_DSA_LIB_ALGO_SORT_BUBBLE_SORT_HPP_
namespace dsa::lib::algo::sort {

class BubbleSort {
 public:
    static void sort(int *ary, size_t n) {
        for (int i = 0; i < n; ++i) {
            bool swapped = false;
            compareSwap(ary, 0, n - i, swapped);
            if (!swapped) { break; }
        }
    }
    /**
     * Compare each two adjacent elements, swap them if 1st one is bigger than the 2nd.
     *
     * @param ary The Array.
     * @param st  The start position, inclusive.
     * @param end The end position, exclusive.
     */
    static void compareSwap(int *ary, int st, size_t end, bool &swapped) {
        for (int i = st; i < end - 1; ++i) {
            if (ary[i] > ary[i + 1]) {
                arraySwap(ary, i, i + 1);
                swapped = true;
            }
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
