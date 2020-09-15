#ifndef NODES_H
#define NODES_H

namespace dsa::nodes {

struct Node
{
    int val;

    Node();
    explicit Node(int val);
};

struct ListNode : Node
{
    ListNode* next;

    ListNode();
    explicit ListNode(int val);
    ListNode(int val, ListNode* next);
};

struct TreeNode : Node
{
    TreeNode();
    explicit TreeNode(int val);
};

struct BinaryTreeNode : TreeNode
{
    BinaryTreeNode *left, *right;

    BinaryTreeNode();
    explicit BinaryTreeNode(int val);
    BinaryTreeNode(int val, BinaryTreeNode* left, BinaryTreeNode* right);
};

}  // namespace dsa::nodes

#endif  // NODES_H