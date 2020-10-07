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
    length_t n;
    for (n = 0; cur; n++) { cur = cur->next; }
    return n;
}

std::tuple<length_t, int *> LinkedList::toArray() {
    int *ary = new int[this->length()];
    ListNode *cur = this->head;
    for (int i = 0; cur; i++, cur = cur->next) { *(ary + i) = cur->val; }
    return {this->length(), ary};
}

ListNode *LinkedList::getNodeByIndex(int idx) const {
    ListNode *cur = this->head;
    for (int i = 0; i < idx && cur; ++i) { cur = cur->next; }
    return cur;
}
ListNode *LinkedList::getNodeByValue(int val) const {
    ListNode *cur = this->head;
    while (cur && cur->val != val) { cur = cur->next; }
    return cur;
}

}  // namespace dsa::lib::lists::linkedlists
