#pragma once

#include <vector>

class Matrix {
 public:
    /**
     * LeetCode74
     * Binary Search. Treat the matrix like a 1d-array.
     * O(logM*N)
     *
     * @param matrix
     * @param target
     * @return
     */
    bool searchMatrix(std::vector<std::vector<int>> &matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;

        int m = matrix.size(), n = matrix[0].size();
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

};