#include <dsa/lib/lists/linkedlists/sls.h>
#include "sls_test_fx.hpp"

namespace dsa::lib::lists::linkedlists {
namespace {

TEST_F(SinglyLinkedListTest, case1) {
    int expAry[] = {1, 2, 3};
    length_t expLen = sizeof(expAry) / sizeof(expAry[0]);
    arrays::Array array(expAry, expLen);
    nodes::ListNode *head = array.toSinglyLinkedList();

    SinglyLinkedList ls(head);
    auto[actLen, actAry] = ls.toArray();

    EXPECT_ARRAY_EQ(expAry, expLen, actAry, actLen);
    destroyLinkedList(head);
}

}  // namespace
}  // namespace dsa