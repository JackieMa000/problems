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
    explicit LinkedList(nodes::ListNode *head);

    length_t length() final;
    virtual std::tuple<length_t, int *> toArray() final;
    virtual nodes::ListNode *getNodeByIndex(int idx) const final;

    static void destroy(nodes::ListNode *head);
};

}  // namespace dsa::lib::lists::linkedlists

#endif