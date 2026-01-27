#include "deps.h"

class Solution
{
  public:
    string minWindow(string s, string t)
    {
        if (s.size() < t.size())
        {
            return "";
        }

        int need[128] = {0}, have[128] = {0};
        int uniqueChars = 0;
        for (auto c : t)
        {
            if (need[c] == 0)
            {
                ++uniqueChars;
            }
            ++need[c];
        }

        int formed = 0, left = 0, minLen = INT_MAX, minStart = 0;

        for (int right = 0; right < s.size(); ++right)
        {

            auto c = s[right];
            ++have[c];

            if (need[c] > 0 && have[c] == need[c])
            {
                ++formed;
            }

            while (formed == uniqueChars)
            {
                int windowLen = right - left + 1;
                if (windowLen < minLen)
                {
                    minLen = windowLen;
                    minStart = left;
                }

                char leftChar = s[left];
                --have[leftChar];

                if (need[leftChar] > 0 && have[leftChar] < need[leftChar])
                {
                    --formed;
                }

                ++left;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(minStart, minLen);
    }
};