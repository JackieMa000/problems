#ifndef DSA_SRC_DSA_LIB_MATH_DS_HPP_
#define DSA_SRC_DSA_LIB_MATH_DS_HPP_

#include <string>
#include <stack>
#include <map>

class Parentheses {
    bool isValid(std::string s) {
        std::stack<char> temp;
        std::map<char, char> m = {{']', '['}, {')', '('}, {'}', '{'}};
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '[' || s[i] == '(' || s[i] == '{')
                temp.push(s[i]);
            else if (s[i] == ']' || s[i] == ')' || s[i] == '}') {
                if (temp.empty() || temp.top() != m[s[i]]) return false;
                else temp.pop();
            }
        }
        return temp.empty();
    }
};

#endif //DSA_SRC_DSA_LIB_MATH_DS_HPP_
