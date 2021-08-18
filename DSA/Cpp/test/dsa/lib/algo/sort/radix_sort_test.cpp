#include <vector>
#include <list>
#include <forward_list>

#include <dsa/testing/dsatest.h>
#include <dsa/lib/algo/sort/radix_sort.hpp>

namespace dsa::lib::algo::sort::rs {
namespace {

void expectRadixSort(std::vector<int> &&expected, std::vector<int> &&nums) {
    rs::sort(nums);
    EXPECT_EQ(expected, nums);
}
TEST(RadixSortTest, emptyArray) {
    expectRadixSort({}, {});
}
TEST(RadixSortTest, oneElement) {
    expectRadixSort({1}, {1});
}
TEST(RadixSortTest, sorts) {
    expectRadixSort({1, 23, 45, 121, 432, 564, 788}, {121, 432, 564, 23, 1, 45, 788});
}
TEST(RadixSortTest, iterator) {
    std::vector<int> nums = {121, 432, 564, 23, 1, 45, 788};
    std::vector<int> expected = {1, 23, 45, 121, 432, 564, 788};
    rs::sort(nums.begin(), nums.end());
    EXPECT_EQ(expected, nums);
}

void expectRadixSortStr(std::vector<std::string> &&expected, std::vector<std::string> &&ss) {
    rs::sort(ss);
    EXPECT_EQ(expected, ss);
}
TEST(RadixSortStrTest, emptyArray) {
    expectRadixSortStr({}, {});
}
TEST(RadixSortStrTest, oneElement) {
    expectRadixSortStr({"ab"}, {"ab"});
}
TEST(RadixSortStrTest, sorts) {
    expectRadixSortStr({"hac", "hke", "hzg", "iba", "ikf"}, {"hke", "iba", "hzg", "ikf", "hac"});
}
TEST(RadixSortStrTest, iterator) {
    std::vector<std::string> ss = {"hke", "iba", "hzg", "ikf", "hac"};
    std::vector<std::string> expected = {"hac", "hke", "hzg", "iba", "ikf"};
    rs::sortStr(ss.begin(), ss.end());
    EXPECT_EQ(expected, ss);
}

}
}
