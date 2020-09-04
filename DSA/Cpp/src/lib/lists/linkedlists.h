#include "nodes.h"
#include "lib/lists/lists.h"

#ifndef LIB_LISTS_LINKEDLISTS_H
#define LIB_LISTS_LINKEDLISTS_H

namespace dsa
{
    namespace lib
    {
        class LinkedList : List
        {
        protected:
            dsa::nodes::ListNode *head;

        public:
            LinkedList(dsa::nodes::ListNode *head);
            virtual ~LinkedList();

            int size() final;
            virtual int *toArray() final;
            virtual dsa::nodes::ListNode *getNodeByIndex(int idx) const final;

            virtual dsa::nodes::ListNode *reverse();
        };

        class SinglyLinkedList : LinkedList
        {
        public:
            SinglyLinkedList(dsa::nodes::ListNode *head);
            ~SinglyLinkedList();

            dsa::nodes::ListNode *reverse();
            dsa::nodes::ListNode *reverseBefore(dsa::nodes::ListNode *node);
            dsa::nodes::ListNode *reverseFromTo(dsa::nodes::ListNode *fnode, dsa::nodes::ListNode *tnode);
        };

        class DoublyLinkedList : LinkedList
        {
        public:
            DoublyLinkedList(dsa::nodes::ListNode *head);
            ~DoublyLinkedList();
        };

    } // namespace lib
} // namespace dsa

#endif // LIB_LISTS_LINKEDLISTS_H