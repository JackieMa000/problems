package dsa.lib.math.nums;

import java.util.PriorityQueue;

//LeetCode703
class KthLargest {
    private final PriorityQueue<Integer> queue;
    private final int k;

    public KthLargest(int k, int[] nums) {
        queue = new PriorityQueue<>();
        this.k = k;
        for (int num : nums) add(num);
    }

    public int add(int val) {
        queue.add(val);
        if (queue.size() > this.k) queue.poll();
        return queue.peek();
    }
}
