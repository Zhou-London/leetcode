#include "deps.h"

#include <cstring>

class Solution
{
  public:
    int lengthOfLongestSubstring(string s)
    {
        int jump_table[128]; // Jump table for left pointer.
        memset(jump_table, 0, sizeof(jump_table));

        int max_len = 0;
        int left = 0;

        for (int right = 0; right < s.size(); ++right)
        {
            auto right_c = s[right];

            left = max(left, jump_table[right_c]);
            max_len = max(max_len, right - left + 1);

            jump_table[right_c] = right + 1;
        }

        return max_len;
    }
};
