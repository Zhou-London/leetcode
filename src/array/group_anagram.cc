#include "deps.h"

class Solution
{
  public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        using Groups = unordered_map<string, vector<string>>;
        using ReturnType = vector<vector<string>>;

        Groups groups;

        for (const string &s : strs)
        {
            int count[26] = {};
            for (char c : s)
                ++count[c - 'a'];

            string key;
            key.reserve(52);
            for (int i = 0; i < 26; ++i)
            {
                key += '#';
                key += to_string(count[i]);
            }

            groups[key].push_back(s);
        }

        ReturnType result;
        result.reserve(groups.size());

        for (auto &[_, group] : groups)
            result.push_back(std::move(group));

        return result;
    }
};