#include "ls_test.h"

namespace dsa::lib::lists::linkedlists {
namespace {

class HasCycleTest : public LinkedListTest {
 protected:
    static bool hasCycle(ListNode *head) {
        LinkedList ls(head);
        return ls.hasCycle();
    }
};
TEST_F(HasCycleTest, case1) {
    int ary[] = {1};
    ListNode *head = arrayToSinglyLinkedlist(ary, aryLength(ary));
    bool actual = hasCycle(head);
    EXPECT_FALSE(actual);
    LinkedList::destroy(head);
}
TEST_F(HasCycleTest, case2) {
    int ary[] = {1, 2};
    ListNode *head = arrayToCyclicSinglyLinkedlist(ary, aryLength(ary), 0);
    bool actual = hasCycle(head);
    EXPECT_TRUE(actual);
    LinkedList::destroyCycle(head, aryLength(ary));
}
TEST_F(HasCycleTest, case3) {
    int ary[] = {3, 2, 0, 4};
    ListNode *head = arrayToCyclicSinglyLinkedlist(ary, aryLength(ary), 1);
    bool actual = hasCycle(head);
    EXPECT_TRUE(actual);
    LinkedList::destroyCycle(head, aryLength(ary));
}

}
}