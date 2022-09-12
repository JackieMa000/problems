package sortedarrays

import "testing"

func TestFindMedianSortedArrays(t *testing.T) {
	checkMedian(t, median([]int{1, 3}, []int{2}), 2.0)
	checkMedian(t, median([]int{1, 2}, []int{3, 4}), 2.5)
}

func checkMedian(t *testing.T, got float64, want float64) {
	if got != want {
		t.Errorf("Median = %.1f, want %.1f", got, want)
	}
}

func median(nums1 []int, nums2 []int) float64 {
	return findMedianSortedArrays(nums1, nums2)
}
