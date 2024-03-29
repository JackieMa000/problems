package ds

/**
 * LeetCode74
 * Binary Search. Treat the matrix like a 1d-array.
 * O(logM*N)
 */
func searchMatrix(matrix [][]int, target int) bool {
	if len(matrix) == 0 {
		return false
	}

	m, n := len(matrix), len(matrix[0])
	left, right := 0, m*n-1
	for left <= right {
		mid := left + (right-left)/2
		pivot := matrix[mid/n][mid%n]

		if pivot == target {
			return true
		} else if pivot < target {
			left = mid + 1
		} else {
			right = mid - 1
		}
	}
	return false
}
