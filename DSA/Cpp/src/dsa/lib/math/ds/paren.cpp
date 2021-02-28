#include <stack>
#include <map>
#include "paren.h"

namespace dsa::lib::math::ds {

bool Parentheses::isValid(const std::string &s) {
    return isValid1(s);
}
//Stack and Hash Map
bool Parentheses::isValid1(const std::string &s) {
    std::stack<char> stack;
    std::map<char, char> parenMap = {{']', '['}, {')', '('}, {'}', '{'}};
    for (const char &c : s) {
//        Opening bracket. Did not find the key
        if (parenMap.find(c) == parenMap.end()) stack.push(c);
//        Closing bracket
        else if (stack.empty() || stack.top() != parenMap[c]) return false;
        else stack.pop();
    }
    return stack.empty();
}
//Stack
bool Parentheses::isValid2(const std::string &s) {
    std::stack<char> stack;
    for (const auto &c: s) {
//        Opening bracket
        if (c == '(') stack.push(')');
        else if (c == '[') stack.push(']');
        else if (c == '{') stack.push('}');
//        Closing bracket
        else if (stack.empty() || stack.top() != c) return false;
        else stack.pop();
    }
    return stack.empty();
}
bool Parentheses::isValid21(const std::string &s) {
    std::stack<char> stack;
    for (const auto &c : s) {
        switch (c) {
            case '(':stack.push(')');
                break;
            case '[': stack.push(']');
                break;
            case '{': stack.push('}');
                break;
            default:
                if (stack.empty() || stack.top() != c) return false;
                else stack.pop();
        }
    }
    return stack.empty();
}

}
