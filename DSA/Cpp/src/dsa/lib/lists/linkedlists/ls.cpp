#include "ls.h"

namespace dsa::lib::lists::linkedlists {

LinkedList::LinkedList(ListNode *head) : head(head) {
}

void LinkedList::destroy(ListNode *head) {
    ListNode *cur, *next;
    cur = head;
    while (cur) {
        next = cur->next;
        delete cur;
        cur = next;
    }
}

length_t LinkedList::length() {
    ListNode *cur = this->head;
    length_t len = 0;
    while (cur) {
        len++;
        cur = cur->next;
    }
    return len;
}

std::tuple<length_t, int *> LinkedList::toArray() {
    int *ary = new int[this->length()];

    ListNode *cur = this->head;
    int i = 0;
    while (cur) {
        *(ary + i) = cur->val;
        cur = cur->next;
        i++;
    }
    return {this->length(), ary};
}

ListNode *LinkedList::getNodeByIndex(int idx) const {
    ListNode *cur = this->head;
    for (int i = 0; cur && i < idx; ++i) { cur = cur->next; }
    return cur;
}

}  // namespace dsa::lib::lists::linkedlists
