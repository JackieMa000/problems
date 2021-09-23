#include <list>
#include <vector>

#include <dsa/lib/libdef.h>
#include <dsa/lib/utils/algorithm.hpp>
#include <dsa/testing/dsatest.h>
#include <dsa/lib/utils/math.hpp>

namespace dsa {
namespace {

TEST(RemoveTest, array) {
    int nums[] = {0, 1, 0, 2};
    int expected[] = {1, 2};

    int *last = dsa::remove(nums, nums + arylen(nums), 0);
    long n = dsa::distance(nums, last);
    EXPECT_LIST_EQ(expected, nums, nums + n);
}
TEST(RemoveIfTest, vector) {
    std::vector<int> nums = {1, 2, 3};
    std::vector<int> expected = {2};

    auto last = dsa::remove_if(nums.begin(), nums.end(), isOdd);

    std::vector<int> result(1);
    dsa::copy(nums.begin(), last, result.begin());
    EXPECT_EQ(expected, result);
}

}
}