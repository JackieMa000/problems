#ifndef LIB_LISTS_LINKEDLISTS_LS_H
#define LIB_LISTS_LINKEDLISTS_LS_H

#include <tuple>
#include <dsa/lib/lists/list.h>
#include <dsa/nodes.h>

namespace dsa::lib::lists::linkedlists {

class LinkedList : public List {
 protected:
    nodes::ListNode *head;

 public:
    LinkedList(nodes::ListNode *head);

    unsigned int
    size() final;

    virtual std::tuple<unsigned int, int *>
    toArray() final;

    virtual nodes::ListNode *
    getNodeByIndex(int idx) const final;

    void
    destroy();
};

}  // namespace dsa::lib::lists::linkedlists

#endif