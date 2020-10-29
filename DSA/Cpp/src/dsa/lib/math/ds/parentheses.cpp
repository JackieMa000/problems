#include <stack>
#include <map>
#include "parentheses.h"

namespace dsa::lib::math::ds {

bool Parentheses::isValid(std::string s) {
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

}
