package dsa;

import dsa.nodes.ListNode;

import java.util.Arrays;

public class Scratch {
    public static void main(String[] args) {
        ListNode node = new ListNode();
        int[] ary1 = {1, 2, 3};
        Integer[] ary2 = {1, 2, 3};
        ListNode[] ary3 = {node};

        char[] ary10 = {'a', 'b', 'c', 'n'};

        System.out.println(Arrays.toString(ary1));
        System.out.println(Arrays.toString(ary2));
        System.out.println(Arrays.toString(ary3));

        System.out.println(Arrays.toString(ary10));
    }
}
