#include "sls.h"

namespace dsa::lib::lists::linkedlists {

SinglyLinkedList::SinglyLinkedList(ListNode *head) : LinkedList(head) {}

// reverse the nodes before a certain node
ListNode *SinglyLinkedList::reverseBefore(ListNode *node) {
    ListNode *pre, *cur, *next;
    pre = node;
    cur = this->head;

    while (cur != node) {
        next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    return pre;
}

ListNode *SinglyLinkedList::reverse() {
    ListNode *pre, *cur, *next;
    cur = this->head;

    while (cur) {
        next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    return pre;
}

ListNode *SinglyLinkedList::reverseFromTo(ListNode *fnode, ListNode *tnode) {
//    ToDo
    return nullptr;
}

}  // namespace dsa::lib::lists::linkedlists