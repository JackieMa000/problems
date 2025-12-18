#pragma once

#include <dsa/config.h>

#include <functional>  // 确保包含基础功能头文件

// 兼容 C++17+：手动定义 binary_function（与旧版 std::binary_function 完全一致）
#if __cplusplus >= 201703L  // 检测是否为 C++17 及以上标准
namespace std {
template <class Arg1, class Arg2, class Result>
struct binary_function {
    using first_argument_type = Arg1;
    using second_argument_type = Arg2;
    using result_type = Result;
};
}
#endif

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
