#include "ls.h"

namespace dsa::lib::lists::linkedlists {

LinkedList::LinkedList(nodes::ListNode* head) : head(head)
{
}

void
LinkedList::destroy()
{
    nodes::ListNode *cur, *next;
    cur = this->head;
    while (cur)
    {
        next = cur->next;
        delete cur;
        cur = next;
    }
};

int
LinkedList::size()
{
    // ToDo
    return 0;
};

int*
LinkedList::toArray()
{
    // ToDo
    int* res;
    return res;
}

nodes::ListNode*
LinkedList::getNodeByIndex(int idx) const
{
    // ToDo
    nodes::ListNode* ls;
    return ls;
}

}  // namespace dsa::lib::lists::linkedlists
