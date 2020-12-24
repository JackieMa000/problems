package experiment.isValidBST;

import dsa.nodes.BinaryTreeNode;

// Java make copy of parameter object, prev here will be a copy object, so this solution doesn't work.
public class Scratch {
    //BinaryTreeNode prev should be global scope, need to change the prev value in the subroutine(callee) for the parent routine(caller)

    public boolean isValidBST(BinaryTreeNode root) {
        BinaryTreeNode prev = null; // initial value for the left subTree
        return isValid(root, prev);
    }

    //    Cause java would make a copy of the parameter object, not like what c++ could do with lvalue.
//    prev here is a copy, not a single global object, so this solution does not work.
    public boolean isValid(BinaryTreeNode cur, BinaryTreeNode prev) {
        // Terminator
        if (cur == null) return true;

//        Left subTree. Recursive Case
        if (!isValid(cur.left, prev)) return false;

//       Back. Process or Condition
        if (prev != null && prev.val >= cur.val) return false;

//        Right subTree, recursive case. drill down
        prev = cur; // prev value for the right subTree
        return isValid(cur.right, prev);
    }
}
