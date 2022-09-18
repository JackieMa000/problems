package dsa

func CreateMatrix(n int) [][]bool {
	s := make([][]bool, n)
	for i := range s {
		s[i] = make([]bool, n)
	}
	return s
}
