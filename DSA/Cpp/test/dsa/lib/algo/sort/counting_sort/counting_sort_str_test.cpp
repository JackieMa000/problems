#include <dsa/lib/algo/sort/counting_sort/counting_sort_str.hpp>
#include "dsa/lib/algo/sort/sort_test.h"

namespace dsa::lib::algo::sort {
namespace {

class CountingSortStringTest : public SortTest {
 protected:
    static void assertCountingSort(std::vector<std::string> &&expected, std::vector<std::string> &&ss, pos_t index) {
        countingSort(ss, index);
        EXPECT_EQ(expected, ss);
    }

    static void countingSort(std::vector<std::string> &ss, pos_t index) {
        CountingSortString(ss, index).sort();
    }
};
TEST_F(CountingSortStringTest, emptyArray) {
    assertCountingSort({}, {}, 0);
}
TEST_F(CountingSortStringTest, oneElement) {
    assertCountingSort({"abc"}, {"abc"}, 0);
    assertCountingSort({"abc"}, {"abc"}, 1);
    assertCountingSort({"abc"}, {"abc"}, 2);
}
TEST_F(CountingSortStringTest, sortOnIndex0) {
    assertCountingSort({"ad", "bc"}, {"ad", "bc"}, 0);
    assertCountingSort({"ad", "bc"}, {"bc", "ad"}, 0);
    assertCountingSort({"ab", "a"}, {"ab", "a"}, 0);
    assertCountingSort({"a", "ab"}, {"a", "ab"}, 0);
    assertCountingSort({"ab", "b"}, {"ab", "b"}, 0);
    assertCountingSort({"ab", "b"}, {"b", "ab"}, 0);
    assertCountingSort({"ae", "cd"}, {"cd", "ae"}, 0);
    assertCountingSort({"a", "abc", "bce", "bc"}, {"bce", "bc", "a", "abc"}, 0);
    assertCountingSort({"hke", "hzg", "hac", "iba", "ikf"},
                       {"hke", "iba", "hzg", "ikf", "hac"}, 0);
}
TEST_F(CountingSortStringTest, sortOnIndex1) {
    assertCountingSort({"hac", "iba", "hke", "ikf", "hzg"},
                       {"hke", "iba", "hzg", "ikf", "hac"}, 1);
    assertCountingSort({"bc", "ae"}, {"ae", "bc"}, 1);
    assertCountingSort({"ab", "cd"}, {"ab", "cd"}, 1);
    assertCountingSort({"a", "ab"}, {"ab", "a"}, 1);
    assertCountingSort({"ab", "b"}, {"ab", "b"}, 1);
}
TEST_F(CountingSortStringTest, sortOnIndex2) {
    assertCountingSort({"a", "bc", "abc", "bce"}, {"bce", "bc", "a", "abc"}, 2);
    assertCountingSort({"iba", "hac", "hke", "ikf", "hzg"},
                       {"hke", "iba", "hzg", "ikf", "hac"}, 2);
}

}
}