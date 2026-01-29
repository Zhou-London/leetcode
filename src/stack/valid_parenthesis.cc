#include "deps.h"

class Solution {
 public:
  bool isValid(string s) {
    stack<int> stk;

    for (auto c : s) {
      if (c == '(' || c == '{' || c == '[')
        stk.push(c);
      else {
        if (stk.empty()) return false;

        auto top = stk.top();
        if ((c == ')' && top == '(') || (c == '}' && top == '{') ||
            (c == ']' && top == '['))
          stk.pop();
        else
          return false;
      }
    }

    return stk.empty();
  }
};
