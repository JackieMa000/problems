#include <dsa/lib/lists/linkedlists/sls.h>
#include "sls_test.h"

namespace dsa::lib::lists::linkedlists {
namespace {

TEST_F(SinglyLinkedListTest, case1) {
    int ary[] = {1, 2, 3};
    run(ary, sizeof(ary) / sizeof(ary[0]));
}

}  // namespace
}  // namespace dsa