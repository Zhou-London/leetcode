#include "deps.h"

class Solution
{
  public:
    // 5#hello5#world
    string encode(vector<string> &strs)
    {
        string result;
        for (const string &s : strs)
            result += to_string(s.size()) + "#" + s;

        return result;
    }

    vector<string> decode(string s)
    {
        vector<string> result;
        int len_pos = 0;

        while (len_pos < s.size())
        {
            int sharp_pos = len_pos;
            while (s[sharp_pos] != '#')
                ++sharp_pos;

            int len = stoi(s.substr(len_pos, sharp_pos - len_pos));

            auto str = s.substr(sharp_pos + 1, len);
            result.push_back(str);

            len_pos = sharp_pos + len + 1;
        }

        return result;
    }
};
