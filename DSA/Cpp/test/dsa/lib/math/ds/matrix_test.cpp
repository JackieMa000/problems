#include <vector>

#include <dsa/lib/math/ds/matrix.hpp>

namespace dsa::lib::math::ds {
namespace {

bool searchMatrix(std::vector<std::vector<int>> &&matrix, int target) {
    return Matrix().searchMatrix(matrix, target);
}
TEST(SearchMatirxTest, empty) {
    EXPECT_FALSE(searchMatrix({{}}, 1));
}
TEST(SearchMatirxTest, oneElement) {
    EXPECT_FALSE(searchMatrix({{1}}, 3));
    EXPECT_TRUE(searchMatrix({{1}}, 1));
}
TEST(SearchMatirxTest, case1) {
    EXPECT_TRUE(searchMatrix({
                                 {1, 2, 3, 4},
                                 {5, 6, 7, 8},
                                 {9, 10, 11, 12}}, 3));
    EXPECT_TRUE(searchMatrix({
                                 {1, 3, 5, 7},
                                 {10, 11, 16, 20},
                                 {23, 30, 34, 50}}, 5));
    EXPECT_TRUE(searchMatrix({
                                 {1, 3, 5, 7},
                                 {10, 11, 16, 20},
                                 {23, 30, 34, 50}}, 3));
    EXPECT_FALSE(searchMatrix({
                                  {1, 3, 5, 7},
                                  {10, 11, 16, 20},
                                  {23, 30, 34, 50}}, 13));
}

}
}