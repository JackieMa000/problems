#ifndef LIB_LISTS_ARRAYS_H
#define LIB_LISTS_ARRAYS_H

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
    [[nodiscard]] ListNode *toSinglyLinkedList() const;
    [[nodiscard]] BinaryTreeNode *toBinaryTree() const;

};

length_t rStrip(const int *ary, length_t length);

}  // namespace dsa::lib::arrays

#endif