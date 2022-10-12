package ds

import (
	dsa "dsa/lib/utils"
	"math"
)

// LeetCode120
// dfs. Redundant computation
func minimumTotal(triangle [][]int) int {
	return dfs(triangle, 0, 0)
}

func dfs(triangle [][]int, i int, j int) int {
	if i >= len(triangle) {
		return 0
	}

	downLeft := dfs(triangle, i+1, j)
	downRight := dfs(triangle, i+1, j+1)
	return triangle[i][j] + dsa.Min(downLeft, downRight)
}

// dfs with memorization
func minimumTotal1(triangle [][]int) int {
	m := len(triangle)
	memo := dsa.CreateMatrix[int](m, m)
	dsa.FillMatrix(memo, math.MinInt)

	return dfs1(triangle, 0, 0, memo)
}

func dfs1(triangle [][]int, i int, j int, memo [][]int) int {
	if i >= len(triangle) {
		return 0
	}

	if memo[i][j] != math.MinInt {
		return memo[i][j]
	}

	downLeft := dfs(triangle, i+1, j)
	downRight := dfs(triangle, i+1, j+1)
	memo[i][j] = triangle[i][j] + dsa.Min(downLeft, downRight)

	return memo[i][j]
}

// Dynamic Programming. Bottom up
func minimumTotal2(triangle [][]int) int {
	m := len(triangle)
	dp := dsa.CreateMatrix[int](m, m)

	// dp initialize
	copy(dp[m-1], triangle[m-1])

	// dp formula
	for i := m - 2; i >= 0; i-- {
		n := len(triangle[i])
		for j := 0; j < n; j++ {
			dp[i][j] = triangle[i][j] + dsa.Min(dp[i+1][j], dp[i+1][j+1])
		}
	}

	// result
	return dp[0][0]
}

// Dynamic Programming. Bottom up. Space Optimized
func minimumTotal3(triangle [][]int) int {
	m := len(triangle)
	dp := make([]int, m)

	// dp initialize
	copy(dp, triangle[m-1])

	// dp formula
	for i := m - 2; i >= 0; i-- {
		n := len(triangle[i])
		for j := 0; j < n; j++ {
			dp[j] = triangle[i][j] + dsa.Min(dp[j], dp[j+1])
		}
	}

	// result
	return dp[0]
}
