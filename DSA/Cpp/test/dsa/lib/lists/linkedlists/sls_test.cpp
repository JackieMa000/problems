#include <dsa/lib/lists/linkedlists/sls.h>
#include "sls_test_fx.hpp"

namespace dsa::lib::lists::linkedlists {
namespace {

TEST_F(SinglyLinkedListTest, case1) {
    int expAry[] = {1, 2, 3};
    unsigned int expLen = sizeof(expAry) / 4;
    nodes::ListNode *head = createSinglyLinkedList(expAry, expLen);

    SinglyLinkedList ls(head);
    auto[actLen, actAry] = ls.toArray();

    EXPECT_ARRAY_EQ(expAry, expLen, actAry, actLen);

    destroyLinkedList(head);
}

}  // namespace
}  // namespace dsa