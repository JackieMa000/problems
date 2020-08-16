#include "nodes.h"
#include "lib/lists/linkedlists.h"

lib::LinkedList::LinkedList(nodes::ListNode *head) { this->head = head; }
lib::LinkedList::~LinkedList()
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

lib::SinglyLinkedList::SinglyLinkedList(nodes::ListNode *head) : LinkedList(head){};

// reverse the nodes before a certain node
nodes::ListNode *lib::SinglyLinkedList::reverseBefore(nodes::ListNode *node)
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

lib::DoublyLinkedList::DoublyLinkedList(nodes::ListNode *head) : LinkedList(head){};