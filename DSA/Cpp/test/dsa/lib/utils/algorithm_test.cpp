#include <list>
#include <vector>

#include <dsa/lib/libdef.h>
#include <dsa/lib/utils/algorithm.hpp>
#include <dsa/testing/dsatest.h>

namespace dsa {
namespace {

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
    EXPECT_LIST_EQ(expected, nums, nums + arylen(nums));
}

TEST(SwapTest, arrayPos) {
    int ary[] = {1, 2, 3};
    int expected[] = {3, 2, 1};
    dsa::swap(ary, 0, 2);
    EXPECT_LIST_EQ(expected, ary, ary + arylen(ary));
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
    EXPECT_LIST_EQ(expected, foo, foo + arylen(foo));
}

TEST(CopyTest, array) {
    int src[] = {1, 2, 3};
    int des[3];

    dsa::copy(src, src + 3, des);
    EXPECT_LIST_EQ(src, des, des + arylen(des));
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
    EXPECT_LIST_EQ(expected, des, des + arylen(des));
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
    EXPECT_LIST_EQ(expected, des, des + arylen(des));
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
    EXPECT_LIST_EQ(expected, des, des + arylen(des));
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
    EXPECT_LIST_EQ(expected, des, des + arylen(des));
}
TEST(ReverseCopyTest, vector) {
    std::vector<int> src = {1, 2, 3};
    std::vector<int> des(3);
    std::vector<int> expected = {3, 2, 1};

    dsa::reverse_copy(src.begin(), src.end(), des.begin());
    EXPECT_EQ(expected, des);
}

}  // namespace
}  // namespace dsa