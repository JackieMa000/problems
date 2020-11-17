package dsa.lib.math.nums;

import java.util.ArrayDeque;
import java.util.Deque;
import java.util.PriorityQueue;

//LeetCode239
public class MaxSlidingWindow {
    public int[] maxSlidingWindow(int[] nums, int k) {
        return maxSlidingWindow1(nums, k);
    }

    /**
     * Rule: Deque, Monotonic Queue
     * Monotonic Queue: Natural ordering, ascending or descending ordering queue
     */
    private int[] maxSlidingWindow1(int[] nums, int k) {
        final int n = nums.length;
        int[] result = new int[n - k + 1];
        Deque<Integer> deque = new ArrayDeque<>();
        int windowLeftBound;
        for (int i = 0; i < n; i++) {
            windowLeftBound = i - k + 1;
            if (!deque.isEmpty() && deque.peek() < windowLeftBound) deque.pop();
            while (!deque.isEmpty() && nums[deque.peekLast()] < nums[i]) deque.pollLast();
            deque.add(i);
            if (windowLeftBound >= 0) result[windowLeftBound] = nums[deque.peek()];
        }
        return result;
    }

    //Rule: Max Heap
    private int[] maxSlidingWindow2(int[] nums, int k) {
        //     Use indices since they are unique
        final int n = nums.length;
        int[] result = new int[n - k + 1]; // number of windows
//        Lambda implement functional interface
        PriorityQueue<Integer> maxPQ = new PriorityQueue<>((i1, i2) -> (nums[i2] - nums[i1])); // stores values

        for (int i = 0; i < n; ++i) {
//            Maintain the window
            final int windowLeftBound = i - k + 1;
            if (windowLeftBound > 0) maxPQ.remove(i - k); // remove the out-of-bound value by index
            maxPQ.offer(i);

            if (windowLeftBound >= 0) result[windowLeftBound] = nums[maxPQ.peek()];
        }

        return result;
    }
}
