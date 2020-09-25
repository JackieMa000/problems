#ifndef LIB_LISTS_LINKEDLISTS_SLS_TEST_H
#define LIB_LISTS_LINKEDLISTS_SLS_TEST_H

#include "ls_test.h"

namespace dsa::lib::lists::linkedlists {

class SinglyLinkedListTest : public LinkedListTest {
 protected:
    static void run(int *ary, length_t length) {
        arrays::Array array(ary, length);
        nodes::ListNode *head = array.toSinglyLinkedList();

        SinglyLinkedList ls(head);
        auto[actLen, actAry] = ls.toArray();

        EXPECT_ARRAY_EQ(ary, length, actAry, actLen);
        LinkedList::destroy(head);
    }
};

}  // namespace dsa

#endif