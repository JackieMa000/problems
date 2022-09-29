package strings

import (
	"dsa/testing"
	"log"
	"testing"
)

func TestEditDistance_emptyString(t *testing.T) {
	dsatest.CheckEqual(0, getDistance("", ""), t)
	dsatest.CheckEqual(1, getDistance("", "a"), t)
	dsatest.CheckEqual(1, getDistance("a", ""), t)
}

func TestEditDistance_equalString(t *testing.T) {
	dsatest.CheckEqual(0, getDistance("abc", "abc"), t)
}

func TestEditDistance_case1(t *testing.T) {
	dsatest.CheckEqual(3, getDistance("horse", "ros"), t)
	dsatest.CheckEqual(5, getDistance("intention", "execution"), t)
}

func getDistance(w1, w2 string) int {
	r1 := minDistance(w1, w2)
	r2 := minDistance1(w1, w2)
	if r1 != r2 {
		log.Panicln("Results from 2 same functions are different.")
	}

	return r1
}
