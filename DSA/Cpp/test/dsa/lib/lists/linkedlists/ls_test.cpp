#include <dsa/lib/lists/arrays/array.h>
#include <dsa/lib/lists/linkedlists/ls.h>
#include "ls_test.h"

namespace dsa::lib::lists::linkedlists {
namespace {

TEST_F(ToArrayTest, case1) {
    int expAry[] = {1, 2, 3};
    int expLen = sizeof(expAry) / 4;

    arrays::Array array(expAry, expLen);
    nodes::ListNode *head = array.toSinglyLinkedList();

    LinkedList ls(head);
    auto[actLen, actAry] = ls.toArray();

    EXPECT_ARRAY_EQ(expAry, expLen, actAry, actLen);

}

}  // namespace
}  // namespace dsa::lib::lists::linkedlists