#include <dsa/lib/lists/arrays/array.h>
#include <dsa/lib/lists/linkedlists/ls.h>
#include <dsa/lib/lists/linkedlists/sls.h>
#include "ls_test.h"

namespace dsa::lib::lists::linkedlists {
namespace {

nodes::ListNode *LinkedListTest::createSinglyLinkedList(int *ary, unsigned int length) {
    arrays::Array array(ary, length);
    return array.toSinglyLinkedList();
}

void LinkedListTest::destroyLinkedList(nodes::ListNode *head) {
    linkedlists::LinkedList ls(head);
    ls.destroy();
}

TEST_F(ToArrayTest, case1) {
    int expAry[] = {1, 2, 3};
    unsigned int expLen = sizeof(expAry) / 4;
    nodes::ListNode *head = createSinglyLinkedList(expAry, expLen);

    LinkedList ls(head);
    auto[actLen, actAry] = ls.toArray();

    EXPECT_ARRAY_EQ(expAry, expLen, actAry, actLen);

    destroyLinkedList(head);
}

}  // namespace
}  // namespace dsa::lib::lists::linkedlists