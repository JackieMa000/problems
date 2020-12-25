package dsa.lib.algo.sort;

/**
 * 有点类似插入排序, 也分已排序区间，未排序区间。
 * 每次会从未排序区间中找到最小的元素，将其放到已排序区间的末尾.
 * Rule:
 * 1) 已排序区间的末尾位置，用来插入新数据的位置，也就是未排序区间的第一个元素位置
 * 2）取未排序区间的最小值，与未排序区间的第一个元素交换位置swap
 * 3) 未排序区间的开始位置后移一位
 * <p>
 * 已排序区间i: [0, n-1)
 * 未排序区间j: [i+1, n)
 */
public class SelectionSort {
    public static void sort(int[] ary) {
        int n = ary.length;
        for (int i = 0; i < n - 1; i++) {

//            未排序区间, 查找最小值
//            这里的ary[i] 表示未排序区间的第一个元素, 也就是已排序区间的末尾位置等待插入新数据
            int minIdx = i;
            for (int j = i + 1; j < n; j++) {
                if (ary[j] < ary[minIdx]) {
                    minIdx = j;
                }
            }

//            交换位置swap
            int tmp = ary[minIdx];
            ary[minIdx] = ary[i];
            ary[i] = tmp;
        }
    }
}
