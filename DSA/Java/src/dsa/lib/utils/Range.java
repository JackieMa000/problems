package dsa.lib.utils;

import dsa.lib.utils.Algorithm.Comp;
import dsa.lib.utils.Algorithm.Strip;

import java.util.Comparator;
import java.util.Iterator;
import java.util.List;
import java.util.Objects;

public class Range {
    // strip

    /**
     * Remove all the leading 0s from the given array
     */
    public static int[] lstrip(int[] nums) {
        return Strip.lstripIt(nums);
    }

    /**
     * Remove all the trailing 0s from the given array
     */
    public static int[] rstrip(int[] nums) {
        return Strip.rstripIt(nums);
    }

    /**
     * Remove all the leading and trailing 0s from the given array
     */
    public static int[] strip(int[] nums) {
        return Strip.stripIt(nums);
    }

    /**
     * Remove all the leading and trailing 0s from the given array
     */
    public static int[] trim(int[] nums) {
        return strip(nums);
    }


    // swap

    /**
     * Swap 2 elements of an array.
     *
     * @param nums The array.
     * @param i    The position of 1st element.
     * @param j    The position of 2nd element.
     */
    public static void swap(int[] nums, int i, int j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }

    public static <E> void swap(E[] ary, int i, int j) {
        E tmp = ary[i];
        ary[i] = ary[j];
        ary[j] = tmp;
    }

    public static <E> void swap(List<E> ls, int i, int j) {
        E tmp = ls.get(i);
        ls.set(i, ls.get(j));
        ls.set(j, tmp);
    }

    // copy

    /**
     * copy from primitive int array to primitive int array
     */
    public static void copy(int[] src, int srcPos, int[] des, int desPos, int n) {
        for (int i = 0; i < n; ++i) des[desPos + i] = src[srcPos + i];
    }

    /**
     * copy from array to array
     */
    public static <T> void copy(T[] src, int srcPos, T[] des, int desPos, int n) {
        for (int i = 0; i < n; ++i) des[desPos + i] = src[srcPos + i];
    }

    /**
     * copy from Integer wrapper array to primitive int array.
     */
    public static void copy(Integer[] src, int srcPos, int[] des, int desPos, int n) {
        for (int i = 0; i < n; ++i) des[desPos + i] = src[srcPos + i];
    }

    /**
     * copy from primitive int array to Integer wrapper array.
     */
    public static void copy(int[] src, int srcPos, Integer[] des, int desPos, int n) {
        for (int i = 0; i < n; ++i) des[desPos + i] = src[srcPos + i];
    }

    /**
     * copy from list to list.
     */
    public static <T> void copy(List<T> src, int srcPos, List<T> des, int desPos, int n) {
        for (int i = 0; i < n; ++i) des.set(desPos + i, src.get(srcPos + i));
    }

    /**
     * copy from list to array.
     */
    public static <T> void copy(List<T> src, int srcPos, T[] des, int desPos, int n) {
        for (int i = 0; i < n; ++i) des[desPos + i] = src.get(srcPos + i);
    }

    /**
     * copy from array to list.
     */
    public static <T> void copy(T[] src, int srcPos, List<T> des, int desPos, int n) {
        for (int i = 0; i < n; ++i) des.set(desPos + i, src[srcPos + i]);
    }

    // fill

    public static void fill(int[] nums, int v) {
        for (int i = 0; i < nums.length; ++i) nums[i] = v;
    }

    public static <E> void fill(E[] ary, E v) {
        for (int i = 0; i < ary.length; ++i) ary[i] = v;
    }

    public static <E> void fill(List<E> ls, E v) {
        for (int i = 0; i < ls.size(); ++i) ls.set(i, v);
    }

    // max

    public static <T> T max(T[] ary, Comparator<T> comp) {
        return Comp.comp(ary, (x, y) -> comp.compare(x, y) > 0);
    }

    public static int max(int[] nums) {
        Integer r = max(integerValueOf(nums), Integer::compareTo);
        Objects.requireNonNull(r);
        return r;
    }

    public static Integer max(Integer[] nums) {
        return max(nums, Integer::compareTo);
    }

    public static String max(String[] ss) {
        return max(ss, String::compareTo);
    }

    public static String maxSize(String[] ss) {
        return max(ss, Comparator.comparingInt(String::length));
    }

    public static <E> E[] maxSize(E[][] ary) {
        return max(ary, Comparator.comparingInt(e -> e.length));
    }

    public static <E> List<E> maxSize(List<List<E>> ls, Comparator<List<E>> comp) {
        return Comp.compSize(ls, (x, y) -> comp.compare(x, y) > 0);
    }

    public static <E> List<E> maxSize(List<List<E>> ls) {
        return maxSize(ls, Comparator.comparingInt(List::size));
    }

    public static <E> List<E> maxSize(Iterator<List<E>> it, Comparator<List<E>> comp) {
        return Comp.compSize(it, (x, y) -> comp.compare(x, y) > 0);
    }

    public static <E> List<E> maxSize(Iterator<List<E>> it) {
        return maxSize(it, Comparator.comparingInt(List::size));
    }

    // min

    public static <T> T min(T[] ary, Comparator<T> comp) {
        return Comp.comp(ary, (x, y) -> comp.compare(x, y) < 0);
    }

    public static int min(int[] nums) {
        Integer r = min(integerValueOf(nums), Integer::compareTo);
        Objects.requireNonNull(r);
        return r;
    }

    public static Integer min(Integer[] nums) {
        return min(nums, Integer::compareTo);
    }

    public static String min(String[] ss) {
        return min(ss, String::compareTo);
    }

    public static String minSize(String[] ss) {
        return min(ss, Comparator.comparingInt(String::length));
    }

    public static <E> E[] minSize(E[][] ary) {
        return min(ary, Comparator.comparingInt(e -> e.length));
    }

    public static <E> List<E> minSize(List<List<E>> ls, Comparator<List<E>> comp) {
        return Comp.compSize(ls, (x, y) -> comp.compare(x, y) < 0);
    }

    public static <E> List<E> minSize(List<List<E>> lists) {
        return minSize(lists, Comparator.comparingInt(List::size));
    }

    public static <E> List<E> minSize(Iterator<List<E>> it, Comparator<List<E>> comp) {
        return Comp.compSize(it, (x, y) -> comp.compare(x, y) < 0);
    }

    public static <E> List<E> minSize(Iterator<List<E>> it) {
        return minSize(it, Comparator.comparingInt(List::size));
    }

    public static Integer[] integerValueOf(int[] nums) {
        Integer[] r = new Integer[nums.length];
        copy(nums, 0, r, 0, nums.length);
        return r;
    }

    public static int[] intValueOf(Integer[] nums) {
        int[] r = new int[nums.length];
        copy(nums, 0, r, 0, nums.length);
        return r;
    }

}
