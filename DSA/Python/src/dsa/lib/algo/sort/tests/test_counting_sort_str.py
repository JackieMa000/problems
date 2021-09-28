from unittest import TestCase

from dsa.lib.algo.sort.counting_sort_str import CountingSortStr


class CountingSortStringTest(TestCase):
    def assertCountingSort(self, expected, ss, index):
        self.countingSort(ss, index)
        self.assertEqual(expected, ss)

    @staticmethod
    def countingSort(ss, index):
        CountingSortStr(ss, index).sort()

    def test_emptyArray(self):
        self.assertCountingSort([], [], 0)

    def test_oneElement(self):
        self.assertCountingSort(["abc"], ["abc"], 0)
        self.assertCountingSort(["abc"], ["abc"], 1)
        self.assertCountingSort(["abc"], ["abc"], 2)

    def test_sortOnIndex0(self):
        self.assertCountingSort(["ad", "bc"], ["ad", "bc"], 0)
        self.assertCountingSort(["ad", "bc"], ["bc", "ad"], 0)
        self.assertCountingSort(["ab", "a"], ["ab", "a"], 0)
        self.assertCountingSort(["a", "ab"], ["a", "ab"], 0)
        self.assertCountingSort(["ab", "b"], ["ab", "b"], 0)
        self.assertCountingSort(["ab", "b"], ["b", "ab"], 0)
        self.assertCountingSort(["ae", "cd"], ["cd", "ae"], 0)
        self.assertCountingSort(["a", "abc", "bce", "bc"], ["bce", "bc", "a", "abc"], 0)
        self.assertCountingSort(["hke", "hzg", "hac", "iba", "ikf"], ["hke", "iba", "hzg", "ikf", "hac"], 0)

    def test_sortOnIndex1(self):
        self.assertCountingSort(["hac", "iba", "hke", "ikf", "hzg"], ["hke", "iba", "hzg", "ikf", "hac"], 1)
        self.assertCountingSort(["bc", "ae"], ["ae", "bc"], 1)
        self.assertCountingSort(["ab", "cd"], ["ab", "cd"], 1)
        self.assertCountingSort(["a", "ab"], ["ab", "a"], 1)
        self.assertCountingSort(["ab", "b"], ["ab", "b"], 1)

    def test_sortOnIndex2(self):
        self.assertCountingSort(["a", "bc", "abc", "bce"], ["bce", "bc", "a", "abc"], 2)
        self.assertCountingSort(["iba", "hac", "hke", "ikf", "hzg"], ["hke", "iba", "hzg", "ikf", "hac"], 2)
