#pragma once

// Algorithms to be used on ranges of elements.

#include <dsa/config.h>
#include <dsa/type_traits.h>
#include "dsa/dsadef.h"
#include <functional>

#include "funcs.hpp"

namespace dsa {

/**
 * Remove all leading 0s from an iterator
 *
 * @tparam RandomAccessIterator
 * @param first
 * @param last
 * @return  The new first iterator.
 */
template<class RandomAccessIterator>
CONSTEXPR
RandomAccessIterator lstrip(RandomAccessIterator first, const RandomAccessIterator last) {
    while (first != last && *first == 0) ++first;
    return first;
}

/**
 * Remove all trailing 0s from an iterator
 *
 * @tparam RandomAccessIterator
 * @param first
 * @param last
 * @return  The new last iterator.
 */
template<class RandomAccessIterator>
CONSTEXPR
RandomAccessIterator rstrip(const RandomAccessIterator first, RandomAccessIterator last) {
    while (first != last && *(last - 1) == 0) --last;
    return last;
}

/**
 * Remove all leading and trailing 0s from an iterator.
 *
 * @tparam RandomAccessIterator
 * @param first
 * @param last
 * @return  A pair of new first and last iterator.
 */
template<class RandomAccessIterator>
CONSTEXPR
std::pair<RandomAccessIterator, RandomAccessIterator>
strip(RandomAccessIterator first, RandomAccessIterator last) {
    while (first != last && *first == 0) ++first;
    while (first != last && *(last - 1) == 0) --last;
    return {first, last};
}

template<class RandomAccessIterator>
CONSTEXPR
void swap(RandomAccessIterator first, pos_t i, pos_t j) {
    int tmp = first[i];
    first[i] = first[j];
    first[j] = tmp;
}
template<class T>
CONSTEXPR
typename enable_if<std::is_move_constructible<T>::value && std::is_move_assignable<T>::value>::type
swap(T &x, T &y) noexcept(is_nothrow_move_constructible_v<T> && is_nothrow_move_assignable_v<T>) {
    T tmp(std::move(x));
    x = std::move(y);
    y = std::move(tmp);
}
template<class ForwardIterator1, class ForwardIterator2>
CONSTEXPR
ForwardIterator2 swap_ranges(ForwardIterator1 first1, ForwardIterator1 last1, ForwardIterator2 first2) {
    for (; first1 != last1; ++first1, (void) ++first2) { swap(*first1, *first2); }
    return first2;
}
template<class ForwardIterator1, class ForwardIterator2>
CONSTEXPR
void
iter_swap(ForwardIterator1 a, ForwardIterator2 b)
noexcept(noexcept(swap(*std::declval<ForwardIterator1>(), *std::declval<ForwardIterator2>()))) {
    swap(*a, *b);
}

template<class T, size_t N>
CONSTEXPR
typename enable_if<std::is_swappable<T>::value>::type
swap(T (&a)[N], T (&b)[N]) noexcept(is_nothrow_swappable_v<T>) {
    dsa::swap_ranges(a, a + N, b);
}

template<typename T>
CONSTEXPR
void copy(const T *src, pos_t srcPos, T *des, pos_t desPos, length_t n) {
    for (int i = 0; i < n; ++i) {
        des[desPos + i] = src[srcPos + i];
    }
}

template<typename T>
CONSTEXPR
void copy(const std::vector<T> &src, pos_t srcPos, std::vector<T> &des, pos_t desPos, length_t n) {
    for (int i = 0; i < n; ++i) {
        des[desPos + i] = src[srcPos + i];
    }
}
template<class InputIterator, class OutputIterator>
CONSTEXPR
OutputIterator copy(InputIterator first, InputIterator last, OutputIterator result) {
    for (; first != last; ++first, (void) ++result)
        *result = *first;
    return result;
}
template<class InputIterator, class OutputIterator, class UnaryPredicate>
CONSTEXPR
OutputIterator copy_if(InputIterator first, InputIterator last, OutputIterator result, UnaryPredicate pred) {
    for (; first != last; ++first) {
        if (pred(*first)) {
            *result = *first;
            ++result;
        }
    }
    return result;
}
template<class InputIterator, class OutputIterator>
CONSTEXPR
OutputIterator copy_n(InputIterator first, size_t n, OutputIterator result) {
    return dsa::copy(first, first + n, result);
}
template<class BidirectionalIterator, class OutputIterator>
CONSTEXPR
OutputIterator copy_backward(BidirectionalIterator first, BidirectionalIterator last, OutputIterator result) {
    while (first != last)
        *--result = *--last;
    return result;
}
template<class BidirectionalIterator, class OutputIterator>
CONSTEXPR
OutputIterator reverse_copy(BidirectionalIterator first, BidirectionalIterator last, OutputIterator result) {
    for (; first != last; ++result)
        *result = *--last;
    return result;
}

template<class ForwardIterator, class T>
CONSTEXPR
void fill(ForwardIterator first, ForwardIterator last, const T &val) {
    for (; first != last; ++first) { *first = val; }
}
template<class OutputIterator, class T>
CONSTEXPR
OutputIterator fill_n(OutputIterator first, size_t n, const T &val) {
    for (; n > 0; ++first, --n) { *first = val; }
    return first;
}

template<class ForwardIterator, class T>
CONSTEXPR
void replace(ForwardIterator first, ForwardIterator last, const T &old_value, const T &new_value) {
    for (; first != last; ++first)
        if (*first == old_value)
            *first = new_value;
}
template<class ForwardIterator, class UnaryPredicate, class T>
CONSTEXPR
void replace_if(ForwardIterator first, ForwardIterator last, UnaryPredicate pred, const T &new_value) {
    for (; first != last; ++first)
        if (pred(*first)) { *first = new_value; }
}

template<class InputIterator>
CONSTEXPR
typename std::iterator_traits<InputIterator>::difference_type
distance(InputIterator first, InputIterator last, std::input_iterator_tag) {
    typename std::iterator_traits<InputIterator>::difference_type r(0);
    for (; first != last; ++first)
        ++r;
    return r;
}
template<class RandomAccessIterator>
CONSTEXPR
typename std::iterator_traits<RandomAccessIterator>::difference_type
distance(RandomAccessIterator first, RandomAccessIterator last, std::random_access_iterator_tag) {
    return last - first;
}
template<class InputIterator>
CONSTEXPR
typename std::iterator_traits<InputIterator>::difference_type
distance(InputIterator first, InputIterator last) {
    auto it = typename std::iterator_traits<InputIterator>::iterator_category();
    return dsa::distance(first, last, it);
}

template<class ForwardIterator, class T>
NODISCARD inline CONSTEXPR
ForwardIterator remove(ForwardIterator first, ForwardIterator last, const T &val) {
    first = std::find(first, last, val);
    if (first != last) {
        ForwardIterator i = first;
        while (++i != last) {
            if (*i != val) {
                *first = std::move(*i);
                ++first;
            }
        }
    }
    return first;
}

template<class ForwardIterator, class UnaryPredicate>
NODISCARD inline CONSTEXPR
ForwardIterator remove_if(ForwardIterator first, ForwardIterator last, UnaryPredicate pred) {
    typedef typename std::add_lvalue_reference<UnaryPredicate>::type ref;
    first = std::find_if<ForwardIterator, ref>(first, last, pred);
    if (first != last) {
        ForwardIterator i = first;
        while (++i != last) {
            if (!pred(*i)) {
                *first = std::move(*i);
                ++first;
            }
        }
    }
    return first;
}

template<class InputIterator, class T>
NODISCARD inline CONSTEXPR
InputIterator find(InputIterator first, InputIterator last, const T &val) {
    for (; first != last; ++first)
        if (*first == val)
            break;
    return first;
}
template<class InputIterator, class UnaryPredicate>
NODISCARD inline CONSTEXPR
InputIterator find_if(InputIterator first, InputIterator last, UnaryPredicate pred) {
    for (; first != last; ++first)
        if (pred(*first))
            break;
    return first;
}
template<class InputIterator, class UnaryPredicate>
NODISCARD inline CONSTEXPR
InputIterator find_if_not(InputIterator first, InputIterator last, UnaryPredicate pred) {
    for (; first != last; ++first)
        if (!pred(*first))
            break;
    return first;
}

template<class InputIterator, class T>
NODISCARD inline CONSTEXPR
typename std::iterator_traits<InputIterator>::difference_type
count(InputIterator first, InputIterator last, const T &val) {
    typename std::iterator_traits<InputIterator>::difference_type r(0);
    for (; first != last; ++first)
        if (*first == val)
            ++r;
    return r;
}
template<class InputIterator, class UnaryPredicate>
NODISCARD inline CONSTEXPR
typename std::iterator_traits<InputIterator>::difference_type
count_if(InputIterator first, InputIterator last, UnaryPredicate pred) {
    typename std::iterator_traits<InputIterator>::difference_type r(0);
    for (; first != last; ++first)
        if (pred(*first))
            ++r;
    return r;
}

template<class BidirectionalIterator>
void reverse(BidirectionalIterator first, BidirectionalIterator last, std::bidirectional_iterator_tag) {
    while (first != last) {
        if (first == --last)
            break;
        dsa::iter_swap(first, last);
        ++first;
    }
}
template<class RandomAccessIterator>
void reverse(RandomAccessIterator first, RandomAccessIterator last, std::random_access_iterator_tag) {
    if (first != last)
        for (; first < --last; ++first)
            dsa::iter_swap(first, last);
}
template<class BidirectionalIterator>
void reverse(BidirectionalIterator first, BidirectionalIterator last) {
    auto it = typename std::iterator_traits<BidirectionalIterator>::iterator_category();
    dsa::reverse(first, last, it);
}

// min

template<class T, class Compare>
NODISCARD inline CONSTEXPR
const T &min(const T &a, const T &b, Compare comp) {
    return comp(b, a) ? b : a;
}
template<class T>
NODISCARD inline CONSTEXPR
const T &min(const T &a, const T &b) {
    return DSA::min(a, b, std::less<T>());
}

template<class ForwardIterator, class Compare>
NODISCARD inline CONSTEXPR
ForwardIterator min_element(ForwardIterator first, ForwardIterator last, Compare comp) {
//    static_assert(std::__is_cpp17_forward_iterator<ForwardIterator>::value,
//                  "std::min_element requires a ForwardIterator");
    if (first != last) {
        ForwardIterator i = first;
        while (++i != last)
            if (comp(*i, *first))
                first = i;
    }
    return first;
}

template<class ForwardIterator>
NODISCARD inline CONSTEXPR
ForwardIterator min_element(ForwardIterator first, ForwardIterator last) {
    typedef typename std::iterator_traits<ForwardIterator>::value_type v;
    return DSA::min_element(first, last, std::less<v>());
}

template<class ForwardIterator>
NODISCARD inline CONSTEXPR
ForwardIterator minSizeElement(ForwardIterator first, ForwardIterator last) {
    typedef typename std::iterator_traits<ForwardIterator>::value_type v;
    return DSA::min_element(first, last, DSA::lessSize<v>());
}

template<class T, class Compare>
NODISCARD inline CONSTEXPR
T min(std::initializer_list<T> t, Compare comp) {
    return *DSA::min_element(t.begin(), t.end(), comp);
}

template<class T>
NODISCARD inline CONSTEXPR
T min(std::initializer_list<T> t) {
    return *DSA::min_element(t.begin(), t.end(), std::less<T>());
}

// max_element

template<class ForwardIterator, class Compare>
NODISCARD inline CONSTEXPR
ForwardIterator max_element(ForwardIterator first, ForwardIterator last, Compare comp) {
//    static_assert(std::__is_cpp17_forward_iterator<ForwardIterator>::value,
//                  "std::max_element requires a ForwardIterator");
    if (first != last) {
        ForwardIterator i = first;
        while (++i != last)
            if (comp(*first, *i))
                first = i;
    }
    return first;
}

template<class ForwardIterator>
NODISCARD inline CONSTEXPR
ForwardIterator max_element(ForwardIterator first, ForwardIterator last) {
    typedef typename std::iterator_traits<ForwardIterator>::value_type v;
    return DSA::max_element(first, last, std::less<v>());
}

template<class ForwardIterator>
NODISCARD inline CONSTEXPR
ForwardIterator maxSizeElement(ForwardIterator first, ForwardIterator last) {
    typedef typename std::iterator_traits<ForwardIterator>::value_type v;
    return DSA::max_element(first, last, DSA::lessSize<v>());
}

// max

template<class T, class Compare>
NODISCARD inline CONSTEXPR
const T &max(const T &a, const T &b, Compare comp) {
    return comp(a, b) ? b : a;
}

template<class T>
NODISCARD inline CONSTEXPR
const T &max(const T &a, const T &b) {
    return DSA::max(a, b, std::less<T>());
}

template<class T, class Compare>
NODISCARD inline CONSTEXPR
T max(std::initializer_list<T> t, Compare comp) {
    return *DSA::max_element(t.begin(), t.end(), comp);
}

template<class T>
NODISCARD inline CONSTEXPR
T max(std::initializer_list<T> t) {
    return *DSA::max_element(t.begin(), t.end(), std::less<T>());
}

// minmax

template<class T, class Compare>
NODISCARD inline CONSTEXPR
std::pair<const T &, const T &> minmax(const T &a, const T &b, Compare comp) {
    return comp(b, a) ? std::pair<const T &, const T &>(b, a) :
           std::pair<const T &, const T &>(a, b);
}

template<class T>
NODISCARD inline CONSTEXPR
std::pair<const T &, const T &> minmax(const T &a, const T &b) {
    return DSA::minmax(a, b, std::less<T>());
}

template<class T, class Compare>
NODISCARD inline CONSTEXPR
std::pair<T, T> minmax(std::initializer_list<T> t, Compare comp) {
    typedef typename std::initializer_list<T>::const_iterator Iter;
    Iter first = t.begin();
    Iter last = t.end();
    std::pair<T, T> result(*first, *first);

    ++first;
    if (t.size() % 2 == 0) {
        if (comp(*first, result.first))
            result.first = *first;
        else
            result.second = *first;
        ++first;
    }

    while (first != last) {
        T prev = *first++;
        if (comp(*first, prev)) {
            if (comp(*first, result.first)) result.first = *first;
            if (!comp(prev, result.second)) result.second = prev;
        } else {
            if (comp(prev, result.first)) result.first = prev;
            if (!comp(*first, result.second)) result.second = *first;
        }

        first++;
    }
    return result;
}

template<class T>
NODISCARD inline CONSTEXPR
std::pair<T, T> minmax(std::initializer_list<T> t) {
    return DSA::minmax(t, std::less<T>());
}

// minmax_element

template<class ForwardIterator, class Compare>
NODISCARD CONSTEXPR
std::pair<ForwardIterator, ForwardIterator> minmax_element(ForwardIterator first,
                                                           ForwardIterator last,
                                                           Compare comp) {
//    static_assert(std::__is_cpp17_forward_iterator<ForwardIterator>::value,
//                  "std::minmax_element requires a ForwardIterator");
    std::pair<ForwardIterator, ForwardIterator> result(first, first);
    if (first != last) {
        if (++first != last) {
            if (comp(*first, *result.first))
                result.first = first;
            else
                result.second = first;
            while (++first != last) {
                ForwardIterator i = first;
                if (++first == last) {
                    if (comp(*i, *result.first))
                        result.first = i;
                    else if (!comp(*i, *result.second))
                        result.second = i;
                    break;
                } else {
                    if (comp(*first, *i)) {
                        if (comp(*first, *result.first))
                            result.first = first;
                        if (!comp(*i, *result.second))
                            result.second = i;
                    } else {
                        if (comp(*i, *result.first))
                            result.first = i;
                        if (!comp(*first, *result.second))
                            result.second = first;
                    }
                }
            }
        }
    }
    return result;
}

template<class ForwardIterator>
NODISCARD inline CONSTEXPR
std::pair<ForwardIterator, ForwardIterator> minmax_element(ForwardIterator first, ForwardIterator last) {
    typedef typename std::iterator_traits<ForwardIterator>::value_type v;
    return DSA::minmax_element(first, last, std::less<v>());
}


// for_each

template<class InputIterator, class Function>
CONSTEXPR
Function for_each(InputIterator first, InputIterator last, Function f) {
    for (; first != last; ++first)
        f(*first);
    return f;
}

// for_each_n

inline CONSTEXPR
int __convert_to_integral(int __val) { return __val; }

template<class InputIterator, class Size, class Function>
CONSTEXPR
InputIterator for_each_n(InputIterator first, Size orig_n, Function f) {
    typedef decltype(__convert_to_integral(orig_n)) IntegralSize;
    IntegralSize n = orig_n;
    while (n > 0) {
        f(*first);
        ++first;
        --n;
    }
    return first;
}

// all_of

template<class InputIterator, class Predicate>
NODISCARD inline HIDDEN CONSTEXPR
bool all_of(InputIterator first, InputIterator last, Predicate pred) {
    for (; first != last; ++first)
        if (!pred(*first))
            return false;
    return true;
}

// any_of

template<class InputIterator, class Predicate>
NODISCARD inline HIDDEN CONSTEXPR
bool any_of(InputIterator first, InputIterator last, Predicate pred) {
    for (; first != last; ++first)
        if (pred(*first))
            return true;
    return false;
}

// none_of

template<class InputIterator, class Predicate>
NODISCARD inline HIDDEN CONSTEXPR
bool none_of(InputIterator first, InputIterator last, Predicate pred) {
    for (; first != last; ++first)
        if (pred(*first))
            return false;
    return true;
}

// equal

template<class InputIterator1, class InputIterator2, class BinaryPredicate>
NODISCARD inline CONSTEXPR
bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, BinaryPredicate pred) {
    for (; first1 != last1; ++first1, (void) ++first2)
        if (!pred(*first1, *first2))
            return false;
    return true;
}

template<class InputIterator1, class InputIterator2>
NODISCARD inline CONSTEXPR
bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2) {
    typedef typename std::iterator_traits<InputIterator1>::value_type v1;
    typedef typename std::iterator_traits<InputIterator2>::value_type v2;
//    return DSA::equal(first1, last1, first2, std::__equal_to<v1, v2>());
    return DSA::equal(first1, last1, first2, std::equal_to<void>());
}

template<class BinaryPredicate, class InputIterator1, class InputIterator2>
inline CONSTEXPR
bool equal(InputIterator1 first1, InputIterator1 last1,
           InputIterator2 first2, InputIterator2 last2, BinaryPredicate pred,
           std::input_iterator_tag, std::input_iterator_tag) {
    for (; first1 != last1 && first2 != last2; ++first1, (void) ++first2)
        if (!pred(*first1, *first2))
            return false;
    return first1 == last1 && first2 == last2;
}

template<class BinaryPredicate, class RandomAccessIterator1, class RandomAccessIterator2>
inline CONSTEXPR
bool equal(RandomAccessIterator1 first1, RandomAccessIterator1 last1,
           RandomAccessIterator2 first2, RandomAccessIterator2 last2, BinaryPredicate pred,
           std::random_access_iterator_tag, std::random_access_iterator_tag) {
    if (DSA::distance(first1, last1) != DSA::distance(first2, last2))
        return false;
    typedef typename std::add_lvalue_reference<BinaryPredicate>::type ref;
    return DSA::equal<RandomAccessIterator1, RandomAccessIterator2, ref>(first1, last1, first2, pred);
}

template<class InputIterator1, class InputIterator2, class BinaryPredicate>
NODISCARD inline CONSTEXPR
bool equal(InputIterator1 first1, InputIterator1 last1,
           InputIterator2 first2, InputIterator2 last2, BinaryPredicate pred) {
    typedef typename std::add_lvalue_reference<BinaryPredicate>::type ref;
    auto it1 = typename std::iterator_traits<InputIterator1>::iterator_category();
    auto it2 = typename std::iterator_traits<InputIterator2>::iterator_category();
    return DSA::equal<ref>(first1, last1, first2, last2, pred, it1, it2);
}

template<class InputIterator1, class InputIterator2>
NODISCARD inline CONSTEXPR
bool equal(InputIterator1 first1, InputIterator1 last1,
           InputIterator2 first2, InputIterator2 last2) {
    typedef typename std::iterator_traits<InputIterator1>::value_type v1;
    typedef typename std::iterator_traits<InputIterator2>::value_type v2;
    auto it1 = typename std::iterator_traits<InputIterator1>::iterator_category();
    auto it2 = typename std::iterator_traits<InputIterator2>::iterator_category();
//    return DSA::equal(first1, last1, first2, last2, std::__equal_to<v1, v2>(), it1, it2);
    return DSA::equal(first1, last1, first2, last2, std::equal_to<void>(), it1, it2);
}

}
