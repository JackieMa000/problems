#include "dsa/nodes.h"

#ifndef LIB_LISTS_ARRAYS_H
#define LIB_LISTS_ARRAYS_H

namespace dsa::lib::lists::arrays {

class Array
{
private:
    int* ary;

public:
    unsigned int length;

    Array(int ary[], unsigned int length);

    nodes::ListNode *
    toSinglyLinkedList();

    nodes::BinaryTreeNode*
    toBinaryTree();

    int *
    copy(int *p_ary, unsigned int start, unsigned int end);
};

}  // namespace dsa::lib::lists::arrays

#endif