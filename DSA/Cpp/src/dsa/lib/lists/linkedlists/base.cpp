#include "base.h"

namespace dsa::lib::lists::linkedlists {

Base::Base(ListNode *head) : head(head) {}
void Base::Deleter::operator()(ListNode *p_head) { destroy(p_head); }
void Base::DeleterCycle::operator()(ListNode *p_head, length_t length) {
    destroy(p_head, length);
}
void Base::destroy(ListNode *head) {
    ListNode *cur, *next;
    cur = head;
    while (cur) {
        next = cur->next;
        delete cur;
        cur = next;
    }
}
void Base::destroy(ListNode *head, length_t length) {
    ListNode *cur, *next;
    cur = head;
    for (int i = 0; cur && i < length; ++i) {
        next = cur->next;
        delete cur;
        cur = next;
    }
}
length_t Base::length() {
    ListNode *cur = this->head;
    length_t n;
    for (n = 0; cur; n++) { cur = cur->next; }
    return n;
}
array_s Base::toArray() {
    array_s as{nullptr, 0};
    if (this->head) {
        int *ary = new int[this->length()];
        ListNode *cur = this->head;
        for (int i = 0; cur; i++, cur = cur->next) { *(ary + i) = cur->val; }
        as = {ary, this->length()};
    }
    return as;
}
ListNode *Base::getNodeByIndex(int idx) const {
    ListNode *cur = this->head;
    for (int i = 0; i < idx && cur; ++i) { cur = cur->next; }
    return cur;
}
ListNode *Base::getNodeByValue(int val) const {
    ListNode *cur = this->head;
    while (cur && cur->val != val) { cur = cur->next; }
    return cur;
}

}