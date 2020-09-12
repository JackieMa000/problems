#include "nodes.h"
#include "lib/lists/linkedlists.h"

namespace dsa
{
    namespace lib
    {
        LinkedList::LinkedList(nodes::ListNode *head) : head(head) {}
        void LinkedList::destroy()
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
        int LinkedList::size()
        {
            // ToDo
            return 0;
        };

        int *LinkedList::toArray()
        {
            // ToDo
            int *res;
            return res;
        }
        nodes::ListNode *LinkedList::getNodeByIndex(int idx) const {
            // ToDo
            nodes::ListNode *ls;
            return ls;
        }

        SinglyLinkedList::SinglyLinkedList(nodes::ListNode *head) : LinkedList(head){};

        // reverse the nodes before a certain node
        nodes::ListNode *SinglyLinkedList::reverseBefore(nodes::ListNode *node)
        {
            nodes::ListNode *pre, *cur, *next;
            pre = node;
            cur = this->head;

            while (cur != node)
            {
                next = cur->next;
                cur->next = pre;
                pre = cur;
                cur = next;
            }
            return pre;
        };

        nodes::ListNode *SinglyLinkedList::reverse()
        {
            nodes::ListNode *pre, *cur, *next;
            cur = this->head;

            while (cur)
            {
                next = cur->next;
                cur->next = pre;
                pre = cur;
                cur = next;
            }
            return pre;
        }

        // DoublyLinkedList::DoublyLinkedList(nodes::ListNode *head) : LinkedList(head){};

    } // namespace lib
} // namespace dsa