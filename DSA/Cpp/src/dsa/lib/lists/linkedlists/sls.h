#ifndef LIB_LISTS_LINKEDLISTS_SLS_H
#define LIB_LISTS_LINKEDLISTS_SLS_H

#include "ls.h"

namespace dsa::lib::lists::linkedlists {

class SinglyLinkedList : public LinkedList {
 public:
    explicit SinglyLinkedList(nodes::ListNode *head);

    nodes::ListNode *reverse();
    nodes::ListNode *reverseBefore(nodes::ListNode *node);
    nodes::ListNode *reverseFromTo(nodes::ListNode *fnode, nodes::ListNode *tnode);
};

}  // namespace dsa::lib::lists::linkedlists

#endif