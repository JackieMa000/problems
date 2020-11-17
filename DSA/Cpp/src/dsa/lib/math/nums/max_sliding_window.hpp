#ifndef DSA_SRC_DSA_LIB_MATH_NUMS_MAX_SLIDING_WINDOW_HPP_
#define DSA_SRC_DSA_LIB_MATH_NUMS_MAX_SLIDING_WINDOW_HPP_

#include <vector>
#include <deque>
namespace dsa::lib::math::nums {

//LeetCode239
class MaxSlidingWindow {
 public:
    /**
     * Rule: Deque, Monotonic Queue
     * Monotonic: Stronger/Weaker ordering Queue
     */
    static std::vector<int> maxSlidingWindow(std::vector<int> &nums, int k) {
        std::vector<int> result;
        std::deque<int> deque;
        int windowLeftBound;
        for (int i = 0; i < nums.size(); ++i) {
            windowLeftBound = i - k + 1;
            if (!deque.empty() && deque.front() < windowLeftBound) { deque.pop_front(); }
            while (!deque.empty() && nums[deque.back()] < nums[i]) { deque.pop_back(); }
            deque.push_back(i);
            if (windowLeftBound >= 0) { result.push_back(nums[deque.front()]); }
        }
        return result;
    }
};

}

#endif //DSA_SRC_DSA_LIB_MATH_NUMS_MAX_SLIDING_WINDOW_HPP_
