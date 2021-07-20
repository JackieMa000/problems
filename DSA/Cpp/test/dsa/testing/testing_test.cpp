#include "testing.h"

namespace dsa::testing {
namespace {

TEST(ExpectArrayEqIter, emptyElement) {
    int nums[] = {1};
    int expected[] = {2};
    DSATest::EXPECT_LIST_EQ(nums, nums, expected);
}
TEST(ExpectArrayEqIter, oneElement) {
    int nums[] = {1};
    int expected[] = {1};
    DSATest::EXPECT_LIST_EQ(nums, nums + 1, expected);
}
TEST(ExpectArrayEqIter, oneElement1) {
    int nums[] = {1};
    int expected[] = {1, 2};
    DSATest::EXPECT_LIST_EQ(nums, nums + 1, expected);
}
TEST(ExpectArrayEqIter, oneElement2) {
    int nums[] = {1, 3};
    int expected[] = {1, 2};
    DSATest::EXPECT_LIST_EQ(nums, nums + 1, expected);
}
TEST(ExpectArrayEqIter, twoElements) {
    int nums[] = {1, 2};
    int expected[] = {1, 2};
    DSATest::EXPECT_LIST_EQ(nums, nums + 2, expected);
}


}
}
