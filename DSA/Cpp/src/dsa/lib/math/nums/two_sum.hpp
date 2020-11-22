#ifndef DSA_SRC_DSA_LIB_MATH_NUMS_TWO_SUM_HPP_
#define DSA_SRC_DSA_LIB_MATH_NUMS_TWO_SUM_HPP_
#include <vector>
#include <unordered_map>
namespace dsa::lib::math::nums {


/**
 * Rule: Hash Table
 * mapNums: {num: index_of_num}
 * x + y = target -> x = target - y
 * loop through nums
 * cur = y
 * generate the hash table for x
 * try to find x in hash table:
 *  1) found, return {index_x, index_y}
 *  2) not found, save cur(y) to the hash table
 * default return {}
 */
//LeetCode1
class TwoSum {
 public:
    static std::vector<int> twoSum(std::vector<int> &nums, int target) {
        std::unordered_map<int, int> mapNums;
        for (int i = 0; i < nums.size(); ++i) {
            auto found = mapNums.find(target - nums[i]);
            if (found != mapNums.end()) { return {found->second, i}; }
            mapNums[nums[i]] = i;
        }
        return {};
    }
};

}
#endif //DSA_SRC_DSA_LIB_MATH_NUMS_TWO_SUM_HPP_
