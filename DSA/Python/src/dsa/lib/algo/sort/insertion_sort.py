from typing import List


class InsertionSort:
    """
  插入排序:
  已排序区间，未排序区间。
  插入排序包含两种操作，1) 元素的比较，2) 元素的移动
  1) 找到合适的插入位置。2) 对插入点之后的元素往后搬移一位
  <p>
  数据分为两个区间，已排序区间和未排序区间。初始已排序区间只有一个元素，就是数组的第一个元素。
  插入算法的核心思想是取未排序区间中的元素，在已排序区间中找到合适的插入位置将其插入，
  并保证已排序区间数据一直有序

  Rule:
  取已排序区间尾元素a，取未排序区间头元素b
  a从尾向头前进，b从头向尾前进
  用b在已排序区间查找插入位置，和a比较
  a > b -> 数据搬移，a后移一位, 继续比较, a前进
  a = b -> b 前进
  a < b -> b 前进
  已排序区间查找完成后，插入数据b
    """

    @staticmethod
    def sort(ary: List[int]) -> None:
        n = len(ary)
        # 未排序区间
        for i in range(1, n):
            b = ary[i]

            # 已排序区间
            j = i - 1
            while j >= 0:
                a = ary[j]

                if a > b:
                    ary[j + 1] = a
                else:
                    break
                j -= 1
            ary[j + 1] = b
