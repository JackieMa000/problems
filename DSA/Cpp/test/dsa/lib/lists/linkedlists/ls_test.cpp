#include "ls_test_fx.hpp"

namespace dsa::lib::lists::linkedlists {
namespace {

TEST_F(ToArrayTest, case1) {
    int expAry[] = {1, 2, 3};
    size_t expSize = sizeof(expAry);
    nodes::ListNode *head = createSinglyLinkedList(expAry, expSize);

    LinkedList ls(head);
    auto[actSize, actAry] = ls.toArray();

    EXPECT_ARRAY_EQ(expAry, expSize, actAry, actSize);

    destroyLinkedList(head);
}

}  // namespace
}  // namespace dsa::lib::lists::linkedlists