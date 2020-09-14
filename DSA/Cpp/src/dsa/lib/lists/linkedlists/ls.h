#include "dsa/lib/lists/list.h"
#include "dsa/nodes.h"

#ifndef LIB_LISTS_LINKEDLISTS_LS_H
#define LIB_LISTS_LINKEDLISTS_LS_H

namespace dsa::lib::lists::linkedlists {

class LinkedList : List
{
protected:
    nodes::ListNode* head;

public:
    LinkedList(nodes::ListNode* head);

    int
    size() final;

    virtual int*
    toArray() final;

    virtual nodes::ListNode*
    getNodeByIndex(int idx) const final;

    void
    destroy();
};

}  // namespace dsa

#endif