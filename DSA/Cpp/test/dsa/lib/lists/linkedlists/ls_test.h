#ifndef LIB_LISTS_LINKEDLISTS_LS_TEST_H
#define LIB_LISTS_LINKEDLISTS_LS_TEST_H

#include <dsa/lib/lists/list_test.h>
#include <dsa/lib/arrays/array.h>
#include <dsa/lib/lists/linkedlists/ls.h>

namespace dsa::lib::lists::linkedlists {

class LinkedListTest : public ListTest {
 protected:
    static ListNode *generateSinglyLinkedListFromArray(int *ary, length_t length) {
        arrays::Array array(ary, length);
        return array.toSinglyLinkedList();
    }
};

class ToArrayTest : public LinkedListTest {
 protected:
    static void run(int *ary, length_t length) {
        ListNode *head = generateSinglyLinkedListFromArray(ary, length);
        auto[actLen, actAry] = toArray(head);

        EXPECT_ARRAY_EQ(ary, length, actAry, actLen);

        LinkedList::destroy(head);
        delete[] actAry;
    }

    static std::tuple<length_t, int *> toArray(ListNode *head) {
        LinkedList ls(head);
        return ls.toArray();
    }
};

class LengthTest : public LinkedListTest {
 protected:
    static void run(int *ary, length_t length) {
        ListNode *head = generateSinglyLinkedListFromArray(ary, length);
        length_t actual = getLength(head);
        EXPECT_EQ(length, actual);
        LinkedList::destroy(head);
    }

    static length_t getLength(ListNode *head) {
        LinkedList ls(head);
        return ls.length();
    }
};

}  // namespace dsa::lib::lists::linkedlists

#endif