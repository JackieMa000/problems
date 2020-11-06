#pragma once

#include <queue>
#include <dsa/dsadef.h>

namespace dsa::container::lists::queues {

//LeetCode225
template<typename T>
class MyStack {
 private:
    std::queue<T> queue;

 public:
    void push(T x) {
        queue.push(x);
        invertQueue(this->queue);
    }

//    Removes the element on top of the stack and returns that element.
    T pop() {
        auto res = queue.front();
        queue.pop();
        return res;
    }

    T top() {
        return queue.front();
    }

    T peek() {
        return this->top();
    }

    bool empty() {
        return queue.empty();
    }

    length_t size() {
        return queue.size();
    }

 private:
    static void invertQueue(std::queue<T> &queue) {
        for (int i = 0, n = queue.size(); i < n - 1; ++i) {
            queue.push(queue.front());
            queue.pop();
        }
    }
};

}