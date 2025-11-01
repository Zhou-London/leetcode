/* Sum of two integers */
// * Medium

using namespace std;

class Solution
{
  public:
    int getSum(int a, int b)
    {
        while (b != 0)
        {
            unsigned carry = (unsigned)(a & b) << 1;
            a = a ^ b;
            b = (int)carry;
        }
        return a;
    }
};