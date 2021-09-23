#include <list>

#include <dsa/lib/libdef.h>
#include <dsa/lib/utils/algorithm.hpp>
#include <dsa/lib/utils/math.hpp>

namespace dsa {
namespace {

TEST(AnyOfTest, case1) {
    int nums[] = {2, 4, 6, 8};
    EXPECT_TRUE(dsa::any_of(nums, nums + arylen(nums), isEven));
    EXPECT_FALSE(dsa::any_of(nums, nums, isEven));
}
TEST(AnyOfTest, case2) {
    int nums[] = {2, 4, 5, 8};
    EXPECT_TRUE(dsa::any_of(nums, nums + arylen(nums), isEven));
    EXPECT_FALSE(dsa::any_of(nums, nums, isEven));
}
TEST(AnyOfTest, case3) {
    int nums[] = {1, 3, 5, 7};
    EXPECT_FALSE(dsa::any_of(nums, nums + arylen(nums), isEven));
    EXPECT_FALSE(dsa::any_of(nums, nums, isEven));
}
TEST(AnyOfTest, statisAssert) {
    CONSTEXPR int ia[] = {2, 4, 6, 8};
    CONSTEXPR int ib[] = {1, 3, 5, 7};
    CONSTEXPR bool r1 = dsa::any_of(std::begin(ia), std::end(ia), isEven);
    CONSTEXPR bool r2 = dsa::any_of(std::begin(ib), std::end(ib), isEven);
    static_assert(r1 && !r2);
}

}
}