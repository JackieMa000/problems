#include <list>

#include <dsa/lib/libdef.h>
#include <dsa/lib/utils/algorithm.hpp>

namespace dsa {
namespace {

struct for_each_test {
    int count;
    explicit for_each_test(int c) : count(c) {}
    void operator()(int &i) {
        ++i;
        ++count;
    }
};
TEST(ForEachTest, case1) {
    int nums[] = {0, 1, 2, 3, 4, 5};
    size_t s = arylen(nums);
    for_each_test f = dsa::for_each(nums, nums + s, for_each_test(0));

    EXPECT_EQ(s, f.count);
    for (unsigned i = 0; i < s; ++i)
        EXPECT_EQ(nums[i], static_cast<int>(i + 1));
}
#if TEST_STD_VER > 17
TEST(ForEachTest, staticAssert) {
    int nums[] = {1, 3, 6, 7};
    int expected[] = {3, 6, 8, 9};

    dsa::for_each(std::begin(nums), std::end(nums),[](int &a) { a += 2; });
    static_assert(std::equal(std::begin(nums), std::end(nums), std::begin(expected)));
}
#endif
TEST(ForEachNTest, case1) {
    int nums[] = {0, 1, 2, 3, 4, 5};
    size_t s = arylen(nums);

    auto f = for_each_test(0);
    auto it = dsa::for_each_n(nums, 0, f);

    EXPECT_EQ(nums, it);
    EXPECT_EQ(0, f.count);
}
#if TEST_STD_VER > 17
TEST(ForEachNTest, staticAssert) {
    int nums[] = {1, 3, 6, 7};
    int expected[] = {3, 6, 8, 9};
    const size_t n = 4;

    auto it = dsa::for_each_n(std::begin(nums), n,[](int &a) { a += 2; });
    static_assert(it == std::begin(nums) + n)
    static_assert(std::equal(std::begin(nums), std::end(nums), std::begin(expected)));
}
#endif

}
}