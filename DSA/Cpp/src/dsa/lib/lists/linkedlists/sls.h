#ifndef LIB_LISTS_LINKEDLISTS_SLS_H
#define LIB_LISTS_LINKEDLISTS_SLS_H

#include "ls.h"

namespace dsa::lib::lists::linkedlists {

class SinglyLinkedList : public LinkedList {
 public:
    explicit SinglyLinkedList(ListNode *head);

    ListNode *reverse();
    ListNode *reverseBefore(ListNode *node);
    ListNode *reverseFromTo(ListNode *fnode, ListNode *tnode);
};

}  // namespace dsa::lib::lists::linkedlists

#endif