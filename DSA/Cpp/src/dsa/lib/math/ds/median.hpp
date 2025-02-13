#pragma once

namespace dsa::lib::math::ds {

class Median {
 public:
    // LeetCode4
    double findMedianSortedArrays(std::vector<int> &nums1, std::vector<int> &nums2) {
//        merge two sorted arrays
        std::vector<int> mergedArray = merge(nums1, nums2);

//        pick the result
        int n = mergedArray.size();
        bool isOdd = n & 1;
        int mid = n / 2;

        return isOdd ? mergedArray[mid] : (mergedArray[mid - 1] + mergedArray[mid]) / 2.0;
    }

    std::vector<int> merge(std::vector<int> &nums1, std::vector<int> &nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        int n = n1 + n2;
        std::vector<int> nums(n);

//        populate the merged array by comparison
        int i = 0, i1 = 0, i2 = 0;
        while (i1 < n1 && i2 < n2) {
            if (nums1[i1] <= nums2[i2]) nums[i++] = nums1[i1++];
            else nums[i++] = nums2[i2++];
        }

//        merged array is not full populated.
        if (i < n) {
//          nums1 is not done
            while (i1 < n1) nums[i++] = nums1[i1++];;
//          nums2 is not done
            while (i2 < n2) nums[i++] = nums2[i2++];
        }

        return nums;
    }
};

}
