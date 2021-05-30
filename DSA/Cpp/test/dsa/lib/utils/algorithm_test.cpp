#include <dsa/lib/libdef.h>
#include <dsa/lib/utils/algorithm.hpp>
#include <dsa/testing/dsatest.h>
#include <list>
#include <dsa/lib/utils/math.h>
#include "dsa/lib/utils/out.h"
#include <random>

namespace dsa {
namespace {

TEST(rStripTest, empty_array) {
    int ary[] = {}, expected[] = {};
    length_t actLen = rStrip(ary, aryLength(ary));
    EXPECT_ARRAY_EQ(expected, aryLength(expected), ary, actLen);
}
TEST(rStripTest, length1_element0) {
    int ary[] = {0}, expected[] = {};
    length_t actLen = rStrip(ary, aryLength(ary));
    EXPECT_ARRAY_EQ(expected, aryLength(expected), ary, actLen);
}
TEST(rStripTest, last_element_not0) {
    int ary[] = {1, 2}, expected[] = {1, 2};
    length_t actLen = rStrip(ary, aryLength(ary));
    EXPECT_ARRAY_EQ(expected, aryLength(expected), ary, actLen);
}
TEST(rStripTest, last_element0_case1) {
    int ary[] = {1, 2, 0}, expected[] = {1, 2};
    length_t actLen = rStrip(ary, aryLength(ary));
    EXPECT_ARRAY_EQ(expected, aryLength(expected), ary, actLen);
}
TEST(rStripTest, last_element0_case2) {
    int ary[] = {1, 0, 2, 0, 0}, expected[] = {1, 0, 2};
    length_t actLen = rStrip(ary, aryLength(ary));
    EXPECT_ARRAY_EQ(expected, aryLength(expected), ary, actLen);
}

TEST(rStripTest, empty_array_iter) {
    int ary[] = {};
    auto last = rStrip(ary, ary);
    EXPECT_EQ(ary, last);
}
TEST(rStripTest, length1_element0_iter) {
    int ary[] = {0};
    auto last = rStrip(ary, ary + 1);
    EXPECT_EQ(ary, last);
}
TEST(rStripTest, all_elements_0_iter) {
    int ary[] = {0, 0, 0};
    auto last = rStrip(ary, ary + 3);
    EXPECT_EQ(ary, last);
}
TEST(rStripTest, last_element_not0_iter) {
    int ary[] = {1, 2};
    auto last = rStrip(ary, ary + 2);
    EXPECT_EQ(ary + 2, last);
    EXPECT_EQ(2, *(last - 1));
}
TEST(rStripTest, last_element0_case1_iter) {
    int ary[] = {1, 2, 0};
    auto last = rStrip(ary, ary + 3);
    EXPECT_EQ(ary + 2, last);
    EXPECT_EQ(2, *(last - 1));
}
TEST(rStripTest, last_element0_case2_iter) {
    int ary[] = {1, 0, 2, 0, 0};
    auto last = rStrip(ary, ary + 5);
    EXPECT_EQ(ary + 3, last);
    EXPECT_EQ(2, *(last - 1));
}

void assertFill(std::vector<int> &&expected, std::vector<int> &&v) {
    dsa::fill(v.begin(), v.end(), 1);
    EXPECT_EQ(expected, v);
}
TEST(FillTest, case1) {
    assertFill({1, 1, 1}, {0, 0, 0});
}

TEST(FillNTest, case1) {
    int nums[] = {0, 0, 0};
    int expected[] = {1, 1, 0};

    dsa::fill_n(nums, 2, 1);

    EXPECT_ARRAY_EQ(expected, aryLength(expected), nums, aryLength(nums));
}

TEST(SwapTest, arrayPos) {
    int ary[] = {1, 2, 3};
    int expected[] = {3, 2, 1};

    dsa::swap(ary, 0, 2);
    EXPECT_ARRAY_EQ(expected, aryLength(expected), ary, aryLength(ary));
}
TEST(SwapTest, vectorPos) {
    std::vector<int> v = {1, 2, 3};
    std::vector<int> expected = {3, 2, 1};

    dsa::swap(v.begin(), 0, 2);
    EXPECT_EQ(expected, v);
}
TEST(SwapTest, nonArray) {
    int x = 10, y = 20;
    dsa::swap(x, y);

    EXPECT_EQ(20, x);
    EXPECT_EQ(10, y);
}
TEST(SwapTest, array) {
    int foo[4];
    int bar[] = {10, 20, 30, 40};
    int expected[] = {10, 20, 30, 40};

    dsa::swap(foo, bar);
    EXPECT_ARRAY_EQ(expected, aryLength(expected), foo, aryLength(foo));
}

TEST(CopyTest, array) {
    int src[] = {1, 2, 3};
    int des[3];

    dsa::copy(src, src + 3, des);
    EXPECT_ARRAY_EQ(src, aryLength(src), des, aryLength(des));
}
TEST(CopyTest, vector) {
    std::vector<int> src = {1, 2, 3};
    std::vector<int> des(3);

    dsa::copy(src.begin(), src.end(), des.begin());
    EXPECT_EQ(des, src);
}
TEST(CopyIfTest, array) {
    int src[] = {1, -2, -3};
    int des[1];
    int expected[] = {1};

    dsa::copy_if(src, src + 3, des, [](int x) { return x > 0; });
    EXPECT_ARRAY_EQ(expected, aryLength(expected), des, aryLength(des));
}
TEST(CopyIfTest, vector) {
    std::vector<int> src = {1, -2, -3};
    std::vector<int> des(1);
    std::vector<int> expected = {1};

    dsa::copy_if(src.begin(), src.end(), des.begin(), [](int x) { return x > 0; });
    EXPECT_EQ(expected, des);
}
TEST(CopyNTest, array) {
    int src[] = {1, 2, 3};
    int des[2];
    int expected[] = {1, 2};

    dsa::copy_n(src, 2, des);
    EXPECT_ARRAY_EQ(expected, aryLength(expected), des, aryLength(des));
}
TEST(CopyNTest, vector) {
    std::vector<int> src = {1, 2, 3};
    std::vector<int> des(2);
    std::vector<int> expected = {1, 2};

    dsa::copy_n(src.begin(), 2, des.begin());
    EXPECT_EQ(expected, des);
}
TEST(CopyBackwardTest, array) {
    int src[] = {1, 2, 3};
    int des[3];
    int expected[] = {1, 2, 3};

    dsa::copy_backward(src, src + 3, des + 3);
    EXPECT_ARRAY_EQ(expected, aryLength(expected), des, aryLength(des));
}
TEST(CopyBackwardTest, vector) {
    std::vector<int> src = {1, 2, 3};
    std::vector<int> des(3);
    std::vector<int> expected = {1, 2, 3};

    dsa::copy_backward(src.begin(), src.end(), des.end());
    EXPECT_EQ(expected, des);
}
TEST(ReverseCopyTest, array) {
    int src[] = {1, 2, 3};
    int des[3];
    int expected[] = {3, 2, 1};

    dsa::reverse_copy(src, src + 3, des);
    EXPECT_ARRAY_EQ(expected, aryLength(expected), des, aryLength(des));
}
TEST(ReverseCopyTest, vector) {
    std::vector<int> src = {1, 2, 3};
    std::vector<int> des(3);
    std::vector<int> expected = {3, 2, 1};

    dsa::reverse_copy(src.begin(), src.end(), des.begin());
    EXPECT_EQ(expected, des);
}
TEST(ReplaceTest, array) {
    int nums[] = {1, 2, 3};
    int expected[] = {1, 0, 3};

    dsa::replace(nums, nums + 3, 2, 0);

    EXPECT_ARRAY_EQ(expected, aryLength(expected), nums, aryLength(nums));
}
TEST(ReplaceTest, vector) {
    std::vector<int> nums = {1, 2, 3};
    std::vector<int> expected = {1, 0, 3};

    dsa::replace(nums.begin(), nums.end(), 2, 0);
    EXPECT_EQ(expected, nums);
}

TEST(ReplaceIfTest, array) {
    int nums[] = {1, 2, 3};
    int expected[] = {0, 2, 0};

    dsa::replace_if(nums, nums + 3, isOdd, 0);

    EXPECT_ARRAY_EQ(expected, aryLength(expected), nums, aryLength(nums));
}
TEST(ReplaceIfTest, vector) {
    std::vector<int> nums = {1, 2, 3};
    std::vector<int> expected = {0, 2, 0};

    dsa::replace_if(nums.begin(), nums.end(), isOdd, 0);
    EXPECT_EQ(expected, nums);
}

TEST(RemoveTest, array) {
    int nums[] = {0, 1, 0, 2};
    int expected[] = {1, 2};

    int *last = dsa::remove(nums, nums + aryLength(nums), 0);
    long n = dsa::distance(nums, last);
    EXPECT_ARRAY_EQ(expected, aryLength(expected), nums, n);
}
TEST(RemoveIfTest, vector) {
    std::vector<int> nums = {1, 2, 3};
    std::vector<int> expected = {2};

    auto last = dsa::remove_if(nums.begin(), nums.end(), isOdd);

    std::vector<int> result(1);
    dsa::copy(nums.begin(), last, result.begin());
    EXPECT_EQ(expected, result);
}

TEST(DistanceTest, array) {
    int nums[] = {1, 2, 3};
    long actual = dsa::distance(nums, nums);
    EXPECT_EQ(actual, 0);
}
TEST(DistanceTest, array1) {
    int nums[] = {1, 2, 3};
    auto actual = dsa::distance(nums, nums + 3);
    EXPECT_EQ(actual, 3);
}
TEST(DistanceTest, list) {
    std::list<int> nums = {1, 2, 3};
    auto actual = dsa::distance(nums.begin(), nums.end());
    EXPECT_EQ(actual, 3);
}
TEST(DistanceTest, vector) {
    std::vector<int> nums = {1, 2, 3};
    auto actual = dsa::distance(nums.begin(), nums.end());
    EXPECT_EQ(actual, 3);
}

TEST(FindTest, vector) {
    std::vector<int> nums = {1, 2, 3};
    auto actual = dsa::find(nums.begin(), nums.end(), 2);
    EXPECT_EQ(2, *actual);
}
TEST(FindIfTest, array) {
    int nums[] = {1, -2, -3};
    auto actual = dsa::find_if(nums, nums + aryLength(nums), [](int x) { return x < 0; });
    EXPECT_EQ(-2, *actual);
    EXPECT_EQ(1, dsa::distance(nums, actual));
}
TEST(FindIfNotTest, list) {
    std::list<int> nums = {-1, 2, 3};
    auto actual = dsa::find_if_not(nums.begin(), nums.end(), [](int x) { return x < 0; });
    EXPECT_EQ(2, *actual);
    EXPECT_EQ(1, dsa::distance(nums.begin(), actual));
}

TEST(CountTest, array) {
    int nums[] = {0, 1, 2, 2, 0, 1, 2, 3};
    EXPECT_EQ(3, dsa::count(nums, nums + aryLength(nums), 2));
    EXPECT_EQ(0, dsa::count(nums, nums + aryLength(nums), 7));
    EXPECT_EQ(0, dsa::count(nums, nums, 2));
}
TEST(CountIfTest, array) {
    int nums[] = {0, 1, 2, 2, 0, 1, 2, 3};
    EXPECT_EQ(3, dsa::count_if(nums, nums + aryLength(nums), equal(2)));
    EXPECT_EQ(0, dsa::count_if(nums, nums + aryLength(nums), equal(7)));
    EXPECT_EQ(0, dsa::count_if(nums, nums, equal(2)));
}

TEST(ReverseTest, arrayOneElement) {
    int nums[] = {0};
    int expected[] = {0};
    dsa::reverse(nums, nums + aryLength(nums));
    EXPECT_ARRAY_EQ(expected, aryLength(expected), nums, aryLength(nums));
}
TEST(ReverseTest, array) {
    int nums[] = {1, 2, 3};
    int expected[] = {3, 2, 1};
    dsa::reverse(nums, nums + aryLength(nums));
    EXPECT_ARRAY_EQ(expected, aryLength(expected), nums, aryLength(nums));
}
TEST(ReverseTest, list) {
    std::list<int> nums = {1, 2, 3};
    std::list<int> expected = {3, 2, 1};
    dsa::reverse(nums.begin(), nums.end());
    EXPECT_EQ(expected, nums);
}
TEST(ReverseTest, vector) {
    std::vector<int> nums = {1, 2, 3};
    std::vector<int> expected = {3, 2, 1};
    dsa::reverse(nums.begin(), nums.end());
    EXPECT_EQ(expected, nums);
}

TEST(MinTest, case1) {
    int x = 0;
    int y = 0;
    EXPECT_EQ(&x, &dsa::min(x, y));
    EXPECT_EQ(&y, &dsa::min(y, x));
}
TEST(MinTest, case2) {
    int x = 0;
    int y = 1;
    EXPECT_EQ(&x, &dsa::min(x, y));
    EXPECT_EQ(&x, &dsa::min(y, x));
}
TEST(MinTest, case3) {
    int x = 1;
    int y = 0;
    EXPECT_EQ(&y, &dsa::min(x, y));
    EXPECT_EQ(&y, &dsa::min(y, x));
}

TEST(MinCompTest, case1) {
    int x = 0;
    int y = 0;
    EXPECT_EQ(&x, &dsa::min(x, y, std::greater<>()));
}
TEST(MinCompTest, case2) {
    int x = 0;
    int y = 1;
    EXPECT_EQ(&y, &dsa::min(x, y, std::greater<>()));
}
TEST(MinCompTest, case3) {
    int x = 1;
    int y = 0;
    EXPECT_EQ(&x, &dsa::min(x, y, std::greater<>()));
}

TEST(MinInitListTest, case1) {
    EXPECT_EQ(1, dsa::min({2, 3, 1}));
    EXPECT_EQ(1, dsa::min({2, 1, 3}));
    EXPECT_EQ(1, dsa::min({3, 1, 2}));
    EXPECT_EQ(1, dsa::min({3, 2, 1}));
    EXPECT_EQ(1, dsa::min({1, 2, 3}));
    EXPECT_EQ(1, dsa::min({1, 3, 2}));
}

TEST(MinInitListCompTest, case1) {
    EXPECT_EQ(3, dsa::min({2, 3, 1}, std::greater<>()));
    EXPECT_EQ(3, dsa::min({2, 1, 3}, std::greater<>()));
    EXPECT_EQ(3, dsa::min({3, 1, 2}, std::greater<>()));
    EXPECT_EQ(3, dsa::min({3, 2, 1}, std::greater<>()));
    EXPECT_EQ(3, dsa::min({1, 2, 3}, std::greater<>()));
    EXPECT_EQ(3, dsa::min({1, 3, 2}, std::greater<>()));
}

TEST(MinElementTest, array) {
    int nums[] = {2, 4, 6, 8, 7, 5, 3, 1};
    int *actual = dsa::min_element(nums, nums + aryLength(nums));
    EXPECT_EQ(1, *actual);
}
TEST(MinElementTest, list) {
    std::list<int> nums = {2, 4, 6, 8, 7, 5, 3, 1};
    auto actual = dsa::min_element(nums.begin(), nums.end());
    EXPECT_EQ(1, *actual);
}
TEST(MinElementTest, vector) {
    std::vector<int> nums = {2, 4, 6, 8, 7, 5, 3, 1};
    auto actual = dsa::min_element(nums.begin(), nums.end());
    EXPECT_EQ(1, *actual);
}
TEST(MinElementTest, staticAssert) {
    static constexpr int nums[] = {2, 4, 6, 8, 7, 5, 3, 1};
    constexpr auto actual = dsa::min_element(nums, nums + 8);
    static_assert(*actual == 1);
}

TEST(MinElementCompTest, array) {
    int nums[] = {2, 4, 6, 8, 7, 5, 3, 1};
    EXPECT_EQ(1, *dsa::min_element(nums, nums + aryLength(nums), std::less<>()));
    EXPECT_EQ(8, *dsa::min_element(nums, nums + aryLength(nums), std::greater<>()));
}
TEST(MinElementCompTest, list) {
    std::list<int> nums = {2, 4, 6, 8, 7, 5, 3, 1};
    EXPECT_EQ(1, *dsa::min_element(nums.begin(), nums.end(), std::less<>()));
    EXPECT_EQ(8, *dsa::min_element(nums.begin(), nums.end(), std::greater<>()));
}
TEST(MinElementCompTest, vector) {
    std::vector<int> nums = {2, 4, 6, 8, 7, 5, 3, 1};
    EXPECT_EQ(1, *dsa::min_element(nums.begin(), nums.end(), std::less<>()));
    EXPECT_EQ(8, *dsa::min_element(nums.begin(), nums.end(), std::greater<>()));
}
TEST(MinElementCompTest, staticAssert) {
    static constexpr int nums[] = {2, 4, 6, 8, 7, 5, 3, 1};
    constexpr auto actual = dsa::min_element(nums, nums + 8, std::less<>());
    static_assert(*actual == 1);
}

}  // namespace
}  // namespace dsa