#include "nodes.h"
#include "lib/lists/lists.h"

#ifndef LIB_LISTS_ARRAYS_H
#define LIB_LISTS_ARRAYS_H

namespace lib
{
    class Array
    {
    private:
        const int *array;

    public:
        Array(int array[]);
        ~Array();

        nodes::ListNode toSinglyLinkedList();
        nodes::BinaryTreeNode toBinaryTree();
    };

    class ArrayList : List
    {
    private:
        static const int DEFAULT_LENGTH = 10;
        const int *lst;

    public:
        ArrayList();
        ArrayList(int array[]);
        ~ArrayList();

        int size();
    };

} // namespace lib

#endif