#pragma once

#include <dsa/config.h>

namespace dsa {

//Compare the equality of two objects
template<class T>
struct equal_to {
    const T &val;

    explicit equal_to(const T &val) : val(val) {}

    CONSTEXPR
    bool operator()(const T &x) const {
        return x == val;
    }
};

// Compare the size of two objects. They should have size() method.
template<class T1 = void, class T2 = void>
struct compSize : std::binary_function<T1, T2, int> {
    CONSTEXPR
    int operator()(const T1 &t, const T2 &u) const {
        return t.size() > u.size() ? 1 : t.size() == u.size() ? 0 : -1;
    }
};
template<>
struct compSize<void, void> {
    template<class T3, class T4>
    CONSTEXPR
    int operator()(T3 &&t, T4 &&u) const {
        return std::forward<T3>(t).size() == std::forward<T4>(u).size() ? 0 :
               std::forward<T3>(t).size() > std::forward<T4>(u).size() ? 1 : -1;
    }
};

template<class T = void>
struct equalSize {
    CONSTEXPR
    bool operator()(const T &x, const T &y) const
    noexcept(noexcept(compSize<T, T>()(x, y))) {
        return compSize<T, T>()(x, y) == 0;
    }
};
template<>
struct equalSize<void> {
    template<class T1, class T2>
    CONSTEXPR
    auto operator()(T1 &&t, T2 &&u) const
    noexcept(noexcept(compSize<T1, T2>()(t, u)))
    -> decltype(compSize<T1, T2>()(t, u) == 0) {
        return compSize<T1, T2>()(t, u) == 0;
    }
};

template<class T = void>
struct lessSize {
    CONSTEXPR
    bool operator()(const T &x, const T &y) const
    noexcept(noexcept(compSize<T, T>()(x, y))) {
        return compSize<T, T>()(x, y) < 0;
    }
};
template<>
struct lessSize<void> {
    template<class T1, class T2>
    CONSTEXPR
    auto operator()(T1 &&t, T2 &&u) const
    noexcept(noexcept(compSize<T1, T2>()(t, u)))
    -> decltype(compSize<T1, T2>()(t, u) < 0) {
        return compSize<T1, T2>()(t, u) < 0;
    }
};

template<class T = void>
struct greaterSize {
    CONSTEXPR
    bool operator()(const T &x, const T &y) const
    noexcept(noexcept(compSize<T, T>()(x, y))) {
        return compSize<T, T>()(x, y) > 0;
    }
};
template<>
struct greaterSize<void> {
    template<class T1, class T2>
    CONSTEXPR
    auto operator()(T1 &&t, T2 &&u) const
    noexcept(noexcept(compSize<T1, T2>()(t, u)))
    -> decltype(compSize<T1, T2>()(t, u) > 0) {
        return compSize<T1, T2>()(t, u) > 0;
    }
};

}
