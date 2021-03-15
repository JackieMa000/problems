#include <dsa/lib/algo/sort/counting_sort.hpp>
#include "sort_test.h"

namespace dsa::lib::algo::sort {
namespace {

class CountingSortTest : public SortTest {
 protected:
    static void assertCountingSort(std::vector<int> &&expected, std::vector<int> &&actual) {
        countingSort(actual);
        EXPECT_EQ(expected, actual);
    }

    static void countingSort(std::vector<int> &nums) {
        CountingSort(nums).sort();
    }

    static void assertMinMax(std::vector<int> &&nums, int min, int max) {
        CountingSort cs(nums);
        cs.sort();
        EXPECT_EQ(min, cs.min);
        EXPECT_EQ(max, cs.max);
    }

    static void assertCountsSize(std::vector<int> &&nums, size_t size) {
        CountingSort cs(nums);
        cs.sort();
        EXPECT_EQ(size, cs.counts->size());
    }

    static void assertCountsIndexOf(std::vector<int> &&nums, int num, int index) {
        CountingSort cs(nums);
        cs.sort();
        EXPECT_EQ(index, cs.countsIndexOf(num));
    }
};
TEST_F(CountingSortTest, minMax) {
    assertMinMax({1, 1}, 1, 1);
    assertMinMax({1, 2, 3}, 1, 3);
    assertMinMax({8, 2, 9}, 2, 9);
}
TEST_F(CountingSortTest, countsSize) {
    assertCountsSize({1, 1}, 1);
    assertCountsSize({1, 2, 3}, 3);
    assertCountsSize({8, 2, 9}, 8);
}
TEST_F(CountingSortTest, countsIndexOf) {
    assertCountsIndexOf({1, 1}, 1, 0);
    assertCountsIndexOf({1, 2, 3}, 2, 1);
    assertCountsIndexOf({8, 2, 9}, 9, 7);
}
TEST_F(CountingSortTest, emptyArray) {
    assertCountingSort({}, {});
}
TEST_F(CountingSortTest, oneElement) {
    assertCountingSort({1}, {1});
}
TEST_F(CountingSortTest, sorts) {
    assertCountingSort({0, 1, 1}, {1, 1, 0});
    assertCountingSort({1, 2, 3}, {3, 2, 1});
    assertCountingSort({1, 2, 3, 4, 5, 6}, {4, 5, 6, 3, 2, 1});
    assertCountingSort({5, 6, 7, 11, 12, 13}, {12, 11, 13, 5, 6, 7});
    assertCountingSort({0, 0, 2, 2, 3, 3, 3, 5}, {2, 5, 3, 0, 2, 3, 0, 3});
}

}
}
