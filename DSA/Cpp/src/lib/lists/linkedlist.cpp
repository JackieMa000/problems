#include "nodes.h"
#include "lib/lists/linkedlists.h"

lib::LinkedList::LinkedList(dsa::nodes::ListNode *head) { this->head = head; }
lib::LinkedList::~LinkedList()
{
    dsa::nodes::ListNode *cur, *next;
    cur = head;
    while (!cur)
    {
        next = cur->next;
        delete cur;
        cur = next;
    }
};

lib::SinglyLinkedList::SinglyLinkedList(dsa::nodes::ListNode *head) : LinkedList(head){};

// reverse the nodes before a certain node
dsa::nodes::ListNode *lib::SinglyLinkedList::reverseBefore(dsa::nodes::ListNode *node)
{
    dsa::nodes::ListNode *pre, *cur, *next;
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

lib::DoublyLinkedList::DoublyLinkedList(dsa::nodes::ListNode *head) : LinkedList(head){};