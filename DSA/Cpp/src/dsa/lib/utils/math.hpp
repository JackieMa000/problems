#pragma once

#include <dsa/config.h>

namespace dsa {

INTERN CONSTEXPR
bool isOdd(int x) { return ((x & 1) == 1); }

INTERN CONSTEXPR UNUSED
bool isEven(int x) { return ((x & 1) == 0); }

// Using 1d array represent 2d array, which is cpu cache friendly.
// Matrix allocated on heap
template<class T>
struct MatrixHeap {
 private:
    T *ary;
    int m, n;

 public:
    MatrixHeap(int m, int n) : m(m), n(n) {
        ary = new T[m * n];
    }

    virtual ~MatrixHeap() {
        delete[] ary;
    }

    T *operator[](int i) {
        return &(ary[i * n]);
    }

    size_t size() {
        return m * n;
    }
};
// Matrix allocated on stack
template<class T, int m, int n>
struct MatrixStack {
    T _elems[m * n];

    CONSTEXPR T *operator[](size_t i) {
        return &(_elems[i * n]);
    }

    CONSTEXPR size_t size() const {
        return m * n;
    }
};

}
