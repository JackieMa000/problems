package experiment.isValidBST;

import org.junit.Test;

import static dsa.lib.LibTestFX.arrayToBinaryTree;
import static org.junit.Assert.*;

public class Solution1Test {
    @Test
    public void emptyTree() {
        assertTrue(isValid(new int[]{}));
    }

    @Test
    public void oneNode() {
        assertTrue(isValid(new int[]{1}));
    }

    @Test
    public void notBST() {
        assertFalse(isValid(new int[]{1, 1}));
        assertFalse(isValid(new int[]{2, 4, 5}));
        assertFalse(isValid(new int[]{5, 1, 4, 0, 6, 3, 6}));
    }

    @Test
    public void isBST() {
        assertTrue(isValid(new int[]{3, 1, 5, 0, 2}));
        assertTrue(isValid(new int[]{5, 1, 8, 0, 2, 6, 9}));
        assertTrue(isValid(new int[]{5, 1, 6, -3, 2, 0, 7}));
        assertTrue(isValid(new int[]{5, 3, 9, 1, 4, 8, 15}));
    }

    private boolean isValid(int[] ary) {
        return new Solution1().isValidBST(arrayToBinaryTree(ary));
    }
}