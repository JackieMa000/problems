#include "sls.h"

namespace dsa::lib::lists::linkedlists {

SinglyLinkedList::SinglyLinkedList(nodes::ListNode *head) : LinkedList(head) {};

// reverse the nodes before a certain node
nodes::ListNode *
SinglyLinkedList::reverseBefore(nodes::ListNode *node) {
    nodes::ListNode *pre, *cur, *next;
    pre = node;
    cur = this->head;

    while (cur != node) {
        next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    return pre;
};

nodes::ListNode *
SinglyLinkedList::reverse() {
    nodes::ListNode *pre, *cur, *next;
    cur = this->head;

    while (cur) {
        next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    return pre;
}

nodes::ListNode *
SinglyLinkedList::reverseFromTo(nodes::ListNode *fnode, nodes::ListNode *tnode) {
    return nullptr;
}

}  // namespace dsa::lib::lists::linkedlists