#include <list>

#include <dsa/lib/libdef.h>
#include <dsa/lib/utils/algorithm.hpp>
#include <dsa/lib/utils/math.hpp>

namespace dsa {
namespace {

TEST(AllOfTest, case1) {
    int nums[] = {2, 4, 6, 8};
    EXPECT_TRUE(dsa::all_of(nums, nums + arylen(nums), isEven));
    EXPECT_TRUE(dsa::all_of(nums, nums, isEven));
}
TEST(AllOfTest, case2) {
    int nums[] = {2, 4, 5, 8};
    EXPECT_FALSE(dsa::all_of(nums, nums + arylen(nums), isEven));
    EXPECT_TRUE(dsa::all_of(nums, nums, isEven));
}
TEST(AllOfTest, statisAssert) {
    CONSTEXPR int ia[] = {2, 4, 6, 8};
    CONSTEXPR int ib[] = {2, 4, 5, 8};
    CONSTEXPR bool r1 = dsa::all_of(std::begin(ia), std::end(ia), isEven);
    CONSTEXPR bool r2 = dsa::all_of(std::begin(ib), std::end(ib), isEven);
    static_assert(r1 && !r2);
}


}
}