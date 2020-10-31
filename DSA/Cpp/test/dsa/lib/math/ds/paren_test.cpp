#include <dsa/lib/math/ds/paren.h>
#include "ds_test.h"

namespace dsa::lib::math::ds {
namespace {

class IsValidTest : public ParenthesesTest {
 protected:
    static bool isValid(const char *s) {
        return Parentheses::isValid(s);
    }
};
TEST_F(IsValidTest, emptyString) {
    bool actual = isValid("");
    EXPECT_TRUE(actual);
}
TEST_F(IsValidTest, case1) {
    bool actual = isValid("()");
    EXPECT_TRUE(actual);
}
TEST_F(IsValidTest, case2) {
    bool actual = isValid("()[]{}");
    EXPECT_TRUE(actual);
}
TEST_F(IsValidTest, case3) {
    bool actual = isValid("()");
    EXPECT_TRUE(actual);
}
TEST_F(IsValidTest, case4) {
    bool actual = isValid("{[]}");
    EXPECT_TRUE(actual);
}
TEST_F(IsValidTest, case5) {
    bool actual = isValid("(]");
    EXPECT_FALSE(actual);
}
TEST_F(IsValidTest, case6) {
    bool actual = isValid("([)]");
    EXPECT_FALSE(actual);
}
TEST_F(IsValidTest, case7) {
    bool actual = isValid("]");
    EXPECT_FALSE(actual);
}
TEST_F(IsValidTest, case8) {
    bool actual = isValid("(]");
    EXPECT_FALSE(actual);
}
TEST_F(IsValidTest, case9) {
    bool actual = isValid("[");
    EXPECT_FALSE(actual);
}

}
}
