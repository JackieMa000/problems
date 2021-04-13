package dsa.container.lists.queues;

import org.junit.Before;
import org.junit.Test;

import static org.junit.Assert.*;

public class MyStackTest extends MyStackTestFX {

    private MyStack<Integer> stack;

    @Before
    public void setUp() {
        stack = new MyStack<>();
    }

    @Test
    public void emptyStack() {
        assertTrue(stack.empty());
    }

    @Test
    public void pushNotEmpty() {
        stack.push(1);
        assertFalse(stack.empty());
    }

    @Test
    public void pushPopEmpty() {
        stack.push(1);
        assertEquals(Integer.valueOf(1), stack.pop());
        assertTrue(stack.empty());
    }

    @Test
    public void pushTop() {
        stack.push(1);
        stack.push(2);
        assertEquals(Integer.valueOf(2), stack.top());
    }

    @Test
    public void pushPeek() {
        stack.push(1);
        stack.push(2);
        assertEquals(Integer.valueOf(2), stack.peek());
    }
}