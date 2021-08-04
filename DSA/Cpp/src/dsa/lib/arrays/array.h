#ifndef LIB_LISTS_ARRAYS_H
#define LIB_LISTS_ARRAYS_H

#include <dsa/config.h>
#include "dsa/lib/libdef.h"
#include "dsa/nodes/nodes.h"

namespace dsa::lib::arrays {

class Array {
 private:
    static void generateTreeFromArray(int *ary, length_t length, BinaryTreeNode *root, pos_t i);

 public:
    int *ary;
    length_t length;

    Array(int *ary, length_t length);
    NODISCARD ListNode *toSinglyLinkedList() const;
    NODISCARD BinaryTreeNode *toBinaryTree() const;
    /**
     * To represent a cycle in the given linked list, we use an integer pos which represents
     * the position (0-indexed) in the linked list where tail connects to. If pos is -1, then
     * there is no cycle in the linked list.
     */
    NODISCARD ListNode *toCyclicSinglyLinkedList(int pos) const;
};

}  // namespace dsa::lib::arrays

#endif