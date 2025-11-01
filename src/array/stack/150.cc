/* Evaluate reverse polish notation */
// * Medium

#include <stack>
#include <string>
#include <vector>
using namespace std;

class Solution
{
  public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> stk;

        for (const string &token : tokens)
        {
            if (token == "+" || token == "-" || token == "*" || token == "/")
            {
                int b = stk.top();
                stk.pop();
                int a = stk.top();
                stk.pop();

                int res = 0;
                if (token == "+")
                    res = a + b;
                else if (token == "-")
                    res = a - b;
                else if (token == "*")
                    res = a * b;
                else
                    res = a / b;

                stk.push(res);
            }
            else
            {
                stk.push(stoi(token));
            }
        }

        return stk.top();
    }
};