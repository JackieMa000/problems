package dsa.container.lists.queues;

import java.util.Stack;

//LeetCode232
public class MyQueue<T> {
    private final Stack<T> input, output;

    public MyQueue() {
        this.input = new Stack<>();
        this.output = new Stack<>();
    }

    public boolean empty() {
        return this.input.empty() && this.output.empty();
    }

    public void push(T x) {
        this.input.push(x);
    }

    public T pop() {
        if (this.output.empty()) this.migrate();
        return this.output.pop();
    }

    //    Migrate the input stack to the output stack.
    private void migrate() {
        while (!this.input.empty()) this.output.push(this.input.pop());
    }

    public T peek() {
        if (this.output.empty()) this.migrate();
        return this.output.peek();
    }

    public int size() {
        return this.input.size() + this.output.size();
    }

    public T front() {
        return this.peek();
    }
}
