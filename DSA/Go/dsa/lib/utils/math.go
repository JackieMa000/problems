package dsa

func CreateMatrix[T any](m, n int) [][]T {
	matrix := make([][]T, m)
	for i := range matrix {
		matrix[i] = make([]T, n)
	}
	return matrix
}

func FillMatrix[T any](m [][]T, v T) {
	for i := range m {
		for j := range m[i] {
			m[i][j] = v
		}
	}
}
