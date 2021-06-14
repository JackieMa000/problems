#include <list>
#include <vector>

#include <dsa/lib/libdef.h>
#include <dsa/lib/utils/algorithm.hpp>
#include <dsa/testing/dsatest.h>
#include <dsa/lib/utils/math.h>

namespace dsa {
namespace {

TEST(ReplaceTest, array) {
    int nums[] = {1, 2, 3};
    int expected[] = {1, 0, 3};

    dsa::replace(nums, nums + 3, 2, 0);

    EXPECT_ARRAY_EQ(expected, aryLength(expected), nums, aryLength(nums));
}
TEST(ReplaceTest, vector) {
    std::vector<int> nums = {1, 2, 3};
    std::vector<int> expected = {1, 0, 3};

    dsa::replace(nums.begin(), nums.end(), 2, 0);
    EXPECT_EQ(expected, nums);
}

TEST(ReplaceIfTest, array) {
    int nums[] = {1, 2, 3};
    int expected[] = {0, 2, 0};

    dsa::replace_if(nums, nums + 3, dsa::isOdd, 0);

    EXPECT_ARRAY_EQ(expected, aryLength(expected), nums, aryLength(nums));
}
TEST(ReplaceIfTest, vector) {
    std::vector<int> nums = {1, 2, 3};
    std::vector<int> expected = {0, 2, 0};

    dsa::replace_if(nums.begin(), nums.end(), dsa::isOdd, 0);
    EXPECT_EQ(expected, nums);
}

TEST(RemoveTest, array) {
    int nums[] = {0, 1, 0, 2};
    int expected[] = {1, 2};

    int *last = dsa::remove(nums, nums + aryLength(nums), 0);
    long n = dsa::distance(nums, last);
    EXPECT_ARRAY_EQ(expected, aryLength(expected), nums, n);
}
TEST(RemoveIfTest, vector) {
    std::vector<int> nums = {1, 2, 3};
    std::vector<int> expected = {2};

    auto last = dsa::remove_if(nums.begin(), nums.end(), isOdd);

    std::vector<int> result(1);
    dsa::copy(nums.begin(), last, result.begin());
    EXPECT_EQ(expected, result);
}

TEST(DistanceTest, array) {
    int nums[] = {1, 2, 3};
    long actual = dsa::distance(nums, nums);
    EXPECT_EQ(actual, 0);
}
TEST(DistanceTest, array1) {
    int nums[] = {1, 2, 3};
    auto actual = dsa::distance(nums, nums + 3);
    EXPECT_EQ(actual, 3);
}
TEST(DistanceTest, list) {
    std::list<int> nums = {1, 2, 3};
    auto actual = dsa::distance(nums.begin(), nums.end());
    EXPECT_EQ(actual, 3);
}
TEST(DistanceTest, vector) {
    std::vector<int> nums = {1, 2, 3};
    auto actual = dsa::distance(nums.begin(), nums.end());
    EXPECT_EQ(actual, 3);
}

TEST(FindTest, vector) {
    std::vector<int> nums = {1, 2, 3};
    auto actual = dsa::find(nums.begin(), nums.end(), 2);
    EXPECT_EQ(2, *actual);
}
TEST(FindIfTest, array) {
    int nums[] = {1, -2, -3};
    auto actual = dsa::find_if(nums, nums + aryLength(nums), [](int x) { return x < 0; });
    EXPECT_EQ(-2, *actual);
    EXPECT_EQ(1, dsa::distance(nums, actual));
}
TEST(FindIfNotTest, list) {
    std::list<int> nums = {-1, 2, 3};
    auto actual = dsa::find_if_not(nums.begin(), nums.end(), [](int x) { return x < 0; });
    EXPECT_EQ(2, *actual);
    EXPECT_EQ(1, dsa::distance(nums.begin(), actual));
}

TEST(CountTest, array) {
    int nums[] = {0, 1, 2, 2, 0, 1, 2, 3};
    EXPECT_EQ(3, dsa::count(nums, nums + aryLength(nums), 2));
    EXPECT_EQ(0, dsa::count(nums, nums + aryLength(nums), 7));
    EXPECT_EQ(0, dsa::count(nums, nums, 2));
}
TEST(CountIfTest, array) {
    int nums[] = {0, 1, 2, 2, 0, 1, 2, 3};
    EXPECT_EQ(3, dsa::count_if(nums, nums + aryLength(nums), equal(2)));
    EXPECT_EQ(0, dsa::count_if(nums, nums + aryLength(nums), equal(7)));
    EXPECT_EQ(0, dsa::count_if(nums, nums, equal(2)));
}

TEST(ReverseTest, arrayOneElement) {
    int nums[] = {0};
    int expected[] = {0};
    dsa::reverse(nums, nums + aryLength(nums));
    EXPECT_ARRAY_EQ(expected, aryLength(expected), nums, aryLength(nums));
}
TEST(ReverseTest, array) {
    int nums[] = {1, 2, 3};
    int expected[] = {3, 2, 1};
    dsa::reverse(nums, nums + aryLength(nums));
    EXPECT_ARRAY_EQ(expected, aryLength(expected), nums, aryLength(nums));
}
TEST(ReverseTest, list) {
    std::list<int> nums = {1, 2, 3};
    std::list<int> expected = {3, 2, 1};
    dsa::reverse(nums.begin(), nums.end());
    EXPECT_EQ(expected, nums);
}
TEST(ReverseTest, vector) {
    std::vector<int> nums = {1, 2, 3};
    std::vector<int> expected = {3, 2, 1};
    dsa::reverse(nums.begin(), nums.end());
    EXPECT_EQ(expected, nums);
}


}
}