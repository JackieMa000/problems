package isValidBST;

import lib.lists.arrays.Array;
import org.junit.Before;
import org.junit.Test;

import static org.junit.Assert.*;

public class Scratch1Test {

    private Scratch1 solution;

    @Before
    public void setUp() {
        solution = new Scratch1();
    }

    @Test
    public void case1() {
        assertTrue(solution.isValidBST(new Array(new int[]{3, 1, 5, 0, 2}).toBinaryTree()));
    }

    @Test
    public void case2() {
        assertTrue(solution.isValidBST(new Array(new int[]{5, 1, 8, 0, 2, 6, 9}).toBinaryTree()));
    }

    @Test
    public void case3() {
        assertTrue(solution.isValidBST(new Array(new int[]{5, 1, 6, -3, 2, 0, 7}).toBinaryTree()));
    }

    @Test
    public void case4() {
        assertFalse(solution.isValidBST(new Array(new int[]{5, 1, 4, 0, 6, 3, 6}).toBinaryTree()));
    }

    @Test
    public void case5() {
        assertFalse(solution.isValidBST(new Array(new int[]{1, 1}).toBinaryTree()));
    }
}