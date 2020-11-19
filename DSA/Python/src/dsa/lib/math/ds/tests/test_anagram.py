from unittest import TestCase

from dsa.lib.math.ds.anagram import Anagram


class TestAnagram(TestCase):
    def test_is_anagram(self):
        self.assertTrue(self.is_anagram('cat', 'tac'))
        self.assertFalse(self.is_anagram('cat', 'cae'))
        self.assertTrue(self.is_anagram('anagram', 'nagaram'))

    @staticmethod
    def is_anagram(s: str, t: str) -> bool:
        return Anagram().isAnagram(s, t)
