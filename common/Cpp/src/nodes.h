#ifndef NODES_H
#define NODES_H

namespace nodes
{
    struct Node
    {
        int val;

        Node();
        Node(int val);
    };

    struct ListNode : Node
    {
        ListNode *next;

        ListNode();
        ListNode(int val);
        ListNode(int val, ListNode *next);
    };

    struct TreeNode : Node
    {
        TreeNode();
        TreeNode(int val);
    };

    struct BinaryTreeNode : TreeNode
    {
        BinaryTreeNode *left, *right;

        BinaryTreeNode();
        BinaryTreeNode(int val);
        BinaryTreeNode(int val, ListNode *left, ListNode *right);
    };

} // namespace nodes

#endif // NODES_H