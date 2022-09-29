package dsa.lib.math.ds;

import org.junit.Test;

import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertTrue;

public class MatrixTest {
    public static class SearchMatrixTest {
        private static boolean searchMatrix(int[][] matrix, int target) {
            return new Matrix().searchMatrix(matrix, target);
        }

        @Test
        public void empty() {
            assertFalse(searchMatrix(new int[][]{}, 1));
        }

        @Test
        public void oneElement() {
            assertFalse(searchMatrix(new int[][]{new int[]{1}}, 3));
            assertTrue(searchMatrix(new int[][]{new int[]{1}}, 1));
        }

        @Test
        public void case1() {
            assertTrue(searchMatrix(new int[][]{
                    new int[]{1, 2, 3, 4},
                    new int[]{5, 6, 7, 8},
                    new int[]{9, 10, 11, 12}}, 3));
            assertTrue(searchMatrix(new int[][]{
                    new int[]{1, 3, 5, 7},
                    new int[]{10, 11, 16, 20},
                    new int[]{23, 30, 34, 50}}, 5));
            assertTrue(searchMatrix(new int[][]{
                    new int[]{1, 3, 5, 7},
                    new int[]{10, 11, 16, 20},
                    new int[]{23, 30, 34, 50}}, 3));
            assertFalse(searchMatrix(new int[][]{
                    new int[]{1, 3, 5, 7},
                    new int[]{10, 11, 16, 20},
                    new int[]{23, 30, 34, 50}}, 13));
        }
    }

}