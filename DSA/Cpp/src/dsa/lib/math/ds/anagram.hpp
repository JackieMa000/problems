#ifndef DSA_SRC_DSA_LIB_MATH_DS_ANAGRAM_HPP_
#define DSA_SRC_DSA_LIB_MATH_DS_ANAGRAM_HPP_
#include <string>
#include <unordered_map>
namespace dsa::lib::math::ds {


// LeetCode242
/**
 * Rule: Hash Table
 * mapAlphabet = {letter: count_of_letter}
 * array index: letter(hash func), array value: count of letter;
 */
class Anagram {
 public:
    static bool isAnagram(const std::string &s, const std::string &t) {
        return isAnagram11(s, t);
    }
 private:
    static bool isAnagram1(const std::string &s, const std::string &t) {
        int mapAlphabet[26] = {0};
        for (const char &c: s) { mapAlphabet[hashFunc(c)]++; }
        for (const char &c: t) { mapAlphabet[hashFunc(c)]--; }
        for (int &v: mapAlphabet) { if (v) return false; }
        return true;
    }
    static bool isAnagram11(const std::string &s, const std::string &t) {
        int mapAlphabet[26] = {0};
        std::for_each(s.begin(), s.end(), [&](char c) { mapAlphabet[hashFunc(c)]++; });
        std::for_each(t.begin(), t.end(), [&](char c) { mapAlphabet[hashFunc(c)]--; });
        return std::all_of(mapAlphabet, mapAlphabet + 26, [](int v) { return v == 0; }) ? true : false;
    }
    static int hashFunc(char c) { return c - 'a'; }

    static bool isAnagram2(const std::string &s, const std::string &t) {
        std::unordered_map<char, int> mapAlphabet;
        for (const char &c: s) { mapAlphabet[c]++; }
        for (const char &c: t) { mapAlphabet[c]--; }
        for (auto &it: mapAlphabet) { if (it.second) return false; }
        return true;
    }
    static bool isAnagram21(const std::string &s, const std::string &t) {
        std::unordered_map<char, int> mapAlphabet;
        std::for_each(s.begin(), s.end(), [&](char c) { mapAlphabet[c]++; });
        std::for_each(t.begin(), t.end(), [&](char c) { mapAlphabet[c]--; });
        return std::all_of(mapAlphabet.begin(), mapAlphabet.end(), [](auto it) { return it.second == 0; }) ? true
                                                                                                           : false;
    }
};

}
#endif //DSA_SRC_DSA_LIB_MATH_DS_ANAGRAM_HPP_
