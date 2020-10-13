#include "sls_test.h"

namespace dsa::lib::lists::linkedlists {
namespace {

class ToArrayTest : public SinglyLinkedListTest {
 protected:
    static void run(int *ary, length_t length) {
        ListNode *head = arrayToSinglyLinkedlist(ary, length);
        arrayStruct actual = toArray(head);
        EXPECT_ARRAY_EQ(ary, length, actual.ary, actual.length);

        LinkedList::destroy(head);
        delete[] actual.ary;
    }
    static arrayStruct toArray(ListNode *head) {
        SinglyLinkedList ls(head);
        arrayStruct actual = ls.toArray();
        return actual;
    }
};
TEST_F(ToArrayTest, case1) {
    int ary[] = {1, 2, 3};
    run(ary, aryLength(ary));
}

}  // namespace
}  // namespace dsa