#include "nodes.h"
#include "lib/lists/linkedlists.h"

namespace dsa
{
    namespace lib
    {
        LinkedList::LinkedList(nodes::ListNode *head) { this->head = head; }
        LinkedList::~LinkedList()
        {
            nodes::ListNode *cur, *next;
            cur = head;
            while (!cur)
            {
                next = cur->next;
                delete cur;
                cur = next;
            }
        };

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

        DoublyLinkedList::DoublyLinkedList(nodes::ListNode *head) : LinkedList(head){};

    } // namespace lib
} // namespace dsa