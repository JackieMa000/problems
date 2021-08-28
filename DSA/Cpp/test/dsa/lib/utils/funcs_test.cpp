#include <dsa/lib/utils/funcs.hpp>
#include <array>

namespace dsa {
namespace {

TEST(CompSizeTest, argumentType) {
    typedef std::vector<int> ints;
    typedef dsa::compSize<ints, ints> C;

    static_assert((std::is_same<ints, C::first_argument_type>::value));
    static_assert((std::is_same<ints, C::second_argument_type>::value));
    static_assert((std::is_same<int, C::result_type>::value));
}
TEST(CompSizeTest, PrimaryTemplate) {
    typedef std::vector<int> ints;
    typedef compSize<ints, ints> C;
    const C c = C();

    EXPECT_EQ(0, c({1}, {1}));
    EXPECT_EQ(-1, c({1}, {1, 2}));
    EXPECT_EQ(1, c({1, 1}, {1}));
}
TEST(CompSizeTest, voidTemplate) {
    typedef std::vector<int> ints;
    typedef compSize<> C;
    const C c = C();

    EXPECT_EQ(0, c(ints({1}), ints({1})));
    EXPECT_EQ(-1, c(ints({1}), ints({1, 1})));
    EXPECT_EQ(1, c(ints({1, 1}), ints({1})));
}
TEST(CompSizeTest, compileTime) {
    typedef std::array<int, 1> ints;
    typedef std::array<int, 2> ints1;

    static_assert(0 == compSize<ints, ints>()(ints({1}), ints({1})));
    static_assert(1 == compSize<ints1, ints>()(ints1({1, 1}), ints({1})));
    static_assert(-1 == compSize<ints, ints1>()(ints({1}), ints1({1, 1})));

    static_assert(0 == compSize<>()(ints({1}), ints({1})));
    static_assert(1 == compSize<>()(ints1({1, 1}), ints({1})));
    static_assert(-1 == compSize<>()(ints({1}), ints1({1, 1})));
}

TEST(EqualSizeTest, primaryTempalte) {
    typedef dsa::equalSize<std::vector<int>> F;
    const F f = F();

    EXPECT_TRUE(f({1}, {1}));
    EXPECT_FALSE(f({1, 2}, {1}));
    EXPECT_FALSE(f({1}, {1, 2}));
}
TEST(EqualSizeTest, voidTemplate) {
    typedef dsa::equalSize<> F;
    const F f = F();

    typedef std::vector<int> ints;
    EXPECT_TRUE(f(ints({1}), ints({1})));
    EXPECT_FALSE(f(ints({1, 2}), ints({1})));
    EXPECT_FALSE(f(ints({1}), ints({1, 2})));
}
TEST(EqualSizeTest, compileTime) {
    typedef std::array<int, 1> ints;
    static_assert(dsa::equalSize<ints>()({1}, {1}));

    typedef std::array<int, 2> ints1;
    static_assert(dsa::equalSize<>()(ints({1}), ints({1})));
    static_assert(!dsa::equalSize<>()(ints({1}), ints1({1, 1})));
    static_assert(!dsa::equalSize<>()(ints1({1, 1}), ints({1})));
}

TEST(LessSizeTest, primaryTempalte) {
    typedef dsa::lessSize<std::vector<int>> F;
    const F f = F();

    EXPECT_FALSE(f({1}, {1}));
    EXPECT_FALSE(f({1, 2}, {1}));
    EXPECT_TRUE(f({1}, {1, 2}));
}
TEST(LessSizeTest, voidTemplate) {
    typedef dsa::lessSize<> F;
    const F f = F();

    typedef std::vector<int> ints;
    EXPECT_FALSE(f(ints({1}), ints({1})));
    EXPECT_FALSE(f(ints({1, 2}), ints({1})));
    EXPECT_TRUE(f(ints({1}), ints({1, 2})));
}
TEST(LessSizeTest, compileTime) {
    typedef std::array<int, 1> ints;
    static_assert(!dsa::lessSize<ints>()({1}, {1}));

    typedef std::array<int, 2> ints1;
    static_assert(!dsa::lessSize<>()(ints({1}), ints({1})));
    static_assert(dsa::lessSize<>()(ints({1}), ints1({1, 1})));
    static_assert(!dsa::lessSize<>()(ints1({1, 1}), ints({1})));
}

TEST(GreaterSizeTest, primaryTempalte) {
    typedef dsa::greaterSize<std::vector<int>> F;
    const F f = F();

    EXPECT_FALSE(f({1}, {1}));
    EXPECT_TRUE(f({1, 2}, {1}));
    EXPECT_FALSE(f({1}, {1, 2}));
}
TEST(GreaterSizeTest, voidTemplate) {
    typedef dsa::greaterSize<> F;
    const F f = F();

    typedef std::vector<int> ints;
    EXPECT_FALSE(f(ints({1}), ints({1})));
    EXPECT_TRUE(f(ints({1, 2}), ints({1})));
    EXPECT_FALSE(f(ints({1}), ints({1, 2})));
}
TEST(GreaterSizeTest, compileTime) {
    typedef std::array<int, 1> ints;
    static_assert(!dsa::greaterSize<ints>()({1}, {1}));

    typedef std::array<int, 2> ints1;
    static_assert(!dsa::greaterSize<>()(ints({1}), ints({1})));
    static_assert(!dsa::greaterSize<>()(ints({1}), ints1({1, 1})));
    static_assert(dsa::greaterSize<>()(ints1({1, 1}), ints({1})));
}

}
}