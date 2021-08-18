#include <dsa/lib/utils/nums.hpp>

namespace dsa::nums {
namespace {

void assertLastDigitOf(int num, int expected) {
    EXPECT_EQ(expected, nums::lastDigitOf(num));
}
TEST(LastDigitOfTest, lastDigitOf) {
    assertLastDigitOf(0, 0);
    assertLastDigitOf(1, 1);
    assertLastDigitOf(10, 0);
    assertLastDigitOf(123, 3);
}
TEST(LastDigitOfTest, staticAssert) {
    static_assert(nums::lastDigitOf(0) == 0);
    static_assert(nums::lastDigitOf(1) == 1);
    static_assert(nums::lastDigitOf(10) == 0);
    static_assert(nums::lastDigitOf(123) == 3);
}

void assertPlaceValueOf(int num, int place, int expected) {
    EXPECT_EQ(expected, nums::placeValueOf(num, place));
}
TEST(PlaceValueOfTest, unitPlace) {
    assertPlaceValueOf(0, 1, 0);
    assertPlaceValueOf(1, 1, 1);
    assertPlaceValueOf(123, 1, 3);
}
TEST(PlaceValueOfTest, unitPlaceStaticAssert) {
    static_assert(nums::placeValueOf(0, 1) == 0);
    static_assert(nums::placeValueOf(1, 1) == 1);
    static_assert(nums::placeValueOf(123, 1) == 3);
}
TEST(PlaceValueOfTest, tensPlace) {
    assertPlaceValueOf(123, 10, 2);
}
TEST(PlaceValueOfTest, tensPlaceStaticAssert) {
    static_assert(nums::placeValueOf(123, 10) == 2);
}
TEST(PlaceValueOfTest, hundredsPlace) {
    assertPlaceValueOf(123, 100, 1);
}
TEST(PlaceValueOfTest, hundredsPlaceStaticAssert) {
    static_assert(nums::placeValueOf(123, 100) == 1);
}

}
}
