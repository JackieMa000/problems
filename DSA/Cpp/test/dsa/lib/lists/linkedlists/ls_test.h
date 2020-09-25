#ifndef LIB_LISTS_LINKEDLISTS_LS_TEST_H
#define LIB_LISTS_LINKEDLISTS_LS_TEST_H

#include <dsa/lib/lists/list_test.h>
#include <dsa/lib/arrays/array.h>
#include <dsa/lib/lists/linkedlists/ls.h>

namespace dsa::lib::lists::linkedlists {

class LinkedListTest : public ListTest {};
class ToArrayTest : public LinkedListTest {
 protected:
    static void run(int *ary, length_t length) {
        arrays::Array array(ary, length);
        ListNode *head = array.toSinglyLinkedList();

        LinkedList ls(head);
        auto[actLen, actAry] = ls.toArray();

        EXPECT_ARRAY_EQ(ary, length, actAry, actLen);
        LinkedList::destroy(head);
    }
};
class LengthTest : public LinkedListTest {
 protected:
    static void run(int *ary, length_t length) {
        arrays::Array array(ary, length);
        ListNode *head = array.toSinglyLinkedList();

        LinkedList ls(head);
        auto actual = ls.length();

        EXPECT_EQ(length, actual);
        LinkedList::destroy(head);
    }
};

}  // namespace dsa::lib::lists::linkedlists

#endif