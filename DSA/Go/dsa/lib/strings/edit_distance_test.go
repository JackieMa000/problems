package strings

import (
	"dsa/testing"
	"log"
	"testing"
)

func TestEditDistance_emptyString(t *testing.T) {
	dsatest.CheckEqual(t, 0, getDistance("", ""))
	dsatest.CheckEqual(t, 1, getDistance("", "a"))
	dsatest.CheckEqual(t, 1, getDistance("a", ""))
}

func TestEditDistance_equalString(t *testing.T) {
	dsatest.CheckEqual(t, 0, getDistance("abc", "abc"))
}

func TestEditDistance_case1(t *testing.T) {
	dsatest.CheckEqual(t, 3, getDistance("horse", "ros"))
	dsatest.CheckEqual(t, 5, getDistance("intention", "execution"))
}

func getDistance(w1, w2 string) int {
	r1 := minDistance(w1, w2)
	r2 := minDistance1(w1, w2)
	if r1 != r2 {
		log.Panicln("Results from 2 same functions are different.")
	}

	return r1
}
