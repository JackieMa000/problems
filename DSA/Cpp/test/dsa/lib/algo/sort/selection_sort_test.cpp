#include <dsa/lib/algo/sort/selection_sort.hpp>
#include "sort_test.h"

namespace dsa::lib::algo::sort {
namespace {

class SelectionSortTest : public SortTest {};
TEST_F(SelectionSortTest, oneNum) {
    int ary[] = {1};
    int expected[] = {1};
    SelectionSort::sort(ary, arylen(ary));
    EXPECT_ARRAY_EQ(expected, arylen(expected), ary, arylen(ary));
}
TEST_F(SelectionSortTest, case1) {
    int ary[] = {4, 5, 6, 3, 2, 1};
    int expected[] = {1, 2, 3, 4, 5, 6};
    SelectionSort::sort(ary, arylen(ary));
    EXPECT_ARRAY_EQ(expected, arylen(expected), ary, arylen(ary));
}

}
};