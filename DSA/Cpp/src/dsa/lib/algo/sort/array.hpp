#pragma once
namespace dsa {

/**
 * ToDo:
 * 1. copy constructor.
 * 2. move constructor.
 * 3. operator overload equal comparison(operator==)
 * 4. operator overload assignment operator(operator=)
 * 5. range for loop.
 * 6. initialize constructor with length and array elements. e.g  array(length, ary_ele1, ary_ele2...)
 */

template<typename T>
struct array {
 private:

 public:
    T *data{};
    length_t length = 0;

    array() = default;;

    array(T *data, length_t length) : data(data), length(length) {}

    T &operator[](int i) {
        return data[i];
    }
} __attribute__((aligned(16)));

}
