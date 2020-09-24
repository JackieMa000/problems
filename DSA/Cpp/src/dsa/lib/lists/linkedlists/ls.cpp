#include "ls.h"

namespace dsa::lib::lists::linkedlists {

LinkedList::LinkedList(nodes::ListNode *head) : head(head) {
}

void LinkedList::destroy(nodes::ListNode *head) {
    nodes::ListNode *cur, *next;
    cur = head;
    while (cur) {
        next = cur->next;
        delete cur;
        cur = next;
    }
}

length_t LinkedList::length() {
    nodes::ListNode *cur = this->head;
    length_t len = 0;
    while (cur) {
        len++;
        cur = cur->next;
    }
    return len;
}

std::tuple<length_t, int *> LinkedList::toArray() {
    int *res;
    int ary[this->length()];
    res = ary;

    nodes::ListNode *cur = this->head;
    int i = 0;
    while (cur) {
        *(res + i) = cur->val;
        cur = cur->next;
        i++;
    }

    return {this->length(), res};
}

nodes::ListNode *LinkedList::getNodeByIndex(int idx) const {
    // ToDo
    nodes::ListNode *ls;
    return ls;
}

}  // namespace dsa::lib::lists::linkedlists
