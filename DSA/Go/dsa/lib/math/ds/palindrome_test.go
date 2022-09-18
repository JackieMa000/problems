package ds

import (
	"log"
	"testing"
)

func TestLongestPalindrome_emptyString(t *testing.T) {
	checkLongestPalindrome(getLongestPalindrome(""), "", t)
}

func TestLongestPalindrome_oneChar(t *testing.T) {
	checkLongestPalindrome(getLongestPalindrome("a"), "a", t)
}

func TestLongestPalindrome_case1(t *testing.T) {
	checkLongestPalindrome("aa", getLongestPalindrome("aa"), t)
	checkLongestPalindrome("bab", getLongestPalindrome("babd"), t)
	checkLongestPalindrome("bb", getLongestPalindrome("cbbd"), t)
	checkLongestPalindrome("aaaa", getLongestPalindrome("aaaa"), t)
}

func checkLongestPalindrome(want string, got string, t *testing.T) {
	if got != want {
		t.Errorf("getLongestPalindrome = %s, want = %s", got, want)
	}
}

func getLongestPalindrome(s string) string {
	r1 := longestPalindrome(s)
	r2 := longestPalindrome1(s)
	if r1 != r2 {
		log.Panicln("Results from 2 same functions are different.")
	}

	return r1
}
