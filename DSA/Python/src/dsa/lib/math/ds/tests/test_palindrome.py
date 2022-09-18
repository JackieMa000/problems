from unittest import TestCase

from dsa.lib.math.ds.palindrome import Palindrome


class PalindromeTest(TestCase):
    def test_none(self):
        self.assertEqual(None, self.getLongestPalindrome(None))

    def test_emptyString(self):
        self.assertEqual("", self.getLongestPalindrome(""))

    def test_oneChar(self):
        self.assertEqual("a", self.getLongestPalindrome("a"))

    def test_case1(self):
        self.assertEqual("", self.getLongestPalindrome(""))
        self.assertEqual("a", self.getLongestPalindrome("a"))
        self.assertEqual("bab", self.getLongestPalindrome("babd"))
        self.assertEqual("bb", self.getLongestPalindrome("cbbd"))
        self.assertEqual("aaaa", self.getLongestPalindrome("aaaa"))

    @staticmethod
    def getLongestPalindrome(s):
        r1 = Palindrome().longestPalindrome(s)
        r2 = Palindrome().longestPalindrome1(s)
        assert r1 == r2, "Results from 2 same functions are different.";

        return r1
