#pragma once

#include <dsa/config.h>
#include "algorithm.hpp"

namespace dsa {

INTERN CONSTEXPR
bool isOdd(int x) { return ((x & 1) == 1); }

INTERN CONSTEXPR UNUSED
bool isEven(int x) { return ((x & 1) == 0); }

// ******************* Matrix ***************************************
template<class T>
struct MatrixHeap;

/**
 * Construct a m*n matrix with element type T
 * @tparam T
 * @tparam m
 * @tparam n
 */
template<class T, int m, int n>
struct MatrixStack;

template<class T, int m, int n>
using Matrix = MatrixStack<T, m, n>;

// Using 1d array represent 2d array, which is cpu cache friendly.
// Matrix allocated on heap
template<class T>
struct MatrixHeap {
    T *_elems{nullptr};
    int m{}, n{};

    MatrixHeap(const int m, const int n) : m(m), n(n) {
        _elems = new T[m * n];
    }

//    copy constructor
    MatrixHeap(const MatrixHeap &matrix) : MatrixHeap(matrix.m, matrix.n) {
        dsa::copy(matrix._elems, matrix._elems + matrix.size(), this->_elems);
    }

//    move constructor
    MatrixHeap(MatrixHeap &&matrix) noexcept {
        this->_elems = matrix._elems;
        this->m = matrix.m;
        this->n = matrix.n;

        matrix._elems = nullptr;
        matrix.m = 0;
        matrix.n = 0;
    }

//    Fill Constructor
    MatrixHeap(const int m, const int n, const T &value) : MatrixHeap(m, n) {
        dsa::fill(_elems, _elems + size(), value);
    }

    virtual ~MatrixHeap() {
        delete[] _elems;
    }

    T *operator[](int i) {
        return &(_elems[i * n]);
    }

    const T *operator[](int i) const {
        return &(_elems[i * n]);
    }

    size_t size() const {
        return m * n;
    }

    T *begin() noexcept {
        return _elems;
    }

    const T *begin() const noexcept {
        return _elems;
    }

    T *end() noexcept {
        return _elems + size();
    }

    const T *end() const noexcept {
        return _elems + size();
    }

};

// Matrix allocated on stack
template<class T, int m, int n>
struct MatrixStack {
    T _elems[m * n];

    MatrixStack() = default;

//    fill constructor
    explicit MatrixStack(const T &value) {
        dsa::fill(_elems, _elems + size(), value);
    }

    T *operator[](size_t i) {
        return _elems + (i * n);
    }

    CONSTEXPR const T *operator[](size_t i) const {
        return &(_elems[i * n]);
    }

    CONSTEXPR size_t size() const {
        return m * n;
    }

    T *begin() noexcept {
        return _elems;
    }

    const T *begin() const noexcept {
        return _elems;
    }

    T *end() noexcept {
        return _elems + size();
    }

    const T *end() const noexcept {
        return _elems + size();
    }

};

// ******************* Matrix ***************************************

}
