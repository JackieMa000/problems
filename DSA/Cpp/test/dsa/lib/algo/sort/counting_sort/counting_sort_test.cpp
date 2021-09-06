#include <vector>
#include <list>
#include <forward_list>

#include <dsa/lib/algo/sort/counting_sort/counting_sort.hpp>
#include <dsa/testing/dsatest.h>

namespace dsa::lib::algo::sort::cs {
namespace {

void assertCountingSort_v(std::vector<int> &&nums, std::vector<int> &&expected) {
    sort(nums);
    EXPECT_EQ(expected, nums);
}
TEST(CountingSortIntTest_v, sorts) {
    assertCountingSort_v({1, 1, 0}, {0, 1, 1});
    assertCountingSort_v({3, 2, 1}, {1, 2, 3});
    assertCountingSort_v({4, 5, 6, 3, 2, 1}, {1, 2, 3, 4, 5, 6});
    assertCountingSort_v({12, 11, 13, 5, 6, 7}, {5, 6, 7, 11, 12, 13});
    assertCountingSort_v({2, 5, 3, 0, 2, 3, 0, 3}, {0, 0, 2, 2, 3, 3, 3, 5});

    assertCountingSort_v({-1, -2}, {-2, -1});
    assertCountingSort_v({-2, -4, -5}, {-5, -4, -2});
    assertCountingSort_v({0, -1, -2}, {-2, -1, 0});
    assertCountingSort_v({-2, -7, 3}, {-7, -2, 3});
}

void assertCountingSort_l(std::list<int> &&ls, std::list<int> &&expected) {
    cs::sort(ls.begin(), ls.end());
    EXPECT_EQ(expected, ls);
}
TEST(CountingSortIntTest_l, sorts) {
    assertCountingSort_l({1, 1, 0}, {0, 1, 1});
    assertCountingSort_l({3, 2, 1}, {1, 2, 3});
    assertCountingSort_l({4, 5, 6, 3, 2, 1}, {1, 2, 3, 4, 5, 6});
    assertCountingSort_l({12, 11, 13, 5, 6, 7}, {5, 6, 7, 11, 12, 13});
    assertCountingSort_l({2, 5, 3, 0, 2, 3, 0, 3}, {0, 0, 2, 2, 3, 3, 3, 5});

    assertCountingSort_l({-1, -2}, {-2, -1});
    assertCountingSort_l({-2, -4, -5}, {-5, -4, -2});
    assertCountingSort_l({0, -1, -2}, {-2, -1, 0});
    assertCountingSort_l({-2, -7, 3}, {-7, -2, 3});
}

void assertCountingSort_fl(std::forward_list<int> &&fl, std::forward_list<int> &&expected) {
    cs::sort(fl.begin(), fl.end());
    EXPECT_EQ(expected, fl);
}
TEST(CountingSortIntTest_fl, sorts) {
    assertCountingSort_fl({1, 1, 0}, {0, 1, 1});
    assertCountingSort_fl({3, 2, 1}, {1, 2, 3});
    assertCountingSort_fl({4, 5, 6, 3, 2, 1}, {1, 2, 3, 4, 5, 6});
    assertCountingSort_fl({12, 11, 13, 5, 6, 7}, {5, 6, 7, 11, 12, 13});
    assertCountingSort_fl({2, 5, 3, 0, 2, 3, 0, 3}, {0, 0, 2, 2, 3, 3, 3, 5});

    assertCountingSort_fl({-1, -2}, {-2, -1});
    assertCountingSort_fl({-2, -4, -5}, {-5, -4, -2});
    assertCountingSort_fl({0, -1, -2}, {-2, -1, 0});
    assertCountingSort_fl({-2, -7, 3}, {-7, -2, 3});
}

TEST(CountingSortIntTest_a, sorts) {
    int nums[] = {2, 5, 3, 0, 2, 3, 0, 3};
    int expected[] = {0, 0, 2, 2, 3, 3, 3, 5};
    size_t n = arylen(nums);

    cs::sort(nums, nums + n);
    EXPECT_LIST_EQ(expected, nums, nums + n);
}
TEST(CountingSortIntTest_a, sorts1) {
    int nums[] = {-2, -7, 3};
    int expected[] = {-7, -2, 3};
    size_t n = arylen(nums);

    cs::sort(nums, nums + n);
    EXPECT_LIST_EQ(expected, nums, nums + n);
}

TEST(CountingSortTest, tensPlace) {
    std::vector<int> input = {22, 11, 31};
    std::vector<int> expected = {11, 22, 31};
    cs::sort(input.begin(), input.end(), 10);
    EXPECT_EQ(expected, input);
}
TEST(CountingSortgTest, sortOnIndex0) {
    std::vector<std::string> input = {"bc", "ad"};
    std::vector<std::string> expected = {"ad", "bc"};
    cs::sortStr(input.begin(), input.end(), 0);
    EXPECT_EQ(expected, input);
}

}
}