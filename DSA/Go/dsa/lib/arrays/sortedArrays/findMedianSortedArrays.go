package sortedarrays

// LeetCode4
func findMedianSortedArrays(nums1 []int, nums2 []int) float64 {
	nums := merge(nums1, nums2)

	n := len(nums)
	is_odd := (n&1 == 1)
	if is_odd {
		return float64(nums[n/2])
	} else {
		return float64((nums[(n-1)/2] + nums[n/2])) / 2.0
	}
}

func merge(nums1 []int, nums2 []int) []int {
	n1, n2 := len(nums1), len(nums2)
	n := n1 + n2

	nums := make([]int, n)
	i := 0
	i1, i2 := 0, 0

	for i1 < n1 && i2 < n2 {
		if nums1[i1] < nums2[i2] {
			nums[i] = nums1[i1]
			i1++
		} else {
			nums[i] = nums2[i2]
			i2++
		}
		i++
	}

	if i < n {
		for i1 < n1 {
			nums[i] = nums1[i1]
			i++
			i1++
		}
		for i2 < n2 {
			nums[i] = nums2[i2]
			i++
			i2++
		}
	}

	return nums
}
