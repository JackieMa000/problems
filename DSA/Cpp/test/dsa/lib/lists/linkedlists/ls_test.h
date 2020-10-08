#ifndef LIB_LISTS_LINKEDLISTS_LS_TEST_H
#define LIB_LISTS_LINKEDLISTS_LS_TEST_H

#include <dsa/lib/lists/list_test.h>
#include <dsa/lib/arrays/array.h>
#include <dsa/lib/lists/linkedlists/ls.h>

namespace dsa::lib::lists::linkedlists {

class LinkedListTest : public ListTest {
 protected:
    static ListNode *arrayToLinkedlist(int *ary, length_t length) {
        arrays::Array array(ary, length);
        return array.toSinglyLinkedList();
    }
};

}  // namespace dsa::lib::lists::linkedlists

#endif