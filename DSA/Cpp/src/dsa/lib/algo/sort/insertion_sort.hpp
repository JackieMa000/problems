#ifndef DSA_SRC_DSA_LIB_ALGO_SORT_INSERTION_SORT_HPP_
#define DSA_SRC_DSA_LIB_ALGO_SORT_INSERTION_SORT_HPP_
namespace dsa::lib::algo::sort {

class InsertionSort {
 public:
    static void sort(int *ary, size_t n) {
        for (int i = 0; i < n; ++i) {
            int b = ary[i];
            int pos = insertPosOf(ary, i);
            ary[pos] = b;
        }
    }
    /**
     * Find the insert position of element in the sorted range of array.
     *
     * @param ary The whole array
     * @param i The index of element to be inserted
     * @return The index of insert position
     */
    static int insertPosOf(int *ary, int i) {
        int b = ary[i];
        for (--i; i >= 0; --i) {
            int a = ary[i];
            if (a > b) { ary[i + 1] = a; }
            else { break; }
        }
        return i + 1;
    }
};

}
#endif //DSA_SRC_DSA_LIB_ALGO_SORT_INSERTION_SORT_HPP_
