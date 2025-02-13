#include <dsa/lib/math/ds/median.hpp>

namespace dsa::lib::math::ds {
namespace {

double findMedianSortedArray(std::vector<int> &&nums1, std::vector<int> &&nums2) {
    return Median().findMedianSortedArrays(nums1, nums2);
}
TEST(FindMedianSortedArraysTest, case1) {
    EXPECT_FLOAT_EQ(2.0, findMedianSortedArray({1, 3}, {2}));
    EXPECT_FLOAT_EQ(2.5, findMedianSortedArray({1, 2}, {3, 4}));
}

}
}
