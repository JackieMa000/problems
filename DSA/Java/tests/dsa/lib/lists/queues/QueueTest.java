package dsa.lib.lists.queues;

import dsa.lib.lists.ListTestFX;
import org.junit.Test;

import java.util.LinkedList;

import static org.junit.Assert.*;

public class QueueTest extends QueueTestFX {
    public static class InvertTest {
        @Test
        public void case1() {
            java.util.Queue<Integer> q = new LinkedList<>();
            q.add(1);
            q.add(2);
            q.add(3);
            Queue<Integer> queue = new Queue<>(q);
//            queue.invert();
//            queue.queue.poll()

        }
    }
}