package dsa.container.lists.queues;

import org.junit.Before;
import org.junit.Test;

import static org.junit.Assert.*;


public class MyQueueTest {
    private MyQueue<Integer> queue;

    @Before
    public void setUp() {
        queue = new MyQueue<>();
    }

    @Test
    public void emptyQueue() {
        assertTrue(this.queue.empty());
    }

    @Test
    public void pushNotEmpty() {
        this.queue.push(1);
        assertFalse(this.queue.empty());
    }

    @Test
    public void popEmpty() {
        this.queue.push(1);
        assertFalse(this.queue.empty());

        this.queue.pop();
        assertTrue(this.queue.empty());
    }

    @Test
    public void pushPop() {
        this.queue.push(1);
        this.queue.push(2);
        assertEquals(Integer.valueOf(1), this.queue.pop());
    }

    @Test
    public void peek() {
        this.queue.push(1);
        this.queue.push(2);
        assertEquals(Integer.valueOf(1), this.queue.peek());
    }

    @Test
    public void front() {
        this.queue.push(1);
        this.queue.push(2);
        assertEquals(Integer.valueOf(1), this.queue.front());
    }

    @Test
    public void sizeEmpty() {
        assertEquals(0, this.queue.size());
    }

    @Test
    public void sizePush() {
        this.queue.push(1);
        assertEquals(1, this.queue.size());
    }

    @Test
    public void sizePop() {
        this.queue.push(1);
        this.queue.push(2);
        assertEquals(2, this.queue.size());

        assertEquals(Integer.valueOf(1), this.queue.pop());
        assertEquals(1, this.queue.size());
    }
}
