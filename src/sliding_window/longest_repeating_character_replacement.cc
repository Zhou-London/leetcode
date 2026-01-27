#include "deps.h"

class Solution
{
  public:
    int characterReplacement(string s, int k)
    {
        size_t size = s.size();
        int freq[26] = {0};
        int left = 0, maxFreq = 0, result = 0;

        for (int right = 0; right < size; ++right)
        {
            int idx = s[right] - 'A';
            ++freq[idx];
            maxFreq = max(maxFreq, freq[idx]);

            int window_len = right - left + 1;
            if (window_len - maxFreq > k)
            {
                --freq[s[left] - 'A'];
                ++left;
            }

            result = max(result, right - left + 1);
        }

        return result;
    }
};
