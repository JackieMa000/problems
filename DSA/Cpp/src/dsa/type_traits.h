#ifndef DSA_SRC_DSA_TYPE_TRAITS_H_
#define DSA_SRC_DSA_TYPE_TRAITS_H_

#include <type_traits>

namespace dsa {

template<class T>
constexpr bool is_nothrow_move_constructible_v = std::is_nothrow_move_constructible<T>::value;
template<class T>
constexpr bool is_nothrow_move_assignable_v = std::is_nothrow_move_constructible<T>::value;
template<class T>
constexpr bool is_nothrow_swappable_v = std::is_nothrow_swappable<T>::value;

template<bool, class T = void>
struct TEMPLATE_VIS enable_if {};

template<class T>
struct TEMPLATE_VIS enable_if<true, T> { typedef T type; };

template<bool cond, class T = void>
using enable_if_t = typename enable_if<cond, T>::type;

}
#endif //DSA_SRC_DSA_TYPE_TRAITS_H_
