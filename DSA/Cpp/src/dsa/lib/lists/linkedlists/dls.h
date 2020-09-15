#ifndef LIB_LISTS_LINKEDLISTS_DLS_H
#define LIB_LISTS_LINKEDLISTS_DLS_H

#include "ls.h"

namespace dsa::lib::lists::linkedlists {

class DoublyLinkedList : public LinkedList {
 public:
    DoublyLinkedList(nodes::ListNode *head);
    // ~DoublyLinkedList();

    nodes::ListNode *
    reverse();
};

}  // namespace dsa

#endif