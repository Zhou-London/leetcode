/* Longest substring without repeating characters */
// * Medium

#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
  public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char, int> last_seen;
        int left = 0, max_len = 0;

        for (int right = 0; right < (int)s.size(); ++right)
        {
            char c = s[right];
            if (last_seen.count(c))
                left = max(left, last_seen[c] + 1);

            last_seen[c] = right;
            max_len = max(max_len, right - left + 1);
        }

        return max_len;
    }
};