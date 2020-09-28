#include "ls_test.h"

namespace dsa::lib::lists::linkedlists {
namespace {

TEST_F(ToArrayTest, case1) {
    int ary[] = {1};
    run(ary, sizeof(ary) / sizeof(ary[0]));
}
TEST_F(ToArrayTest, case2) {
    int ary[] = {1, 2};
    run(ary, sizeof(ary) / sizeof(ary[0]));
}
TEST_F(ToArrayTest, case3) {
    int ary[] = {1, 2, 3};
    run(ary, sizeof(ary) / sizeof(ary[0]));
}

TEST_F(LengthTest, case1) {
    int ary[] = {1};
    run(ary, 1);
}
TEST_F(LengthTest, case2) {
    int ary[] = {1, 2, 3};
    run(ary, 3);
}
TEST_F(LengthTest, case3) {
    int ary[] = {1, 2, 3, 4};
    run(ary, 4);
}

}  // namespace
}  // namespace dsa::lib::lists::linkedlists