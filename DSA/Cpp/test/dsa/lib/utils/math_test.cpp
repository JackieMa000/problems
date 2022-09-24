#include "dsa/lib/utils/math.hpp"

namespace dsa {
namespace {

TEST(MatrixTest, intElement) {
    MatrixHeap<int> m(3, 2);
    MatrixStack<int, 3, 2> m1{};
    m[0][0] = 1;
    m1[0][0] = 1;
    EXPECT_EQ(m[0][0], 1);
    EXPECT_EQ(m1[0][0], 1);
}
TEST(MatrixTest, charElement) {
    MatrixHeap<char> m(3, 2);
    MatrixStack<char, 3, 2> m1{};
    m[0][0] = 'a';
    m1[0][0] = 'a';
    EXPECT_EQ(m[0][0], 'a');
    EXPECT_EQ(m1[0][0], 'a');
}
TEST(MatrixTest, constCharPointer) {
    MatrixHeap<const char *> m(3, 2);
    MatrixStack<const char *, 3, 2> m1{};
    const char *s = "abc";
    m[0][0] = s;
    m1[0][0] = s;
    EXPECT_EQ(m[0][0], s);
    EXPECT_EQ(m1[0][0], s);
}
TEST(MatrixTest, stringElement) {
    MatrixHeap<std::string> m(3, 2);
    MatrixStack<std::string, 3, 2> m1{};
    m[0][0] = "abc";
    m1[0][0] = "abc";
    EXPECT_EQ(m[0][0], "abc");
    EXPECT_EQ(m1[0][0], "abc");
}
TEST(MatrixTest, stringPointer) {
    MatrixHeap<std::string *> m(3, 2);
    MatrixStack<std::string *, 3, 2> m1{};
    std::string s = "abc";
    m[0][0] = &s;
    m1[0][0] = &s;

    EXPECT_EQ(m[0][0], &s);
    EXPECT_EQ(*(m[0][0]), s);
    EXPECT_EQ(m1[0][0], &s);
    EXPECT_EQ(*(m1[0][0]), s);
}
TEST(MatrixTest, size) {
    MatrixHeap<int> m(3, 2);
    EXPECT_EQ(6, m.size());

    CONSTEXPR MatrixStack<int, 3, 2> m1{};
    static_assert(m1.size() == 6);
}

}
}
