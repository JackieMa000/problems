#ifndef LIB_LISTS_ARRAYS_H
#define LIB_LISTS_ARRAYS_H

#include "dsa/nodes.h"

namespace dsa::lib::lists::arrays {

class Array {
 private:
    int *ary;
    static void generateTreeFromArray(int *ary, unsigned int length, nodes::BinaryTreeNode *root, unsigned int i);

 public:
    unsigned int length;

    Array(int *ary, unsigned long size);

    nodes::ListNode *toSinglyLinkedList();
    nodes::BinaryTreeNode *toBinaryTree();

    int *copy(int *p_ary, unsigned int start, unsigned int end);
};

}  // namespace dsa::lib::lists::arrays

#endif