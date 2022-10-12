package dsa

func Max(nums ...int) int {
	max := nums[0]

	n := len(nums)
	for i := 1; i < n; i++ {
		if nums[i] > max {
			max = nums[i]
		}
	}

	return max
}

func Min(nums ...int) int {
	min := nums[0]

	n := len(nums)
	for i := 1; i < n; i++ {
		if nums[i] < min {
			min = nums[i]
		}
	}

	return min
}

// Fill in a slice with a value
func Fill[T any](s []T, v T) {
	for i := range s {
		s[i] = v
	}
}
