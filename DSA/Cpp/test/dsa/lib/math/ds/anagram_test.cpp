#include <dsa/lib/math/ds/anagram.hpp>
#include "ds_test.h"
namespace dsa::lib::math::ds {
namespace {

class AnagramTest : public DsTest {
 protected:
    static bool isAnagram(const char *s, const char *t) {
        return Anagram::isAnagram(s, t);
    }
};
TEST_F(AnagramTest, case1) {
    bool actual = isAnagram("anagram", "nagaram");
    EXPECT_TRUE(actual);
}
TEST_F(AnagramTest, case2) {
    bool actual = isAnagram("rat", "car");
    EXPECT_FALSE(actual);
}

}
}
