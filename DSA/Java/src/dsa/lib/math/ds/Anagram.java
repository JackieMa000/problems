package dsa.lib.math.ds;

import java.util.HashMap;


/**
 * Rule: Hash Table
 * Map: {letter: count_of_the_letter}. key: letter, value: count_of_the_letter
 * letter: array index, count_of_the_letter: array value
 *
 * 1. get a bucket
 * 2. produce to the bucket
 * 3. consume from the bucket
 * 4. check if the bucket is empty
 */
//LeetCode242
public class Anagram {
    public boolean isAnagram(String s, String t) {
        return isAnagram1(s, t);
    }

    public boolean isAnagram1(String s, String t) {
        int[] mapAlphabet = new int[26];
        for (char c : s.toCharArray()) mapAlphabet[hashFunc(c)]++;
        for (char c : t.toCharArray()) mapAlphabet[hashFunc(c)]--;
        for (int v : mapAlphabet) if (v != 0) return false;
        return true;
    }

    private int hashFunc(char c) {
        return c - 'a';
    }

    public boolean isAnagram11(String s, String t) {
        HashMap<Character, Integer> mapAlphabet = new HashMap<>();
        for (char c : s.toCharArray()) mapAlphabet.put(c, mapAlphabet.getOrDefault(c, 0) + 1);
        for (char c : t.toCharArray()) mapAlphabet.put(c, mapAlphabet.getOrDefault(c, 0) - 1);
        for (int v : mapAlphabet.values()) if (v != 0) return false;
        return true;
    }
}
