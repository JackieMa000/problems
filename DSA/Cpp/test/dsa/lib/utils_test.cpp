#include "dsa/lib/utils.h"
#include "utils_test.h"

namespace dsa::lib::utils {
namespace {

TEST_F(ArrayRstripTest, empty_array) {
    int input[] = {}, expected[] = {}, desAry[0];
    auto[actSize, actAry] = utils::arrayRstrip(input, sizeof(input), desAry);
    EXPECT_ARRAY_EQ(expected, sizeof(expected), actAry, actSize);
}

TEST_F(ArrayRstripTest, length1_element0) {
    int input[] = {0}, expected[] = {}, desAry[0];
    auto[actSize, actAry] = utils::arrayRstrip(input, sizeof(input), desAry);
    EXPECT_ARRAY_EQ(expected, sizeof(expected), actAry, actSize);
}

TEST_F(ArrayRstripTest, last_element_not0) {
    int input[] = {1, 2}, expected[] = {1, 2}, desAry[0];
    auto[actSize, actAry] = utils::arrayRstrip(input, sizeof(input), desAry);
    EXPECT_ARRAY_EQ(expected, sizeof(expected), actAry, actSize);
}

TEST_F(ArrayRstripTest, last_element0_case1) {
    int input[] = {1, 2, 0}, expected[] = {1, 2}, desAry[0];
    auto[actSize, actAry] = utils::arrayRstrip(input, sizeof(input), desAry);
    EXPECT_ARRAY_EQ(expected, sizeof(expected), actAry, actSize);
}

TEST_F(ArrayRstripTest, last_element0_case2) {
    int input[] = {1, 0, 2, 0, 0}, expected[] = {1, 0, 2}, desAry[0];
    auto[actSize, actAry] = utils::arrayRstrip(input, sizeof(input), desAry);
    EXPECT_ARRAY_EQ(expected, sizeof(expected), actAry, actSize);
}

}  // namespace
}  // namespace dsa