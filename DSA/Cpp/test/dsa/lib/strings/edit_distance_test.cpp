#include <dsa/lib/strings/edit_distance.hpp>

namespace dsa::lib::strings {
namespace {

int getMinDistance(std::string &&w1, std::string &&w2) {
    auto r1 = EditDistance().minDistance(w1, w2);
    auto r2 = EditDistance().minDistance1(w1, w2);
    assert(r1 == r2 && "Results from 2 same functions are different.");

    return r1;
}
TEST(EditDistanceTest, emptyString) {
    EXPECT_EQ(0, getMinDistance("", ""));
    EXPECT_EQ(1, getMinDistance("a", ""));
    EXPECT_EQ(1, getMinDistance("", "a"));
}
TEST(EditDistanceTest, equalString) {
    EXPECT_EQ(0, getMinDistance("abc", "abc"));
}
TEST(EditDistanceTest, case1) {
    EXPECT_EQ(3, getMinDistance("horse", "ros"));
    EXPECT_EQ(5, getMinDistance("intention", "execution"));
}

}
}