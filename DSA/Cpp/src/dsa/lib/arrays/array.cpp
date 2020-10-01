#include "array.h"

namespace dsa::lib::arrays {

Array::Array(int *ary, length_t length) : ary(ary), length(length) {}

ListNode *Array::toSinglyLinkedList() const {
    nodes::ListNode dummy;
    auto *head = new nodes::ListNode(*this->ary);
    dummy.next = head;

    for (int i = 1; i < this->length; i++) {
        head->next = new nodes::ListNode(*(this->ary + i));
        head = head->next;
    }

    return dummy.next;
}

BinaryTreeNode *Array::toBinaryTree() const {
    auto *root = new nodes::BinaryTreeNode(*this->ary);
    generateTreeFromArray(this->ary, this->length, root, 0);
    return root;
}
void Array::generateTreeFromArray(int *ary, length_t length, BinaryTreeNode *root, pos_t i) {
    pos_t lpos = 2 * i + 1, rpos = 2 * i + 2;
    if (lpos < length && *(ary + lpos) != 0) {
        root->left = new nodes::BinaryTreeNode(*(ary + lpos));
        generateTreeFromArray(ary, length, root->left, lpos);
    }
    if (rpos < length && *(ary + rpos) != 0) {
        root->right = new nodes::BinaryTreeNode(*(ary + rpos));
        generateTreeFromArray(ary, length, root->right, rpos);
    }
}

/**
 * Remove all the trailing 0s from an array
 * Rule:
 * 1. array length is 0 -> return empty array
 * 2. array length is 1, the element is 0 -> return empty array
 * 3. array last element is not 0 -> return array
 * 4. array length is bigger than 1, last element is 0 -> remove the trailing 0s by loop
 */
length_t rStrip(const int *ary, length_t length) {
    if (!length || (length == 1 && *(ary) == 0)) return 0;
    if (*(ary + (length - 1)) != 0) return length;

    auto newLength = length - 1;
    while (newLength > 0 && *(ary + (newLength - 1)) == 0) newLength--;
    return newLength;
}

}  // namespace dsa::lib::arrays