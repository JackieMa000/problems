#include "nodes.h"
#include "lib/lists/lists.h"

#ifndef LIB_LISTS_LINKEDLISTS_H
#define LIB_LISTS_LINKEDLISTS_H

namespace lib
{
    class LinkedList : List
    {
    public:
        nodes::ListNode *head;

        LinkedList(nodes::ListNode *head);
        virtual ~LinkedList();

        int size() final;
        virtual int *toArray() final;
        virtual nodes::ListNode *getNodeByIndex(int idx) const final;

        virtual nodes::ListNode *reverse();
    };

    class SinglyLinkedList : LinkedList
    {
    public:
        SinglyLinkedList(nodes::ListNode *head);
        ~SinglyLinkedList();

        nodes::ListNode *reverse();
        nodes::ListNode *reverseBefore(nodes::ListNode *node);
        nodes::ListNode *reverseFromTo(nodes::ListNode *fnode, nodes::ListNode *tnode);
    };

    class DoublyLinkedList : LinkedList
    {
    public:
        DoublyLinkedList(nodes::ListNode *head);
        ~DoublyLinkedList();
    };

} // namespace lib

#endif // LIB_LISTS_LINKEDLISTS_H