package dsa.lib.math.ds;

public class Matrix {
    /**
     * LeetCode74
     * Binary Search. Treat the matrix like a 1d-array.
     * O(logM*N)
     *
     * @param matrix
     * @param target
     * @return
     */
    public boolean searchMatrix(int[][] matrix, int target) {
        if (matrix.length == 0) return false;

        int m = matrix.length, n = matrix[0].length;
        int left = 0, right = m * n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int pivot = matrix[mid / n][mid % n];

            if (pivot == target) return true;
            else if (pivot < target) left = mid + 1;
            else right = mid - 1;
        }
        return false;
    }
}
