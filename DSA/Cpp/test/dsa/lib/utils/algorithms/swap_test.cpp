#include <list>
#include <vector>

#include <dsa/lib/libdef.h>
#include <dsa/lib/utils/algorithm.hpp>
#include <dsa/testing/dsatest.h>

namespace dsa {
namespace {

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


}  // namespace
}  // namespace dsa