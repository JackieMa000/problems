package strings

/**
* LeetCode72
* Dynamic Programming
* dp[i][j]: Represents the minimum number of operations required to convert first i chars of world1 to
* first j chars of word2, including word1[i] and word2[j].  word1[:i+1] to word2[:j+1].
 */
func minDistance(word1 string, word2 string) int {
	m, n := len(word1), len(word2)
	m1, n1 := m+1, n+1
	dp := createMatrix(m1, n1)

	// initialize dp table for dp[0][i] and dp[i][0]
	for i := 0; i < m1; i++ {
		dp[i][0] = i
	}
	for j := 0; j < n1; j++ {
		dp[0][j] = j
	}

	// Filling in the db table
	for i := 1; i < m1; i++ {
		for j := 1; j < n1; j++ {
			if word1[i-1] == word2[j-1] {
				dp[i][j] = dp[i-1][j-1]
			} else {
				dp[i][j] = 1 + min(dp[i][j-1], dp[i-1][j], dp[i-1][j-1])
			}
		}
	}

	return dp[m][n]
}

// Brutal Force. Redundant computation without caching.
func minDistance1(word1 string, word2 string) int {
	m, n := len(word1), len(word2)

	if m == 0 {
		return n
	} else if n == 0 {
		return m
	}

	if word1[0] == word2[0] {
		return minDistance1(word1[1:], word2[1:])
	}

	x := 1 + minDistance1(word1[1:], word2[1:])
	y := 1 + minDistance1(word1, word2[1:])
	z := 1 + minDistance1(word1[1:], word2)
	return min(x, y, z)
}

func min(ints ...int) int {
	r := ints[0]

	n := len(ints)
	for i := 1; i < n; i++ {
		if ints[i] < r {
			r = ints[i]
		}
	}

	return r
}

func createMatrix(m, n int) [][]int {
	s := make([][]int, m)
	for i := 0; i < m; i++ {
		s[i] = make([]int, n)
	}
	return s
}
