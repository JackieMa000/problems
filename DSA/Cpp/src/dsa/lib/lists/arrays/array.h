#ifndef LIB_LISTS_ARRAYS_H
#define LIB_LISTS_ARRAYS_H

#include "dsa/dsadef.h"
#include "dsa/nodes.h"

namespace dsa::lib::lists::arrays {

class Array {
 private:
    static void generateTreeFromArray(int *ary, length_t length, nodes::BinaryTreeNode *root, pos_t i);

 public:
    int *ary;
    length_t length;

    Array(int *ary, length_t length);
    [[nodiscard]] nodes::ListNode *toSinglyLinkedList() const;
    [[nodiscard]] nodes::BinaryTreeNode *toBinaryTree() const;

//    int *copy(int *p_ary, unsigned int start, unsigned int end);
};

}  // namespace dsa::lib::lists::arrays

#endif