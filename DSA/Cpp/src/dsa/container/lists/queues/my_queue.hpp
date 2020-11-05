#ifndef DSA_SRC_DSA_CONTAINER_LISTS_QUEUES_MY_QUEUE_HPP_
#define DSA_SRC_DSA_CONTAINER_LISTS_QUEUES_MY_QUEUE_HPP_

#include <stack>
namespace dsa::container::lists::queues {

template<typename T>
class MyQueue {
 private:
    std::stack<T> input, output;
 private:
//    Migrate the input stack elements to the output stack
    void migrate() {
        const int n = input.size();
        for (int i = 0; i < n; ++i) {
            output.push(input.top());
            input.pop();
        }

    }
 public:
    bool empty() {
        return input.empty() && output.empty();
    }
    void push(T x) {
        input.push(x);
    }
    T pop() {
        if (output.empty()) { migrate(); }
        T res = output.top();
        output.pop();
        return res;
    }
    int size() {
        return input.size() + output.size();
    }
    T peek() {
        if (output.empty()) { migrate(); }
        return output.top();
    }
    T front() {
        return this->peek();
    }
};

}

#endif //DSA_SRC_DSA_CONTAINER_LISTS_QUEUES_MY_QUEUE_HPP_
