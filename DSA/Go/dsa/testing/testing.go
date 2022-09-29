package dsatest

import "testing"

func CheckEqual[T comparable](want T, got T, t *testing.T) {
	if got != want {
		t.Errorf("got = %v, want = %v", got, want)
	}
}

func CheckTrue(got bool, t *testing.T) {
	CheckEqual(true, got, t)
}

func CheckFalse(got bool, t *testing.T) {
	CheckEqual(false, got, t)
}
