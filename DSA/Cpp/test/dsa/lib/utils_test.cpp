#include "dsa/lib/utils.h"
#include "utils_test.h"

namespace dsa::lib::utils {
namespace {

TEST_F(ArrayRstripTest, empty_array) {
//    Arrange;
//    Act;
    int ary[] = {};
    auto[actSize, actAry] = utils::arrayRstrip(ary, sizeof(ary));

//    Assert;
//    EXPECT_ARRAY_EQ(ary, sizeof(ary) / 4, actAry, actSize / 4);
}

}  // namespace
}  // namespace dsa