#include "dsa/nodes.h"
#include "list.h"

#ifndef LIB_LISTS_LINKEDLISTS_H
#define LIB_LISTS_LINKEDLISTS_H

namespace dsa {
namespace lib {
namespace lists {
namespace linkedlists {

class LinkedList : List
{
protected:
    nodes::ListNode* head;

public:
    LinkedList(nodes::ListNode* head);
    // virtual ~LinkedList();

    int
    size() final;

    virtual int*
    toArray() final;

    virtual nodes::ListNode*
    getNodeByIndex(int idx) const final;

    void
    destroy();
};

class SinglyLinkedList : public LinkedList
{
public:
    SinglyLinkedList(nodes::ListNode* head);
    // ~SinglyLinkedList();

    nodes::ListNode*
    reverse();
    
    nodes::ListNode*
    reverseBefore(nodes::ListNode* node);

    nodes::ListNode*
    reverseFromTo(nodes::ListNode* fnode, nodes::ListNode* tnode);

};

class DoublyLinkedList : public LinkedList
{
public:
    DoublyLinkedList(nodes::ListNode* head);
    // ~DoublyLinkedList();

    nodes::ListNode*
    reverse();
};

}  // namespace linkedlists
}  // namespace lists
}  // namespace lib
}  // namespace dsa

#endif  // LIB_LISTS_LINKEDLISTS_H