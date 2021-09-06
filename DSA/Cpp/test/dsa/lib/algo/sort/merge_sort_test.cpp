#include <dsa/lib/algo/sort/merge_sort.hpp>
#include "sort_test.h"
namespace dsa::lib::algo::sort {
namespace {

class MergeSortTest : public SortTest {
 public:
    static void sort(int *ary, length_t n) {
        MergeSort ms;
        ms.sort(ary, n);
    }
};
TEST_F(MergeSortTest, case1) {
    int ary[] = {1};
    int expected[] = {1};
    sort(ary, arylen(ary));
    EXPECT_ARRAY_EQ(expected, arylen(expected), ary, arylen(ary));
}
TEST_F(MergeSortTest, case2) {
    int ary[] = {4, 5, 6, 3, 2, 1};
    int expected[] = {1, 2, 3, 4, 5, 6};
    sort(ary, arylen(ary));
    EXPECT_ARRAY_EQ(expected, arylen(expected), ary, arylen(ary));
}
TEST_F(MergeSortTest, case3) {
    int ary[] = {12, 11, 13, 5, 6, 7};
    int expected[] = {5, 6, 7, 11, 12, 13};
    sort(ary, arylen(ary));
    EXPECT_ARRAY_EQ(expected, arylen(expected), ary, arylen(ary));
}

}
}
