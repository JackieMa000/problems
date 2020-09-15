#include "array.h"

namespace dsa::lib::lists::arrays {

Array::Array(int ary[], unsigned int length) : ary(ary), length(length)
{
}

nodes::ListNode*
Array::toSinglyLinkedList()
{
    auto* dummy = new nodes::ListNode();
    auto* head = new nodes::ListNode(*this->ary);
    dummy->next = head;

    for (int i = 1; i < this->length; i++)
    {
        head->next = new nodes::ListNode(*(this->ary + i));
        head = head->next;
    }

    return dummy->next;
}

// Copy the array based on the index range, including the end pos.
int*
Array::copy(int start, int end)
{
    int *ptr, res[end - start + 1];
    ptr = res;
    for (int i = start; i <= end; i++)
        *(ptr + i) = *(this->ary + i);
    return ptr;
}

}  // namespace dsa::lib::lists::arrays