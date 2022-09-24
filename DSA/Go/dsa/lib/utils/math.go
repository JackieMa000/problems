package dsa

func CreateMatrix[T any](m, n int) [][]T {
	s := make([][]T, m)
	for i := range s {
		s[i] = make([]T, n)
	}
	return s
}
