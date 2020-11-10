#ifndef DSA_SRC_DSA_LIB_MATH_NUMS_KTHLARGEST_HPP_
#define DSA_SRC_DSA_LIB_MATH_NUMS_KTHLARGEST_HPP_

#include <queue>
namespace dsa::lib::math::nums {

//LeetCode703
class KthLargest {
 private:
    std::priority_queue<int, std::vector<int>, std::greater<>> queue;
    int k;

 public:
    KthLargest(int k, std::vector<int> &nums) {
        this->k = k;
        for (int &num : nums) { add(num); }
    }

    int add(int val) {
        queue.push(val);
        if (queue.size() > this->k) queue.pop();
        return queue.top();
    }
};

}
#endif //DSA_SRC_DSA_LIB_MATH_NUMS_KTHLARGEST_HPP_
