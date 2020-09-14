#include "dsa/testing/testing.h"
#include "dsa/lib/lists/linkedlists/ls.h"

namespace dsa {
namespace lib {
namespace lists {
namespace linkedlists {
namespace {

class LinkedListTest : public testing::DSATest
{
};

class SinglyLinkedListTest : public LinkedListTest
{
};

class DoublyLinkedListTest : public LinkedListTest
{
};

TEST_F(LinkedListTest, case1)
{
    // ToDo
    nodes::ListNode* head;
    LinkedList ls(head);
    ls.toArray();
}

}  // namespace
}  // namespace linkedlists
}  // namespace lists
}  // namespace lib
}  // namespace dsa