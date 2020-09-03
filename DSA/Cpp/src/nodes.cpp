#include "nodes.h"

// FixMe: Redefination of nodes with nodes.h
namespace dsa
{
    namespace nodes
    {
        struct Node
        {
            int val = 0;

            Node() {}
            Node(int val) { this->val = val; }
        };

        struct ListNode : Node
        {
            ListNode *next;
            ListNode *next = nullptr;

            ListNode() : Node() {}
            ListNode(int val) : Node(val) {}
            ListNode(int val, ListNode *next)
            {
                this->val = val;
                this->next = next;
            }
        };

        struct TreeNode : Node
        {
            TreeNode() : Node() {}
            TreeNode(int val) : Node(val) {}
        };

        struct BinaryTreeNode : TreeNode
        {
            BinaryTreeNode *left, *right;
            BinaryTreeNode *left = nullptr, *right = nullptr;

            BinaryTreeNode() : TreeNode() {}
            BinaryTreeNode(int val) : TreeNode(val) {}
            BinaryTreeNode(int val, BinaryTreeNode *left, BinaryTreeNode *right)
            {
                this->val = val;
                this->left = left;
                this->right = right;
            }
        };
    } // namespace nodes
} // namespace dsa