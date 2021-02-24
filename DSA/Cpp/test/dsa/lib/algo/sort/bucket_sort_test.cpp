#include <dsa/lib/algo/sort/bucket_sort.hpp>
#include "sort_test.h"
namespace dsa::lib::algo::sort {
namespace {

class BucketSortTest : public SortTest {
 protected:
    static void bucketSort(std::vector<int> &nums) {
        BucketSort bs(nums);
        bs.sort();
    }
};
TEST_F(BucketSortTest, emptyNums) {
    std::vector<int> nums = {};
    std::vector<int> expected = {};
    bucketSort(nums);
    EXPECT_EQ(expected, nums);
}
TEST_F(BucketSortTest, case1) {
    std::vector<int> nums = {1};
    std::vector<int> expected = {1};
    bucketSort(nums);
    EXPECT_EQ(expected, nums);
}
TEST_F(BucketSortTest, case2) {
    std::vector<int> nums = {4, 5, 6, 3, 2, 1};
    std::vector<int> expected = {1, 2, 3, 4, 5, 6};
    bucketSort(nums);
    EXPECT_EQ(expected, nums);
}
TEST_F(BucketSortTest, case3) {
    std::vector<int> nums = {12, 11, 13, 5, 6, 7};
    std::vector<int> expected = {5, 6, 7, 11, 12, 13};
    bucketSort(nums);
    EXPECT_EQ(expected, nums);
}

}
}