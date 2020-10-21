#ifndef LIB_LISTS_LINKEDLISTS_SLS_H
#define LIB_LISTS_LINKEDLISTS_SLS_H

#include "ls.h"

namespace dsa::lib::lists::linkedlists {

class SinglyLinkedList : public LinkedList {
 public:
    explicit SinglyLinkedList(ListNode *head);

};

}  // namespace dsa::lib::lists::linkedlists

#endif