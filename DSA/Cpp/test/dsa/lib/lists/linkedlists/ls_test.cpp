#include "ls_test.h"
#include "dsa/lib/lists/arrays/array.h"

namespace dsa::lib::lists::linkedlists {
namespace {

TEST_F(LinkedListTest, case1)
{
    // ToDo
    // Arrange;
    int ary[] = {1, 2, 3};
    arrays::Array array(ary, sizeof(ary) / 4);
    nodes::ListNode* head = array.toSinglyLinkedList();

    // Act;
    LinkedList ls(head);
    int* actual = ls.toArray();

    // Assert;
    // EXPECT_ARRAY_EQ(ary, 3, actual, 3);
}

}  // namespace
}  // namespace dsa::lib::lists::linkedlists