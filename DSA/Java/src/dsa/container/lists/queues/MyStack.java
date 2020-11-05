package dsa.container.lists.queues;

import java.util.LinkedList;
import java.util.Queue;

//LeetCode225
class MyStack<T> {

    private final Queue<T> queue;

    /**
     * Initialize your data structure here.
     */
    public MyStack() {
        this.queue = new LinkedList<>();

    }

    /**
     * Push element x onto stack.
     */
    public void push(T x) {
        this.queue.add(x);
        invertQueue(this.queue);
    }

    private static <T> void invertQueue(Queue<T> queue) {
        final int n = queue.size();
        for (int i = 0; i < n - 1; i++) queue.add(queue.poll());
    }

    /**
     * Removes the element on top of the stack and returns that element.
     */
    public T pop() {
        return this.queue.poll();
    }

    /**
     * Get the top element.
     */
    public T top() {
        return this.queue.peek();
    }

    /**
     * Returns whether the stack is empty.
     */
    public boolean empty() {
        return this.queue.isEmpty();
    }

    public int size() {
        return this.queue.size();
    }

    public T peek() {
        return this.top();
    }
}
