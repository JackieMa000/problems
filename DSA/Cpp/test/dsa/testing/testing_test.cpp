#include <vector>
#include <list>
#include <forward_list>

#include "testing.h"

namespace dsa::testing {
namespace {

TEST(ExpectArrayEqIter, emptyElement) {
    int nums[] = {1};
    int expected[] = {2};
    DSATest::EXPECT_LIST_EQ(expected, nums, nums);
}
TEST(ExpectArrayEqIter, oneElement) {
    int nums[] = {1};
    int expected[] = {1};
    DSATest::EXPECT_LIST_EQ(expected, nums, nums + 1);
}
TEST(ExpectArrayEqIter, oneElement1) {
    int nums[] = {1};
    int expected[] = {1, 2};
    DSATest::EXPECT_LIST_EQ(expected, nums, nums + 1);
}
TEST(ExpectArrayEqIter, oneElement2) {
    int nums[] = {1, 3};
    int expected[] = {1, 2};
    DSATest::EXPECT_LIST_EQ(expected, nums, nums + 1);
}
TEST(ExpectArrayEqIter, twoElements) {
    int nums[] = {1, 2};
    int expected[] = {1, 2};
    DSATest::EXPECT_LIST_EQ(expected, nums, nums + 2);
}

TEST(ExpectLinkedListEq, SinglyLinkedList) {
    std::forward_list<int> nums = {1, 2};
    std::forward_list<int> expected = {1, 2};
    DSATest::EXPECT_LIST_EQ(expected.begin(), nums.begin(), nums.end());
}
TEST(ExpectLinkedListEq, DoublyLinkedList) {
    std::list<int> nums = {1, 2};
    std::list<int> expected = {1, 2};
    DSATest::EXPECT_LIST_EQ(expected.begin(), nums.begin(), nums.end());
}

TEST(ExpectArrayEqLinkedList, case1) {
    int nums[] = {1, 2};
    std::forward_list<int> expected = {1, 2};
    DSATest::EXPECT_LIST_EQ(expected.begin(), nums, nums + 2);
}
TEST(ExpectArrayEqLinkedList, case2) {
    int nums[] = {1, 2};
    std::list<int> expected = {1, 2};
    DSATest::EXPECT_LIST_EQ(expected.begin(), nums, nums + 2);
}
TEST(ExpectArrayEqLinkedList, case3) {
    std::vector<int> nums = {1, 2};
    std::forward_list<int> expected = {1, 2};
    DSATest::EXPECT_LIST_EQ(expected.begin(), nums.begin(), nums.end());
}
TEST(ExpectArrayEqLinkedList, case4) {
    std::vector<int> nums = {1, 2};
    std::list<int> expected = {1, 2};
    DSATest::EXPECT_LIST_EQ(expected.begin(), nums.begin(), nums.end());
}

}
}
