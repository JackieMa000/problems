#include "array_test.h"

namespace dsa::lib::lists::arrays {
namespace {

TEST_F(ToSinglyLinkedListTest, case1) {
    int ary[] = {1};
    run(ary, sizeof(ary) / sizeof(ary[0]));
}

TEST_F(ToSinglyLinkedListTest, case2) {
    int ary[] = {1, 2, 3};
    run(ary, sizeof(ary) / sizeof(ary[0]));
}

TEST_F(ToBinaryTreeTest, case1) {
    int ary[] = {1, 2, 3};
    run(ary, sizeof(ary) / sizeof(ary[0]));
}

TEST_F(ToBinaryTreeTest, case2) {
    int ary[] = {3, 1, 5, 0, 2};
    run(ary, sizeof(ary) / sizeof(ary[0]));
}

TEST_F(ToBinaryTreeTest, case3) {
    int ary[] = {5, 1, 4, 0, 6, 3, 6};
    run(ary, sizeof(ary) / sizeof(ary[0]));
}

}  // namespace
}  // namespace dsa::lib::lists::arrays