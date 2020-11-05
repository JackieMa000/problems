#include <dsa/container/lists/queues/my_queue.hpp>
#include "queue_test.h"

namespace dsa::container::lists::queues {
namespace {

class MyQueueTest : public QueueTest {
 protected:
    MyQueue<int> queue;
};
TEST_F(MyQueueTest, emptyQueue) {
    EXPECT_TRUE(this->queue.empty());
}
TEST_F(MyQueueTest, pushNotEmpty) {
    this->queue.push(1);
    EXPECT_FALSE(this->queue.empty());
}
TEST_F(MyQueueTest, pushPopEmpty) {
    this->queue.push(1);
    EXPECT_EQ(1, queue.pop());
    EXPECT_TRUE(this->queue.empty());
}
TEST_F(MyQueueTest, pop) {
    this->queue.push(1);
    this->queue.push(2);
    EXPECT_EQ(1, queue.pop());
}
TEST_F(MyQueueTest, sizeEmpty) {
    EXPECT_EQ(0, queue.size());
}
TEST_F(MyQueueTest, pushSize) {
    queue.push(1);
    EXPECT_EQ(1, queue.size());
}
TEST_F(MyQueueTest, peek) {
    queue.push(1);
    queue.push(2);
    EXPECT_EQ(1, queue.peek());
}
TEST_F(MyQueueTest, front) {
    queue.push(1);
    queue.push(2);
    EXPECT_EQ(1, queue.front());
}

}
}
