#include <dsa/lib/algo/sort/counting_sort/counting_sort_int.hpp>
#include "dsa/lib/algo/sort/sort_test.h"

namespace dsa::lib::algo::sort {
namespace {

class CountingSortIntPlaceTest : public SortTest {
 protected:
    static void assertCountingSortPlace(std::vector<int> &&nums, int place, std::vector<int> &&expected) {
        countingSort(nums, place);
        EXPECT_EQ(expected, nums);
    }

    static void countingSort(std::vector<int> &nums, int place) {
        CountingSortIntPlace(nums, place).sort();
    }
};
TEST_F(CountingSortIntPlaceTest, emptyArray) {
    assertCountingSortPlace({}, 1, {});
    assertCountingSortPlace({}, 10, {});
}
TEST_F(CountingSortIntPlaceTest, oneElement) {
    assertCountingSortPlace({1}, 1, {1});
    assertCountingSortPlace({1}, 10, {1});
}
TEST_F(CountingSortIntPlaceTest, placeExceeds_noSort) {
    assertCountingSortPlace({2, 1, 3}, 10, {2, 1, 3});
    assertCountingSortPlace({2, 11, 31}, 10, {2, 11, 31});
    assertCountingSortPlace({22, 11, 31}, 100, {22, 11, 31});
}
TEST_F(CountingSortIntPlaceTest, unitPlace) {
    assertCountingSortPlace({2, 1, 3}, 1, {1, 2, 3});

    assertCountingSortPlace({22, 11, 31}, 1, {11, 31, 22});
    assertCountingSortPlace({121, 432, 564, 23, 1, 45, 788}, 1, {121, 1, 432, 23, 564, 45, 788});
}
TEST_F(CountingSortIntPlaceTest, tensPlace) {
    assertCountingSortPlace({22, 11, 31}, 10, {11, 22, 31});
    assertCountingSortPlace({121, 1, 432, 23, 564, 45, 788}, 10, {1, 121, 23, 432, 45, 564, 788});

}
TEST_F(CountingSortIntPlaceTest, hundredsPlace) {
    assertCountingSortPlace({222, 111, 311}, 100, {111, 222, 311});
    assertCountingSortPlace({1, 121, 23, 432, 45, 564, 788}, 100, {1, 23, 45, 121, 432, 564, 788});
}

}
}
