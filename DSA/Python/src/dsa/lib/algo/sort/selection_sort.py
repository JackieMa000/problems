from typing import List


class SelectionSort:
    """
     有点类似插入排序, 也分已排序区间，未排序区间。
     每次会从未排序区间中找到最小的元素，将其放到已排序区间的末尾.
     Rule:
     1) 已排序区间的末尾位置，用来插入新数据的位置，也就是未排序区间的第一个元素位置
     2）取未排序区间的最小值，与未排序区间的第一个元素交换位置swap
     3) 未排序区间的开始位置后移一位
     <p>
     已排序区间i: [0, n-1)
     未排序区间j: [i+1, n)
    """

    @staticmethod
    def sort(ary: List[int]) -> None:
        n = len(ary)

        for i in range(n - 1):
            # 未排序区间查找最小值
            min_idx = i
            for j in range(i + 1, n):
                if ary[j] < ary[min_idx]:
                    min_idx = j

            # swap
            tmp = ary[min_idx]
            ary[min_idx] = ary[i]
            ary[i] = tmp
