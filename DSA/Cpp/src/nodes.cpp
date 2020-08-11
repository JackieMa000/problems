#include "nodes.h"

struct nodes::Node
{
    int val = 0;

    Node() {}
    Node(int val) { this->val = val; }
};

struct nodes::ListNode : nodes::Node
{
    ListNode *next;
    ListNode *next = nullptr;

    ListNode() : nodes::Node() {}
    ListNode(int val) : nodes::Node(val) {}
    ListNode(int val, ListNode *next)
    {
        this->val = val;
        this->next = next;
    }
};

struct nodes::TreeNode : nodes::Node
{
    TreeNode() : nodes::Node() {}
    TreeNode(int val) : nodes::Node(val) {}
};

struct nodes::BinaryTreeNode : nodes::TreeNode
{
    BinaryTreeNode *left, *right;
    BinaryTreeNode *left = nullptr, *right = nullptr;

    BinaryTreeNode() : nodes::TreeNode() {}
    BinaryTreeNode(int val) : nodes::TreeNode(val) {}
    BinaryTreeNode(int val, BinaryTreeNode *left, BinaryTreeNode *right)
    {
        this->val = val;
        this->left = left;
        this->right = right;
    }
};
