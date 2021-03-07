#include <dsa/lib/algo/sort/quick_sort.hpp>
#include "sort_test.h"
namespace dsa::lib::algo::sort {
namespace {

class QuickSortTest : public SortTest {
 protected:
    static void quickSort(int *ary, int n) { QuickSort().sort(ary, n); }
};
TEST_F(QuickSortTest, case1) {
    int ary[] = {1};
    int expected[] = {1};
    quickSort(ary, aryLength(ary));
    EXPECT_ARRAY_EQ(expected, aryLength(expected), ary, aryLength(ary));
}
TEST_F(QuickSortTest, case2) {
    int ary[] = {4, 5, 6, 3, 2, 1};
    int expected[] = {1, 2, 3, 4, 5, 6};
    quickSort(ary, aryLength(ary));
    EXPECT_ARRAY_EQ(expected, aryLength(expected), ary, aryLength(ary));
}
TEST_F(QuickSortTest, case3) {
    int ary[] = {12, 11, 13, 5, 6, 7};
    int expected[] = {5, 6, 7, 11, 12, 13};
    quickSort(ary, aryLength(ary));
    EXPECT_ARRAY_EQ(expected, aryLength(expected), ary, aryLength(ary));
}

}
}
