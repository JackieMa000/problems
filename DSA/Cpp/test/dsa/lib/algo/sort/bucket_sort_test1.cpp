#include <dsa/lib/algo/sort/bucket_sort.hpp>
#include <vector>
#include "sort_test.h"
namespace dsa::lib::algo::sort {
namespace {

class BucketSortTest : public SortTest {
 protected:
    static void bucketSort(std::__1::vector<int> &ary) {
        BucketSort bs(ary);
        bs.quickSort();
    }
};
TEST_F(BucketSortTest, case1) {
    int ary[] = {1};
    int expected[] = {1};
    bucketSort(ary, aryLength(ary));
    EXPECT_ARRAY_EQ(expected, aryLength(expected), ary, aryLength(ary));
}
TEST_F(BucketSortTest, case2) {
    int ary[] = {4, 5, 6, 3, 2, 1};
    int expected[] = {1, 2, 3, 4, 5, 6};
    bucketSort(ary, aryLength(ary));
    EXPECT_ARRAY_EQ(expected, aryLength(expected), ary, aryLength(ary));
}

}
}