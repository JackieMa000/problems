#include <list>

#include <dsa/lib/libdef.h>
#include <dsa/lib/utils/algorithm.hpp>
#include <dsa/lib/utils/math.hpp>

namespace dsa {
namespace {

TEST(NoneOfTest, case1) {
    int nums[] = {2, 4, 6, 8};
    EXPECT_FALSE(dsa::none_of(nums, nums + arylen(nums), isEven));
    EXPECT_TRUE(dsa::none_of(nums, nums, isEven));
}
TEST(NoneOfTest, case2) {
    int nums[] = {2, 4, 5, 8};
    EXPECT_FALSE(dsa::none_of(nums, nums + arylen(nums), isEven));
    EXPECT_TRUE(dsa::none_of(nums, nums, isEven));
}
TEST(NoneOfTest, statisAssert) {
    CONSTEXPR int ia[] = {1, 3, 6, 7};
    CONSTEXPR int ib[] = {1, 3, 5, 7};
    CONSTEXPR bool r1 = dsa::none_of(std::begin(ia), std::end(ia), isEven);
    CONSTEXPR bool r2 = dsa::none_of(std::begin(ib), std::end(ib), isEven);
    static_assert(!r1 && r2);
}

}
}