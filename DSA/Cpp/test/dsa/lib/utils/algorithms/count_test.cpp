#include <list>
#include <vector>

#include <dsa/lib/libdef.h>
#include <dsa/lib/utils/algorithm.hpp>

namespace dsa {
namespace {

TEST(CountTest, array) {
    int nums[] = {0, 1, 2, 2, 0, 1, 2, 3};
    EXPECT_EQ(3, dsa::count(nums, nums + arylen(nums), 2));
    EXPECT_EQ(0, dsa::count(nums, nums + arylen(nums), 7));
    EXPECT_EQ(0, dsa::count(nums, nums, 2));
}
TEST(CountIfTest, array) {
    int nums[] = {0, 1, 2, 2, 0, 1, 2, 3};
    EXPECT_EQ(3, dsa::count_if(nums, nums + arylen(nums), equal_to(2)));
    EXPECT_EQ(0, dsa::count_if(nums, nums + arylen(nums), equal_to(7)));
    EXPECT_EQ(0, dsa::count_if(nums, nums, equal_to(2)));
}

}
}