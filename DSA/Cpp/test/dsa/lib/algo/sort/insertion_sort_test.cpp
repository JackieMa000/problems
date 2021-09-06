#include <dsa/lib/algo/sort/insertion_sort.hpp>
#include "sort_test.h"

namespace dsa::lib::algo::sort {
namespace {

class InsertionSortTest : public SortTest {};
TEST_F(InsertionSortTest, oneNum) {
    int ary[] = {1};
    int expected[] = {1};
    InsertionSort::sort(ary, arylen(ary));
    EXPECT_ARRAY_EQ(expected, arylen(expected), ary, arylen(ary));
}
TEST_F(InsertionSortTest, case1) {
    int ary[] = {4, 5, 6, 3, 2, 1};
    int expected[] = {1, 2, 3, 4, 5, 6};
    InsertionSort::sort(ary, arylen(ary));
    EXPECT_ARRAY_EQ(expected, arylen(expected), ary, arylen(ary));
}

}
};