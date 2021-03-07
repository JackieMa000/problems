#ifndef DSA_SRC_DSA_LIB_MATH_DS_PAREN_H_
#define DSA_SRC_DSA_LIB_MATH_DS_PAREN_H_

#include <string>

namespace dsa::lib::math::ds {

class Parentheses {
 public:
    //    LeetCode20
    static bool isValid(const std::string &s);

 private:
    static bool isValid1(const std::string &s);
    static bool isValid2(const std::string &s);
    static bool isValid21(const std::string &s);
};

}

#endif //DSA_SRC_DSA_LIB_MATH_DS_PAREN_H_
