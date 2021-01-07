package dsa.lib.algo.sort;

/**
 * QuickSort Rule:
 * 如果要排序数组中下标从 p 到 r 之间的一组数据，我们选择 p 到 r 之间的任意一个数据作为 pivot（分区点）。
 * 我们遍历 p 到 r 之间的数据，将小于 pivot 的放到左边，将大于 pivot 的放到右边，将 pivot 放到中间。
 * <p>
 * 经过这一步骤之后，数组 p 到 r 之间的数据就被分成了三个部分，前面 p 到 q-1 之间都是小于 pivot 的，中间是 pivot，
 * 后面的 q+1 到 r 之间是大于 pivot 的。
 * <p>
 * 根据分治、递归的处理思想，我们可以用递归排序下标从 p 到 q-1 之间的数据和下标从 q+1 到 r 之间的数据，直到区间缩小为 1，就说明所有的数据都有序了。
 */
public class QuickSort {
    public void sort(int[] ary, int length) {
        quickSort(ary, 0, length - 1);

    }

    private void quickSort(int[] ary, int p, int r) {
        if (p >= r) return;

//        the new position of pivot after one round of partition
        int q = partition(ary, p, r);
//        left side of pivot
        quickSort(ary, p, q - 1);
//        right side of pivot
        quickSort(ary, q + 1, r);
    }

    /**
     * 随机选择一个元素作为 pivot（一般情况下，可以选择 p 到 r 区间的最后一个元素），然后对 A[p…r]分区，函数返回 pivot 的新下标。
     * A = A[p…r-1]
     * A1 = A[p…i-1]
     * A2 = A[i…r-1]
     * 这里的处理有点类似选择排序。我们通过游标 i 把 A分成两部分, 已处理区间A1和未处理区间A2,
     * A1的元素都是小于pivot 的, A2的元素都是大于pivot的
     * 我们每次都从A2中取一个元素 A[j]，与 pivot 对比，如果小于 pivot，则将其加入到A1的尾部，也就是A[i]的位置。
     * 利用交换swap A[i] with A[j]，在 O(1) 的时间复杂度内完成插入操作
     */
    private int partition(int[] ary, int p, int r) {
//        position i is in the middle of A1 and A2
        int i = p;

        int pivot = ary[r];
        for (int j = p; j < r; ++j) {
            if (ary[j] < pivot) {
                arrayswap(ary, i, j);
                ++i;
            }
        }
//        put pivot element in the middle of A1 and A2(aka. position i)
        arrayswap(ary, i, r);

        return i;
    }

    // swap array elements
    private void arrayswap(int[] ary, int i, int j) {
        int tmp = ary[i];
        ary[i] = ary[j];
        ary[j] = tmp;
    }
}
