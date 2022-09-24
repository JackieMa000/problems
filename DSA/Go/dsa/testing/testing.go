package dsatest

import "testing"

func CheckEqual[T comparable](t *testing.T, want T, got T) {
	if got != want {
		t.Errorf("got = %v, want = %v", got, want)
	}
}
