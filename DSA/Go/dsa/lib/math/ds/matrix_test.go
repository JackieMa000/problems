package ds

import (
	dsatest "dsa/testing"
	"testing"
)

func TestSearchMatrix_empty(t *testing.T) {
	dsatest.CheckFalse(searchMatrix([][]int{{}}, 1), t)
}

func TestSearchMatrix_oneElement(t *testing.T) {
	dsatest.CheckFalse(searchMatrix([][]int{{1}}, 3), t)
	dsatest.CheckTrue(searchMatrix([][]int{{1}}, 1), t)
}

func TestSearchMatrix_case1(t *testing.T) {
	dsatest.CheckTrue(searchMatrix([][]int{
		{1, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 10, 11, 12}}, 3), t)
	dsatest.CheckTrue(searchMatrix([][]int{
		{1, 3, 5, 7},
		{10, 11, 16, 20},
		{23, 30, 34, 50}}, 5), t)
	dsatest.CheckTrue(searchMatrix([][]int{
		{1, 3, 5, 7},
		{10, 11, 16, 20},
		{23, 30, 34, 50}}, 3), t)
	dsatest.CheckFalse(searchMatrix([][]int{
		{1, 3, 5, 7},
		{10, 11, 16, 20},
		{23, 30, 34, 50}}, 13), t)
}
