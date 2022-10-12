#include <dsa/lib/math/ds/triangle.hpp>
#include <cassert>
#include <gtest/gtest.h>

namespace dsa::lib::math::ds {
namespace {

int minTotal(std::vector<std::vector<int>> &&triangle) {
    int r = Triangle().minimumTotal(triangle);
    int r1 = Triangle().minimumTotal1(triangle);
    int r2 = Triangle().minimumTotal2(triangle);
    int r3 = Triangle().minimumTotal3(triangle);
    int r4 = Triangle().minimumTotal4(triangle);
    assert(r == r1 && r == r2 && r == r3 && r == r4
               && "Results from multiple same functions are different.");

    return r;
}
TEST(MinimumTotal, case1) {
    EXPECT_EQ(11, minTotal({
                               {2},
                               {3, 4},
                               {6, 5, 7},
                               {4, 1, 8, 3}
                           }));
    EXPECT_EQ(-10, minTotal({{-10}}));
}

}
}