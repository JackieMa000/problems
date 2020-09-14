#include "ls.h"

#ifndef LIB_LISTS_LINKEDLISTS_SLS_H
#define LIB_LISTS_LINKEDLISTS_SLS_H

namespace dsa::lib::lists::linkedlists {

class SinglyLinkedList : public LinkedList
{
public:
    SinglyLinkedList(nodes::ListNode* head);
    // ~SinglyLinkedList();

    nodes::ListNode*
    reverse();

    nodes::ListNode*
    reverseBefore(nodes::ListNode* node);

    nodes::ListNode*
    reverseFromTo(nodes::ListNode* fnode, nodes::ListNode* tnode);
};

}  // namespace dsa::lib::lists::linkedlists

#endif