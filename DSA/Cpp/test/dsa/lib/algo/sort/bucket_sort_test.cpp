#include <dsa/lib/algo/sort/bucket_sort1.hpp>
#include "sort_test.h"
namespace dsa::lib::algo::sort {
namespace {

class BucketSortTest : public SortTest {
 protected:
    static void bucketSort(std::vector<int> &nums) { BucketSort(nums).sort(); }

    static void assertMinMax(std::vector<int> &&nums, int min, int max) {
        BucketSort bs(nums);
        bs.sort();
        EXPECT_EQ(min, bs.min);
        EXPECT_EQ(max, bs.max);
    };
};
TEST_F(BucketSortTest, minMax) {
    assertMinMax({1, 1}, 1, 1);
    assertMinMax({2, 1}, 1, 2);
    assertMinMax({1, 2, 3}, 1, 3);
    assertMinMax({1, 1, 1}, 1, 1);
    assertMinMax({4, 2, 8}, 2, 8);
}
TEST_F(BucketSortTest, emptyNums) {
    std::vector<int> nums = {};
    const std::vector<int> expected = {};
    bucketSort(nums);
    EXPECT_EQ(expected, nums);
    EXPECT_EQ(std::vector<int>({}), nums);
}
TEST_F(BucketSortTest, case1) {
    std::vector<int> nums = {1};
    const std::vector<int> expected = {1};
    bucketSort(nums);
    EXPECT_EQ(expected, nums);
    EXPECT_EQ(std::vector<int>({1}), nums);
}
//TEST_F(BucketSortTest, case2) {
//    std::vector<int> nums = {4, 5, 6, 3, 2, 1};
//    const std::vector<int> expected = {1, 2, 3, 4, 5, 6};
//    bucketSort(nums);
//    EXPECT_EQ(expected, nums);
//}
//TEST_F(BucketSortTest, case3) {
//    std::vector<int> nums = {12, 11, 13, 5, 6, 7};
//    const std::vector<int> expected = {5, 6, 7, 11, 12, 13};
//    bucketSort(nums);
//    EXPECT_EQ(expected, nums);
//}

}
}