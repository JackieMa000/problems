#include <dsa/lib/libdef.h>
#include "dsa/lib/utils/utils.h"
#include "utils_test.h"

namespace dsa::lib::utils {
namespace {

class ArrayRstripTest : public UtilsTest {};

TEST_F(ArrayRstripTest, empty_array) {
    int ary[] = {}, expected[] = {};
    length_t actLen = utils::arrayRstrip(ary, aryLength(ary));
    EXPECT_ARRAY_EQ(expected, aryLength(expected), ary, actLen);
}
TEST_F(ArrayRstripTest, length1_element0) {
    int ary[] = {0}, expected[] = {};
    length_t actLen = utils::arrayRstrip(ary, aryLength(ary));
    EXPECT_ARRAY_EQ(expected, aryLength(expected), ary, actLen);
}
TEST_F(ArrayRstripTest, last_element_not0) {
    int ary[] = {1, 2}, expected[] = {1, 2};
    length_t actLen = utils::arrayRstrip(ary, aryLength(ary));
    EXPECT_ARRAY_EQ(expected, aryLength(expected), ary, actLen);
}
TEST_F(ArrayRstripTest, last_element0_case1) {
    int ary[] = {1, 2, 0}, expected[] = {1, 2};
    length_t actLen = utils::arrayRstrip(ary, aryLength(ary));
    EXPECT_ARRAY_EQ(expected, aryLength(expected), ary, actLen);
}
TEST_F(ArrayRstripTest, last_element0_case2) {
    int ary[] = {1, 0, 2, 0, 0}, expected[] = {1, 0, 2};
    length_t actLen = utils::arrayRstrip(ary, aryLength(ary));
    EXPECT_ARRAY_EQ(expected, aryLength(expected), ary, actLen);
}

}  // namespace
}  // namespace dsa