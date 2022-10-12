package ds

import (
	dsatest "dsa/testing"
	"log"
	"testing"
)

func TestMinimumTotal(t *testing.T) {
	dsatest.CheckEqual(11, minTotal([][]int{{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}}), t)
	dsatest.CheckEqual(-10, minTotal([][]int{{-10}}), t)
}

func minTotal(triangle [][]int) int {
	r := minimumTotal(triangle)
	r1 := minimumTotal1(triangle)
	r2 := minimumTotal2(triangle)
	r3 := minimumTotal3(triangle)
	if r != r1 && r != r2 && r != r3 {
		log.Panicln("Results from multiple same functions are different.")
	}

	return r
}
