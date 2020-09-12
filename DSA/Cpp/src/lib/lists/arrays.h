#include "nodes.h"

#ifndef LIB_LISTS_ARRAYS_H
#define LIB_LISTS_ARRAYS_H

namespace dsa
{
    namespace lib
    {
        class Array
        {
        private:
            int *ary;

        public:
            unsigned int length;

            Array(int ary[], unsigned int length);
            // ~Array();

            nodes::ListNode *toSinglyLinkedList();
            nodes::BinaryTreeNode *toBinaryTree();
            int *copy(int start, int end);
        };

    } // namespace lib
} // namespace dsa

#endif