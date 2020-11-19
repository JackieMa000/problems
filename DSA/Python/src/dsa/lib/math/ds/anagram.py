# LeetCode242
class Anagram:
    """
    Rule: Hash Table
    map: {letter: count_of_the_letter}
    array index: letter(hash func), array value: count of occurrences of the letter in the string
    """

    def isAnagram(self, s: str, t: str) -> bool:
        return self.isAnagram1(s, t)

    def isAnagram1(self, s: str, t: str) -> bool:
        def hash_func(c) -> int:
            return ord(c) - ord('a')

        map_alphabet = [0] * 26
        for c in s: map_alphabet[hash_func(c)] += 1
        for c in t: map_alphabet[hash_func(c)] -= 1
        for v in map_alphabet:
            if v: return False
        return True

    def isAnagram11(self, s: str, t: str) -> bool:
        def hash_func(c) -> int:
            return ord(c) - ord('a')

        map_alphabet = [0] * 26
        for c in s: map_alphabet[hash_func(c)] += 1
        for c in t: map_alphabet[hash_func(c)] -= 1
        return True if all(map(lambda v: v == 0, map_alphabet)) else False

    def isAnagram2(self, s: str, t: str) -> bool:
        map_alphabet = {}
        for c in s: map_alphabet[c] = map_alphabet.get(c, 0) + 1
        for c in t: map_alphabet[c] = map_alphabet.get(c, 0) - 1
        for v in map_alphabet.values():
            if v: return False
        return True

    def isAnagram21(self, s: str, t: str) -> bool:
        map_alphabet = {}
        for c in s: map_alphabet[c] = map_alphabet.get(c, 0) + 1
        for c in t: map_alphabet[c] = map_alphabet.get(c, 0) - 1
        return True if all(map(lambda v: v == 0, map_alphabet.values())) else False
