#include "ls.h"

namespace dsa::lib::lists::linkedlists {

LinkedList::LinkedList(nodes::ListNode *head) : head(head) {
}

void
LinkedList::destroy() {
    nodes::ListNode *cur, *next;
    cur = this->head;
    while (cur) {
        next = cur->next;
        delete cur;
        cur = next;
    }
};

unsigned int
LinkedList::size() {
    nodes::ListNode *cur = this->head;
    int len = 0;
    while (cur) {
        len++;
        cur = cur->next;
    }
    return len;
};

std::tuple<unsigned int, int *>
LinkedList::toArray() {
    int *res;
    int ary[this->size()];
    res = ary;

    nodes::ListNode *cur = this->head;
    int i = 0;
    while (cur) {
        *(res + i) = cur->val;
        cur = cur->next;
        i++;
    }

    return {this->size(), res};
}

nodes::ListNode *
LinkedList::getNodeByIndex(int idx) const {
    // ToDo
    nodes::ListNode *ls;
    return ls;
}

}  // namespace dsa::lib::lists::linkedlists
