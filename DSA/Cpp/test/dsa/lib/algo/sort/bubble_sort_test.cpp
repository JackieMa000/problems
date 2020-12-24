#include <dsa/lib/algo/sort/bubble_sort.hpp>
#include "sort_test.h"
namespace dsa::lib::algo::sort {
namespace {

class BubbleSortTest : public SortTest {};
TEST_F(BubbleSortTest, oneNum) {
    int ary[] = {1};
    int expected[] = {1};
    BubbleSort::sort(ary, aryLength(ary));
    EXPECT_ARRAY_EQ(expected, aryLength(expected), ary, aryLength(ary));
}
TEST_F(BubbleSortTest, case1) {
    int ary[] = {4, 5, 6, 3, 2, 1};
    int expected[] = {1, 2, 3, 4, 5, 6};
    BubbleSort::sort(ary, aryLength(ary));
    EXPECT_ARRAY_EQ(expected, aryLength(expected), ary, aryLength(ary));
}

}
};