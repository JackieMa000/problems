#include "array.h"

namespace dsa::lib::lists::arrays {

Array::Array(int ary[], unsigned int length) : ary(ary), length(length) {
}

nodes::ListNode *
Array::toSinglyLinkedList() {
    auto *dummy = new nodes::ListNode();
    auto *head = new nodes::ListNode(*this->ary);
    dummy->next = head;

    for (int i = 1; i < this->length; i++) {
        head->next = new nodes::ListNode(*(this->ary + i));
        head = head->next;
    }

    return dummy->next;
}

// Copy the array based on the index range, including the end pos.
int *
Array::copy(int *p_ary, unsigned int start, unsigned int end) {
    for (unsigned int i = start; i <= end; i++)
        *(p_ary + i) = *(this->ary + i);
    return p_ary;
}

}  // namespace dsa::lib::lists::arrays