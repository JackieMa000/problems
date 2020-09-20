#include <dsa/lib/lists/linkedlists/sls.h>
#include "sls_test_fx.hpp"

namespace dsa::lib::lists::linkedlists {
namespace {

TEST_F(SinglyLinkedListTest, case1) {
    int expAry[] = {1, 2, 3};
    size_t expSize = sizeof(expAry);
    nodes::ListNode *head = createSinglyLinkedList(expAry, expSize);

    SinglyLinkedList ls(head);
    auto[actSize, actAry] = ls.toArray();

    EXPECT_ARRAY_EQ(expAry, expSize, actAry, actSize);

    destroyLinkedList(head);
}

}  // namespace
}  // namespace dsa