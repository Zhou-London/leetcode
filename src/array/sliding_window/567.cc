/* Permutation in string */
// * Medium

#include <string>
#include <vector>
using namespace std;

class Solution
{
  public:
    bool checkInclusion(string s1, string s2)
    {
        if (s1.size() > s2.size())
            return false;

        auto count1 = vector<int>(26, 0);
        auto count2 = vector<int>(26, 0);

        for (char c : s1)
            ++count1[c - 'a'];

        int window = s1.size();

        for (int i = 0; i < s2.size(); ++i)
        {
            ++count2[s2[i] - 'a'];

            if (i >= window)
                --count2[s2[i - window] - 'a'];
            if (count1 == count2)
                return true;
        }

        return false;
    }
};