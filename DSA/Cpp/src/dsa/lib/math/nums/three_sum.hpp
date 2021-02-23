#ifndef DSA_SRC_DSA_LIB_MATH_NUMS_THREE_SUM_HPP_
#define DSA_SRC_DSA_LIB_MATH_NUMS_THREE_SUM_HPP_
#include <vector>
#include <unordered_set>
namespace dsa::lib::math::nums {

//LeetCode15
class ThreeSum {
 public:
    static std::vector<std::vector<int> > threeSum(std::vector<int> &nums) {
        return threeSum2(nums);
    }

    /**
     * Rule: sortFind. Double Pointers
     * quickSort remove duplicates
     * remove duplicates for a
     * remove duplicates for b, c
     * sum = a + b + c
     *
     * quickSort(a)
     * loop a:
     *  remove duplicates for a
     *  double pointers for b, c
     *  left = i + 1, right = n - 1
     *  if sum > 0: right--
     *  if sum < 0: left++
     *  if sum == 0:
     *      1) remove duplicates for b, c
     *      2) save result
     *      3) left++, right--
     */
    static std::vector<std::vector<int> > threeSum1(std::vector<int> &nums) {
        const int n = nums.size();
        std::vector<std::vector<int> > result;

        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 2; i++) {
            if (i >= 1 && nums[i] == nums[i - 1]) { continue; }
            size_t left = i + 1, right = n - 1;
            while (left < right) {
                const int sum = nums[i] + nums[left] + nums[right];
                if (sum == 0) {
                    while (left < right && nums[left] == nums[left + 1]) { left++; }
                    while (left < right && nums[right] == nums[right - 1]) { right--; }
                    result.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    right--;
                } else if (sum > 0) { right--; }
                else { left++; }
            }
        }

        return result;
    }

    /**
     * Hash Table
     * a + b + c = target -> b = -(a + c)
     * Sort. Hash Table, remove duplicates from the result
     * Hash Set result for saving the result
     * Hash Set bSet for finding the result by b
     *
     * loop a:
     *  loop c:
     *      cur = c
     *      b = -(a + c)
     *      if b in bSet, save the result
     *      else, save cur to the bSet.
     */
    static std::vector<std::vector<int> > threeSum2(std::vector<int> &nums) {
        const int n = nums.size();
        std::vector<std::vector<int>> result;

        std::set<std::vector<int>> resultSet;
        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 2; ++i) {
            std::unordered_set<int> bSet;
            for (int j = i + 1; j < n; ++j) {
                auto b = -(nums[i] + nums[j]);
                if (bSet.find(b) != bSet.end()) {
                    resultSet.insert({nums[i], b, nums[j]});
                } else { bSet.insert(nums[j]); }
            }
        }
//        std::vector<std::vector<int>> result(resultSet.begin(), resultSet.end());
//        return result;
//        construct in place
        return *new(&result) std::vector<std::vector<int>>(resultSet.begin(), resultSet.end());
    }
};

}
#endif //DSA_SRC_DSA_LIB_MATH_NUMS_THREE_SUM_HPP_
