#include <dsa/lib/algo/sort/quick_sort.hpp>
#include "sort_test.h"
namespace dsa::lib::algo::sort {
namespace {

class QuickSortTest : public SortTest {
 protected:
    static void sort(int *ary, int n) {
        QuickSort qs;
        qs.sort(ary, n);
    }
};
TEST_F(QuickSortTest, case1) {
    int ary[] = {1};
    int expected[] = {1};
    sort(ary, aryLength(ary));
    EXPECT_ARRAY_EQ(expected, aryLength(expected), ary, aryLength(ary));
}

}
}
