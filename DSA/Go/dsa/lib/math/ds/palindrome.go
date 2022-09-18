package ds

/**
* LeetCode5
* Dynamic Programming
* dp[i][j] represents whether it's palindrome from i to j(including a[j])
* s[i] ==s[j] and (dp[i+1][j-1] or j -i < 3) => dp[i][j]
 */
func longestPalindrome(s string) string {
	n := len(s)
	if n <= 1 {
		return s
	}

	// Filling in dp table and get the range of the longest palindrome substring.
	start := 0
	end := 0
	dp := createMatrix(n)
	for i := n - 1; i >= 0; i-- {
		for j := i; j < n; j++ {
			dp[i][j] = s[i] == s[j] && (j-i < 3 || dp[i+1][j-1])

			if dp[i][j] && j-i > end-start {
				start = i
				end = j
			}
		}
	}
	return s[start : end+1]
}

func createMatrix(n int) [][]bool {
	s := make([][]bool, n)
	for i := range s {
		s[i] = make([]bool, n)
	}
	return s
}

/**
* Expand around center
* O(n^2), Constant Space
 */
func longestPalindrome1(s string) string {
	n := len(s)
	if n <= 1 {
		return s
	}

	start := 0
	end := 0
	for i := 0; i < n; i++ {
		lenOdd := expandAroundCenter(s, i, i)
		lenEven := expandAroundCenter(s, i, i+1)
		lenMax := max(lenOdd, lenEven)

		if lenMax > end-start+1 {
			start = i - (lenMax-1)/2
			end = i + lenMax/2
		}
	}

	return s[start : end+1]
}

func expandAroundCenter(s string, left int, right int) int {
	for left >= 0 && right < len(s) && s[left] == s[right] {
		left--
		right++
	}
	return right - left - 1
}

func max(a, b int) int {
	if a >= b {
		return a
	}
	return b
}
