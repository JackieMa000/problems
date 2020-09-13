#include "ls.h"

#ifndef LIB_LISTS_LINKEDLISTS_DLS_H
#define LIB_LISTS_LINKEDLISTS_DLS_H

namespace dsa {
namespace lib {
namespace lists {
namespace linkedlists {

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

#endif