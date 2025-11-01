/* Generate Parentheses */
// * Medium

#include <string>
#include <vector>
using namespace std;

class Solution
{
  public:
    vector<string> res;

    void backtrack(string &cur, int open, int close, int n)
    {
        if ((int)cur.size() == 2 * n)
        {
            res.push_back(cur);
            return;
        }

        if (open < n)
        {
            cur.push_back('(');
            backtrack(cur, open + 1, close, n);
            cur.pop_back();
        }

        if (close < open)
        {
            cur.push_back(')');
            backtrack(cur, open, close + 1, n);
            cur.pop_back();
        }
    }

    vector<string> generateParenthesis(int n)
    {
        string cur;
        cur.reserve(2 * n);
        backtrack(cur, 0, 0, n);
        return res;
    }
};