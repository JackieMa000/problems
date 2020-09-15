#include "array_test_fx.hpp"

namespace dsa::lib::lists::arrays {
namespace {

TEST_F(ArrayTest, case_array_eq) {
    int expected[] = {1, 2, 3}, actual[] = {1, 2, 3};
    EXPECT_ARRAY_EQ(expected,
                    sizeof(expected) / 4, actual, sizeof(actual) / 4);
}

TEST_F(ToSinglyLinkedListTest, case1) {
    int ary[] = {1};
    run(ary,
        sizeof(ary) / 4);
}

TEST_F(ToSinglyLinkedListTest, case2) {
    int ary[] = {1, 2, 3};
    run(ary,
        sizeof(ary) / 4);
}

}  // namespace
}  // namespace dsa::lib::lists::arrays