#include "queue_test.h"
#include <dsa/container/lists/queues/my_stack.hpp>

namespace dsa::container::lists::queues {
namespace {

class MyStackTest : public QueueTest {
 protected:
    MyStack<int> stack;
};
TEST_F(MyStackTest, emptyStack) {
    EXPECT_TRUE(stack.empty());
}
TEST_F(MyStackTest, pushNotEmpty) {
    stack.push(1);
    EXPECT_FALSE(stack.empty());
}
TEST_F(MyStackTest, sizeEmpty) {
    EXPECT_EQ(0, stack.size());
}
TEST_F(MyStackTest, pushSize) {
    stack.push(1);
    stack.push(2);
    EXPECT_EQ(2, stack.size());
}
TEST_F(MyStackTest, pushTop) {
    stack.push(1);
    stack.push(2);
    EXPECT_EQ(2, stack.top());
}
TEST_F(MyStackTest, pushPeek) {
    stack.push(1);
    stack.push(2);
    EXPECT_EQ(2, stack.peek());
}
TEST_F(MyStackTest, pushPop) {
    stack.push(1);
    stack.push(2);
    EXPECT_EQ(2, stack.pop());
}

}
};
