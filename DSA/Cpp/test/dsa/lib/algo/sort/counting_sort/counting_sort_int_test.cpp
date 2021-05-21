#include <dsa/lib/algo/sort/counting_sort/counting_sort_int.hpp>
#include "dsa/lib/algo/sort/sort_test.h"

namespace dsa::lib::algo::sort {
namespace {

class CountingSortIntTest : public SortTest {
 protected:
    static void assertCountingSort(std::vector<int> &&nums, std::vector<int> &&expected) {
        countingSort(nums);
        EXPECT_EQ(expected, nums);
    }

    static void countingSort(std::vector<int> &nums) {
        CountingSortInt(nums).sort();
    }

    static void assertMinMax(std::vector<int> &&nums, int min, int max) {
        CountingSortInt cs(nums);
        cs.initFields();

        EXPECT_EQ(min, cs.min);
        EXPECT_EQ(max, cs.max);
    }

    static void assertCountsSize(std::vector<int> &&nums, size_t size) {
        CountingSortInt cs(nums);
        cs.initFields();

        EXPECT_EQ(size, cs.counts->size());
    }

    static void assertCountsIndexOf(std::vector<int> &&nums, int num, int index) {
        CountingSortInt cs(nums);
        cs.initMinMax();
        EXPECT_EQ(index, cs.countsIndexOf(num));
    }

    static void assertStoreCounts(std::vector<int> &&nums, std::vector<int> &&expected) {
        CountingSortInt cs(nums);
        cs.initFields();
        cs.storeCounts();

        EXPECT_EQ(expected, (*cs.counts));
    }

    static void assertAccCounts(std::vector<int> &&nums, std::vector<int> &&expected) {
        CountingSortInt cs(nums);
        cs.initFields();
        cs.storeCounts();
        cs.accumulateCounts();

        EXPECT_EQ(expected, (*cs.counts));
    }
};
TEST_F(CountingSortIntTest, emptyArray) {
    assertCountingSort({}, {});
}
TEST_F(CountingSortIntTest, oneElement) {
    assertCountingSort({1}, {1});
}
TEST_F(CountingSortIntTest, sorts) {
    assertCountingSort({1, 1, 0}, {0, 1, 1});
    assertCountingSort({3, 2, 1}, {1, 2, 3});
    assertCountingSort({4, 5, 6, 3, 2, 1}, {1, 2, 3, 4, 5, 6});
    assertCountingSort({12, 11, 13, 5, 6, 7}, {5, 6, 7, 11, 12, 13});
    assertCountingSort({2, 5, 3, 0, 2, 3, 0, 3}, {0, 0, 2, 2, 3, 3, 3, 5});

    assertCountingSort({-1, -2}, {-2, -1});
    assertCountingSort({-2, -4, -5}, {-5, -4, -2});
    assertCountingSort({0, -1, -2}, {-2, -1, 0});
    assertCountingSort({-2, -7, 3}, {-7, -2, 3});
}
TEST_F(CountingSortIntTest, minMax) {
    assertMinMax({1}, 1, 1);
    assertMinMax({1, 1}, 1, 1);
    assertMinMax({1, 2, 3}, 1, 3);
    assertMinMax({8, 2, 9}, 2, 9);
}
TEST_F(CountingSortIntTest, countsSize) {
    assertCountsSize({0, 0}, 1);
    assertCountsSize({1, 1}, 1);

    assertCountsSize({0, 1, 1}, 2);
    assertCountsSize({2, 4, 8}, 7);
    assertCountsSize({1, 2, 3}, 3);
    assertCountsSize({1, 4, 1}, 4);
    assertCountsSize({3, 4, 2}, 3);
    assertCountsSize({8, 2, 9}, 8);
}
TEST_F(CountingSortIntTest, storeCounts) {
    assertStoreCounts({1, 2, 3}, {1, 1, 1});
    assertStoreCounts({1, 4, 1}, {2, 0, 0, 1});
    assertStoreCounts({3, 4, 2}, {1, 1, 1});
}
TEST_F(CountingSortIntTest, accCounts) {
    assertAccCounts({1, 2, 3}, {1, 2, 3});
    assertAccCounts({1, 4, 1}, {2, 2, 2, 3});
    assertAccCounts({3, 4, 2}, {1, 2, 3});
}
TEST_F(CountingSortIntTest, countsIndexOf) {
    assertCountsIndexOf({1, 1}, 1, 0);
    assertCountsIndexOf({1, 2, 3}, 2, 1);
    assertCountsIndexOf({8, 2, 9}, 9, 7);
}

}
}
