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
    pre = nullptr;
    cur = this->head;

    while (cur) {
        next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    return pre;
}

// Reverse the nodes from *fnode* to *tnode*, does not include the *tnode* node
ListNode *SinglyLinkedList::reverseFromTo(ListNode *fnode, ListNode *tnode) {
    ListNode *cur = this->head;
    ListNode dummy;
    dummy.next = cur;
    ListNode *groupPre = &dummy;

    while (cur != fnode) {
        groupPre = cur;
        cur = cur->next;
    }

    SinglyLinkedList ls(fnode);
    groupPre->next = ls.reverseBefore(tnode);

    return dummy.next;
}

}  // namespace dsa::lib::lists::linkedlists