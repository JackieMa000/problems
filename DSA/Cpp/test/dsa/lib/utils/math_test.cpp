#include "dsa/lib/utils/math.hpp"
#include <gtest/gtest.h>

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
TEST(MatrixStackTest, ConstructorWithInitialValue) {
    CONSTEXPR const int m = 2, n = 2;

    MatrixStack<int, m, n> m1(1);
    const MatrixStack<int, m, n> m3(1);

    int expected[m][n] = {{1, 1}, {1, 1}};

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            EXPECT_EQ(expected[i][j], m1[i][j]);
            EXPECT_EQ(expected[i][j], m3[i][j]);
        }
    }
}
TEST(MatrixHeapTest, ConstructorWithInitialValue) {
    const int m = 2, n = 2;

    MatrixHeap<int> m1(m, n, 1);
    const MatrixHeap<int> m2(m, n, 1);

    int expected[m][n] = {{1, 1}, {1, 1}};

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            EXPECT_EQ(expected[i][j], m1[i][j]);
            EXPECT_EQ(expected[i][j], m2[i][j]);
        }
    }
}
TEST(MatrixTest, DefaultMatrix) {
    const int m = 2, n = 2;
    Matrix<int, m, n> m1{};
    const Matrix<int, m, n> m2(1);
}
TEST(MatrixStackTest, CopyConstructor) {
    const int m = 1, n = 1;

    MatrixStack<int, m, n> m1(1);
    MatrixStack<int, m, n> m2(m1);

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            EXPECT_EQ(m1[i][j], m2[i][j]);
            EXPECT_NE(&m1[i][j], &m2[i][j]);
        }
    }
}
TEST(MatrixHeapTest, CopyConstructor) {
    const int m = 1, n = 1;

    MatrixHeap<int> m1(m, n, 1);
    MatrixHeap<int> m2(m1);

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            EXPECT_EQ(m1[i][j], m2[i][j]);
            EXPECT_NE(&m1[i][j], &m2[i][j]);
        }
    }
}
TEST(MatrixHeapTest, MoveConstructor) {
    const int m = 1, n = 1;

    MatrixHeap<int> m1(m, n, 1);
    MatrixHeap<int> m2(std::move(m1));

    EXPECT_EQ(nullptr, m1.begin());
    EXPECT_EQ(0, m1.size());

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            EXPECT_EQ(1, m2[i][j]);
        }
    }
}

}
}
