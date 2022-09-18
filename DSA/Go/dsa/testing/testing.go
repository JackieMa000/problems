package dsatest

import "testing"

func CheckStrEqual(t *testing.T, want string, got string) {
	if got != want {
		t.Errorf("got = %s, want = %s", got, want)
	}
}

func CheckIntEqual(t *testing.T, want int, got int) {
	if got != want {
		t.Errorf("got = %d, want = %d", got, want)
	}
}
