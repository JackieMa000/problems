#include <list>

#include <dsa/lib/libdef.h>
#include <dsa/lib/utils/algorithm.hpp>
#include <dsa/lib/utils/math.hpp>

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