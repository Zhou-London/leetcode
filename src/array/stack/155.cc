/* Min stack */
// * Medium

#include <stack>
using namespace std;

class MinStack
{
  private:
    stack<int> stk;
    stack<int> minStk;

  public:
    MinStack()
    {
    }

    void push(int val)
    {
        stk.push(val);
        if (minStk.empty() || val <= minStk.top())
            minStk.push(val);
        else
            minStk.push(minStk.top());
    }

    void pop()
    {
        if (!stk.empty())
        {
            stk.pop();
            minStk.pop();
        }
    }

    int top()
    {
        return stk.top();
    }

    int getMin()
    {
        return minStk.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */