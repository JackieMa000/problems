#include <dsa/lib/math/nums/KthLargest.hpp>
#include "nums_test.h"

namespace dsa::lib::math::nums {
namespace {

class KthLargestTest : public NumsTest {};
class AddTest : public KthLargestTest {};
TEST_F(AddTest, case1) {
    std::vector<int> nums = {4, 5, 8, 2};
    KthLargest kl(3, nums);
    EXPECT_EQ(4, kl.add(3));
    EXPECT_EQ(5, kl.add(5));
    EXPECT_EQ(5, kl.add(10));
    EXPECT_EQ(8, kl.add(9));
    EXPECT_EQ(8, kl.add(4));
}

}
}
